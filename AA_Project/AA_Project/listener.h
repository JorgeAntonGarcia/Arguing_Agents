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
	int number_arg_accepted;
	int number_arg_rejected;

	// VARIABLES THAT CONFORM THE SUBJECT POSITION
	float grade_of_expertise; // Reflects sensitivity to involvement
	float emotional_state; // Reflects sensitivity to AR_ratios

	// POSITION OF THE SUBJECT RELATED TO THE TOPIC
	bool is_pro;

	// functions
	bool Evaluate_argument(argument, float, float, float);
	void Update_opinion(argument, bool, float *, float *);
	float get_random();
	bool Check_KB(int);

public:
	listener() {  
		grade_of_expertise = 0.0f; emotional_state = 50.0f; is_pro = true; number_arg_accepted = 0; number_arg_rejected = 0;
	}
	listener(float expertise, float emotional = 50.0f, bool pro = true) {
		grade_of_expertise = expertise; emotional_state = emotional; is_pro = pro;
		number_arg_accepted = 0; number_arg_rejected = 0;
	}
	listener(int);
	~listener();

	// FUNCTION OF ACCEPTANCE OF NEW ARGUMENTS, RETURNS A BOOLEAN (TRUE = ACCEPTED, FALSE = REJECTED)
	bool Add_argument(argument);
	void Add_set_arguments(list<argument>);
	float Get_grade_of_expertise() { return grade_of_expertise; }
	float Get_emotional_state() { return emotional_state; }
	bool Get_is_pro() { return is_pro; }

	int Get_arguments_accepted() { return number_arg_accepted; }
	int Get_arguments_rejected() { return number_arg_rejected; }
	
};

#endif