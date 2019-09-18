#ifndef LISTENER_H_
#define LISTENER_H_

#include "argument.h"
#include <list>

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
	float economic_acep;
	float ecologic_acep;
	float social_acep;
	// GRADE OF GRADING THE DIFFERENT SUBJECTS
	float economic_value;
	float ecologic_value;
	float social_value;

public:
	listener();
	~listener();

	// FUNCTION OF ACCEPTANCE OF NEW ARGUMENTS, RETURNING A BOOLEAN (TRUE = ACCEPTED, FALSE = REJECTED)
	bool Add_argument(argument);

};

#endif