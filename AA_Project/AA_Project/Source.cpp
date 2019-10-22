#include "listener.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>

#define NUM_LISTENERS 9

int main() {

	listener Listeners_list[NUM_LISTENERS] = { (1), (1), (1), (2), (2), (2), (3), (3), (3) };
	list<argument> argument_list;
	float expertise_initial[NUM_LISTENERS], expertise_final[NUM_LISTENERS], emotion_initial[NUM_LISTENERS], emotion_final[NUM_LISTENERS];
	int arg_acc_before[NUM_LISTENERS], arg_rej_before[NUM_LISTENERS];

	argument *arg = new argument(1, true, 0.0, 50.0); argument_list.push_back(*arg);
	arg->set_argument(2, true, 10.0, 50.0); argument_list.push_back(*arg);
	arg->set_argument(3, true, 20.0, 50.0); argument_list.push_back(*arg);
	arg->set_argument(4, true, 30.0, 50.0); argument_list.push_back(*arg);
	arg->set_argument(5, true, 40.0, 50.0); argument_list.push_back(*arg);
	arg->set_argument(6, true, 50.0, 50.0); argument_list.push_back(*arg);
	arg->set_argument(7, true, 50.0, 50.0); argument_list.push_back(*arg);
	arg->set_argument(8, true, 50.0, 50.0); argument_list.push_back(*arg);
	arg->set_argument(9, true, 50.0, 50.0); argument_list.push_back(*arg);
	arg->set_argument(10, true, 50.0, 50.0); argument_list.push_back(*arg);

	for (int i = 0; i < NUM_LISTENERS; i++) {
		expertise_initial[i] = Listeners_list[i].Get_grade_of_expertise();
		emotion_initial[i] = Listeners_list[i].Get_emotional_state();
		printf("Listener %d  :  ", i + 1);
		printf("Initial: grade of expertise: %.2f   emotional state: %.2f\n", expertise_initial[i], emotion_initial[i]);
	}

	printf("\n\n");

	for (int i = 0; i < NUM_LISTENERS; i++) { Listeners_list[i].Add_set_arguments(argument_list); }

	for (int i = 0; i < NUM_LISTENERS; i++) {
		expertise_final[i] = Listeners_list[i].Get_grade_of_expertise();
		emotion_final[i] = Listeners_list[i].Get_emotional_state();
		arg_acc_before[i] = Listeners_list[i].Get_arguments_accepted();
		arg_rej_before[i] = Listeners_list[i].Get_arguments_rejected();
		printf("Listener %d  :  ", i + 1);
		printf("Final: grade of expertise : %.2f   emotional state : %.2f     Arguments accepted: %d  Arguments rejected: %d\n",
			expertise_final[i], emotion_final[i], arg_acc_before[i], arg_rej_before[i]);
	}

	printf("\n\n");

	/*
	//CSV file input data
	std::ofstream myfile;
	myfile.open("results.csv");
	myfile
		<< "Listener number,"
		" Initial score,"
		" After background score,"
		" Arguments accepted (BS),"
		" Arguments rejected (BS),"
		" Final Score,"
		" Arguments accepted (FS),"
		" Arguments rejected (FS) \n";

	for (int i = 0; i < NUM_LISTENERS; i++) {
		myfile << to_string(i + 1) + "," +
			to_string(Listeners_list[i].Get_arguments_accepted()) + "," +
			to_string(Listeners_list[i].Get_arguments_rejected()) + "\n";

	}
	myfile.close();*/

	system("pause");

}

