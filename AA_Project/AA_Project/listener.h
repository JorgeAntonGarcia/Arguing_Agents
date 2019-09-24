#ifndef LISTENER_H_
#define LISTENER_H_

#include "argument.h"
#include <list>
#include <random>
#include <algorithm>

using namespace std;

class listener {
private:
	// ARGUMENTS THAT A LISTENER HAS
	list <argument> argument_list;
	// PARAMETERS FOR THE SCORE AND RESULTS
	float economic_opinion;
	float ecologic_opinion;
	float social_opinion;
	// GRADE OF TOLERANCE TO ACCEPT NEW ARGUMENTS
	float economic_accep;
	float ecologic_accep;
	float social_accep;
	// GRADE OF GRADING THE DIFFERENT SUBJECTS
	float economic_value;
	float ecologic_value;
	float social_value;
	// functions
	bool Evaluate_argument(argument, float);
	float get_random();

public:
	listener() {  
		economic_opinion = 0.0f; ecologic_opinion = 0.0f; social_opinion = 0.0f; 
		economic_accep = 50.0f; ecologic_accep = 50.0f; social_accep = 50.0f;
		economic_value = 1.0f; ecologic_value = 1.0f; social_value = 1.0f;
	};
	listener(float ECONOMIC_OP = 0.0f, float ECOLOGIC_OP = 0.0f, float SOCIAL_OP = 0.0f, 
		float ECONOMIC_AC = 50.0f, float ECOLOGIC_AC = 50.0f, float SOCIAL_AC = 50.0f,
		float ECONOMIC_VAL = 1.0f, float ECOLOGIC_VAL = 1.0f, float SOCIAL_VAL = 1.0f) {
		economic_opinion = ECONOMIC_OP; ecologic_opinion = ECOLOGIC_OP; social_opinion = SOCIAL_OP;
		economic_accep = ECONOMIC_AC; ecologic_accep = ECOLOGIC_AC; social_accep = SOCIAL_AC;
		economic_value = ECONOMIC_VAL; ecologic_value = ECOLOGIC_VAL; social_value = SOCIAL_VAL;
	}
	~listener();

	// FUNCTION OF ACCEPTANCE OF NEW ARGUMENTS, RETURNS A BOOLEAN (TRUE = ACCEPTED, FALSE = REJECTED)
	bool Add_argument(argument);
	
};

#endif