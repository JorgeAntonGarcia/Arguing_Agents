#ifndef LISTENER_CPP_
#define LISTENER_CPP_

#include "listener.h"

listener::listener(int type) {
	number_arg_accepted = 0; number_arg_rejected = 0;
	switch (type) {
	case 1:
		grade_of_expertise = 3.6; emotional_state = 1.0f; is_pro = true; number_arg_accepted = 0; number_arg_rejected = 0;  break;
	case 2:
		grade_of_expertise = (float)(0.3 * 7.0); emotional_state = 1.0f; is_pro = true; number_arg_accepted = 0; number_arg_rejected = 0;; break;
	case 3:
		grade_of_expertise = 0.0f; emotional_state = 1.0f; is_pro = true; number_arg_accepted = 0; number_arg_rejected = 0; break;
	default:
		grade_of_expertise = 0.0f; emotional_state = 1.0f; is_pro = true; number_arg_accepted = 0; number_arg_rejected = 0; break;
	}
}

listener::~listener() {

}

float listener::get_random() { // Returns a random float in given range
	static std::random_device e;
	static std::uniform_real_distribution<> dis(0, 100); // range [0,100]
	return (float)dis(e);

	// Source: https://stackoverflow.com/questions/686353/random-float-number-generation
}

bool listener::Add_argument(argument Arg) {
	bool accepted = false;
	float * min_involvement = &grade_of_expertise;   // We set up the minimum value needed to accept an argument
	float * emotion = &emotional_state;

	float min_AR_ratio = emotional_state - AR_BOUNDARY;	 // We set up the minimum value of AR ratio to accept an argument
	float max_AR_ratio = emotional_state + AR_BOUNDARY;	 // We set up the maximum value of AR ratio to accept an argument

	// Check whether the listener has heard the argument before
	if (Check_KB(Arg.Get_ID())) {
		return accepted;
	}

	accepted = this->Evaluate_argument(Arg, *min_involvement, min_AR_ratio, max_AR_ratio);
	this->Update_opinion(Arg, accepted, min_involvement, emotion);
	
	return accepted;
}

bool listener::Evaluate_argument(argument Arg, float min_inv, float min_ar, float max_ar) {
	bool accepted = false;
	
	if (Arg.Get_AR_ratio() > min_ar) {
		if (Arg.Get_AR_ratio() < max_ar) {
			if (Arg.Get_involvement() > min_inv) {
				accepted = true;
			}
		}
	}

	return accepted;
}

void listener::Update_opinion(argument Arg, bool accepted, float * expertise, float * emotion) {
	float GAUSS_MAXIMUM = 4.0f;
	float GAUSS_SHAPE_EXPERTISE = (INVOLVEMENT_MAX - INVOLVEMENT_MIN) / 2;
	float GAUSS_SHAPE_EMOTION = (AR_RATIO_MAX - AR_RATIO_MIN) / 2;

		if (accepted == true) {
			this->accepted_arguments.push_back(Arg);
			this->number_arg_accepted++;

			// == EXPERTISE CHANGE ==
			// Gaussian function to model the grade of expertise of the subject depending on the strength of the argument accepted
			float math_expertise = expf(-(powf((INVOLVEMENT_MAX) - Arg.Get_involvement() + *expertise, 2.0) / (2 * powf(GAUSS_SHAPE_EXPERTISE, 2.0))));
			// Grade of expertise influences the amount of change in expertise. 
			// Limited by the involvement of the argument.
			float learning_potential = (Arg.Get_involvement() - *expertise) / Arg.Get_involvement();
			
			if (Arg.Get_pro() == is_pro) {	// Arguments aligned with the subject position
				if ((*expertise += GAUSS_MAXIMUM * math_expertise * learning_potential ) < INVOLVEMENT_MAX) {}
				else { *expertise = INVOLVEMENT_MAX; }
			} 
			else {							// Arguments that face the subject knowledge
				if ((*expertise -= GAUSS_MAXIMUM * math_expertise * learning_potential) > INVOLVEMENT_MIN) {}
				else { *expertise = -(*expertise - GAUSS_MAXIMUM * math_expertise * learning_potential); is_pro = !is_pro; }
			}	

			// == EMOTIONAL CHANGE ==
			// Gaussian function to model the emotional state of the subject depending on the strength of the argument accepted
			float math_emotion = 0.0f;

			if (Arg.Get_AR_ratio() < emotional_state) {	// Arguments more emotional than the state of the subject
				math_emotion = expf(-(powf((emotional_state - Arg.Get_AR_ratio()), 2.0) / (2 * powf(GAUSS_SHAPE_EMOTION, 2.0))));
				math_emotion = 1 - math_emotion;
				if ((*emotion -= GAUSS_MAXIMUM * math_emotion) > AR_RATIO_MIN) {}
				else { *emotion = AR_RATIO_MIN; }
			} 
			else {										// Arguments with more reason than the state of the subject
				math_emotion = expf(-(powf((Arg.Get_AR_ratio() - emotional_state), 2.0) / (2 * powf(GAUSS_SHAPE_EMOTION, 2.0))));
				math_emotion = 1 - math_emotion;
				if ((*emotion += GAUSS_MAXIMUM * math_emotion) < AR_RATIO_MAX) {}
				else { *emotion = AR_RATIO_MAX; }
			}
		}

		else {
			this->rejected_arguments.push_back(Arg);
			this->number_arg_rejected++;
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