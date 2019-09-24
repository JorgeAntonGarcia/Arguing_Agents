#ifndef LISTENER_H_
#define LISTENER_H_

#include "argument.h"
#include <list>
#include <random>

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
	listener();
	~listener();

	// FUNCTION OF ACCEPTANCE OF NEW ARGUMENTS, RETURNS A BOOLEAN (TRUE = ACCEPTED, FALSE = REJECTED)
	bool Add_argument(argument);
	
};

#endif