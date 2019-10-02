#ifndef LISTENER_CPP_
#define LISTENER_CPP_

#include "listener.h"

listener::listener(int type) {
	switch (type) {
	case 1:
		economic_opinion = 50.0f; ecologic_opinion = 50.0f; social_opinion = 50.0f;
		economic_value = 1.2f; ecologic_value = 0.6f; social_value = 0.9f; break;
	case 2:
		economic_opinion = 50.0f; ecologic_opinion = 50.0f; social_opinion = 50.0f;
		economic_value = 0.6f; ecologic_value = 1.2f; social_value = 0.9f; break;
	case 3:
		economic_opinion = 50.0f; ecologic_opinion = 50.0f; social_opinion = 50.0f;
		economic_value = 1.0f; ecologic_value = 1.0f; social_value = 1.2f; break;
	default:
		economic_opinion = 50.0f; ecologic_opinion = 50.0f; social_opinion = 50.0f;
		economic_value = 1.0f; ecologic_value = 1.0f; social_value = 1.0f; break;
	}
}

listener::~listener() {

}

float listener::get_random() { // Returns a random float in given range
	static std::random_device e;
	static std::uniform_real_distribution<> dis(0, 100); // range [0,100]
	return dis(e);

	// Source: https://stackoverflow.com/questions/686353/random-float-number-generation
}

bool listener::Add_argument(argument Arg) {
	bool accepted = false;
	float * acceptance_rate = NULL;
	// Check whether the listener has heard the argument before
	if (Check_KB(Arg.Get_ID())) {
		return accepted;
	}
	// Use nature to get the proper opinion score
	switch (Arg.Get_nature()) {
		case ECONOMIC:
			acceptance_rate = &(this->economic_opinion);
			break;
		case ECOLOGIC:
			acceptance_rate = &(this->ecologic_opinion);
			break;
		case SOCIAL:
			acceptance_rate = &(this->social_opinion);
			break;
		default:
			perror("Critical Error - Listener.cpp: Nature not in switch");
			exit(1);
			break;
	}

	//  If you give a Pro you don't need to apply any transformation, but giving a Con makes neccesary to invert the acceptance rate
	if  (Arg.Get_pro() == true)	{ accepted = this->Evaluate_argument(Arg, *acceptance_rate); }
	else						{ accepted = this->Evaluate_argument(Arg, 100 - *acceptance_rate); }

	this->Update_opinion(Arg, accepted, acceptance_rate);
	
	return accepted;
}

bool listener::Evaluate_argument(argument Arg, float acceptance_rate) {
	bool accepted = false;
	float adjusted_validity = (Arg.Get_validity() - 50) / 100;
	float random = get_random();

	acceptance_rate = (acceptance_rate * (1 + adjusted_validity) > 100) ? 100 : (acceptance_rate * (1+ adjusted_validity)); // acceptance_rate caps at 100%
	
	accepted = (acceptance_rate >= random) ? true : false;

	return accepted;
}

void listener::Update_opinion(argument Arg, bool accepted, float * parameter) {
	float GAUSS_MAXIMUM = 4.0f;
	float GAUSS_SHAPE = 10.0f;

		if (accepted == true) {
			this->accepted_arguments.push_back(Arg);
			// Gaussian function to model the opinion change
			float math = expf(-(powf((*parameter - 50.0f), 2.0) / (2 * powf(GAUSS_SHAPE, 2.0))));
			if (Arg.Get_pro() == true) { *parameter += GAUSS_MAXIMUM * math;}
			else { *parameter -= GAUSS_MAXIMUM * math; }
		}

		else {
			this->rejected_arguments.push_back(Arg);
			// To think about it
		}

}

bool listener::Check_KB(int ID) {
	//Returns whether the listener has seen the argument before
	bool is_known = false;
	//Check accepted arguments
	for (auto i : accepted_arguments) {
		if (ID == i.Get_ID()) {
			is_known = true;
			break;
		}
	}
	//If the argument hasn't been encountered in the accepted arguments:
	if (!is_known) {
		// Check the rejected_arguments
		for (auto i : rejected_arguments) {
			if (ID == i.Get_ID()) {
				is_known = true;
				break;
			}
		}
	}

	return is_known;
}

void listener::Add_set_arguments(list<argument> data_set) {
	std::list<argument>::iterator it;
	for (it = data_set.begin(); it != data_set.end(); it++) {
		this->Add_argument(*it);
	}
}

#endif