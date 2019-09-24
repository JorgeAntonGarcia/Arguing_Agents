#ifndef LISTENER_CPP_
#define LISTENER_CPP_

#include "listener.h"


listener::~listener() {}

float listener::get_random() { // Returns a random float in given range
	static std::random_device e;
	static std::uniform_real_distribution<> dis(0, 100); // range [0,100]
	return dis(e);

	// Source: https://stackoverflow.com/questions/686353/random-float-number-generation
}

bool listener::Add_argument(argument Arg) {
	bool accepted = false;
	float acceptance_rate = 0;
	// CREATE THE FUNCTION OF CHECKING THE ARGUMENT
	switch (Arg.Get_nature()) {
		case ECONOMIC:
			acceptance_rate = this->economic_accep;
			break;
		case ECOLOGIC:
			acceptance_rate = this->ecologic_accep;
			break;
		case SOCIAL:
			acceptance_rate = this->social_accep;
			break;
		default:
			perror("Critical Error - Listener.cpp: Nature not in switch");
			exit(1);
			break;
	}
	accepted = this->Evaluate_argument(Arg, acceptance_rate);

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

#endif