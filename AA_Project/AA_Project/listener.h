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
	list <argument> accepted_arguments;
	list <argument> rejected_arguments;
	// OPINION THE LISTENER HAS RELATED TO EACH TOPIC
	float economic_opinion;
	float ecologic_opinion;
	float social_opinion;
	// GRADE OF GRADING THE DIFFERENT SUBJECTS
	float economic_value;
	float ecologic_value;
	float social_value;
	// functions
	bool Evaluate_argument(argument, float);
	void Update_opinion(argument, bool, float *);
	float get_random();
	bool Check_KB(int);

public:
	listener() {  
		economic_opinion = 50.0f; ecologic_opinion = 50.0f; social_opinion = 50.0f; 
		economic_value = 1.0f; ecologic_value = 1.0f; social_value = 1.0f;
	}
	listener(float ECONOMIC_OP, float ECOLOGIC_OP, float SOCIAL_OP, 
		float ECONOMIC_VAL = 1.0f, float ECOLOGIC_VAL = 1.0f, float SOCIAL_VAL = 1.0f) {
		economic_opinion = ECONOMIC_OP; ecologic_opinion = ECOLOGIC_OP; social_opinion = SOCIAL_OP;
		economic_value = ECONOMIC_VAL; ecologic_value = ECOLOGIC_VAL; social_value = SOCIAL_VAL;
	}
	listener(int);
	~listener();

	// FUNCTION OF ACCEPTANCE OF NEW ARGUMENTS, RETURNS A BOOLEAN (TRUE = ACCEPTED, FALSE = REJECTED)
	bool Add_argument(argument);

	float Get_economic_op() { return economic_opinion; }
	float Get_ecologic_op() { return ecologic_opinion; }
	float Get_social_op() { return social_opinion; }
	float Get_economic_value() { return economic_value; }
	float Get_ecologic_value() { return ecologic_value; }
	float Get_social_value() { return social_value; }

	float Get_verdict();
	string Evaluate_verdict();
	
};

#endif