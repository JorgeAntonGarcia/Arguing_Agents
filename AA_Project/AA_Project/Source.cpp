#include "listener.h"
#include <stdlib.h>
#include <stdio.h>

#define NUM_LISTENERS 9


int main() {
	listener Listeners_list[NUM_LISTENERS] = { (1),(1),(1),(2),(2),(2),(3),(3),(3) };
	list <argument> Background_1, Background_2, Background_3, Arguments_given;
	float initial_scores[NUM_LISTENERS], before_scores[NUM_LISTENERS], after_scores[NUM_LISTENERS];
	argument* arg;

	// Setting up the 1st background (focused on Economic values)
	arg = new argument(1, ECONOMIC, true, 90.0f, 60.0f); Background_1.push_back(*arg);
	arg->set_argument(2, ECONOMIC, true, 89.0f, 56.5f); Background_1.push_back(*arg);
	arg->set_argument(3, ECONOMIC, true, 83.5f, 71.2f); Background_1.push_back(*arg);
	arg->set_argument(4, ECONOMIC, true, 76.3f, 42.9f); Background_1.push_back(*arg);
	arg->set_argument(5, ECONOMIC, true, 61.4f, 81.8f); Background_1.push_back(*arg);
	arg->set_argument(6, ECONOMIC, true, 51.0f, 61.3f); Background_1.push_back(*arg);
	arg->set_argument(7, ECONOMIC, true, 49.2f, 51.2f); Background_1.push_back(*arg);
	arg->set_argument(8, ECONOMIC, true, 41.1f, 91.3f); Background_1.push_back(*arg);
	arg->set_argument(9, ECONOMIC, true, 30.6f, 22.8f); Background_1.push_back(*arg);
	arg->set_argument(10, ECONOMIC, false, 88.9f, 54.8f); Background_1.push_back(*arg);
	arg->set_argument(11, ECONOMIC, false, 57.0f, 62.7f); Background_1.push_back(*arg);
	arg->set_argument(12, ECONOMIC, false, 51.5f, 52.1f); Background_1.push_back(*arg);
	arg->set_argument(13, ECONOMIC, false, 27.4f, 37.2f); Background_1.push_back(*arg);
	arg->set_argument(14, SOCIAL, true, 72.4f, 82.9f); Background_1.push_back(*arg);
	arg->set_argument(15, SOCIAL, true, 62.4f, 61.2f); Background_1.push_back(*arg);
	arg->set_argument(16, SOCIAL, true, 52.6f, 32.7f); Background_1.push_back(*arg);
	arg->set_argument(17, SOCIAL, false, 80.1f, 70.5f); Background_1.push_back(*arg);
	arg->set_argument(18, SOCIAL, false, 59.3f, 25.1f); Background_1.push_back(*arg);
	arg->set_argument(19, ECOLOGIC, true, 30.0f, 71.2f); Background_1.push_back(*arg);
	arg->set_argument(20, ECOLOGIC, false, 27.4f, 69.3f); Background_1.push_back(*arg);
	arg->set_argument(21, ECOLOGIC, false, 22.8f, 91.0f); Background_1.push_back(*arg);

	// Setting up the 2nd background (focused on Social values)
	arg->set_argument(22, SOCIAL, true, 90.0f, 60.0f); Background_2.push_back(*arg);
	arg->set_argument(23, SOCIAL, true, 89.0f, 56.5f); Background_2.push_back(*arg);
	arg->set_argument(24, SOCIAL, true, 83.5f, 71.2f); Background_2.push_back(*arg);
	arg->set_argument(25, SOCIAL, true, 76.3f, 42.9f); Background_2.push_back(*arg);
	arg->set_argument(26, SOCIAL, true, 61.4f, 81.8f); Background_2.push_back(*arg);
	arg->set_argument(27, SOCIAL, true, 51.0f, 61.3f); Background_2.push_back(*arg);
	arg->set_argument(28, SOCIAL, true, 49.2f, 51.2f); Background_2.push_back(*arg);
	arg->set_argument(29, SOCIAL, true, 41.1f, 91.3f); Background_2.push_back(*arg);
	arg->set_argument(30, SOCIAL, true, 30.6f, 22.8f); Background_2.push_back(*arg);
	arg->set_argument(31, SOCIAL, false, 88.9f, 54.8f); Background_2.push_back(*arg);
	arg->set_argument(32, SOCIAL, false, 57.0f, 62.7f); Background_2.push_back(*arg);
	arg->set_argument(33, SOCIAL, false, 51.5f, 52.1f); Background_2.push_back(*arg);
	arg->set_argument(34, SOCIAL, false, 27.4f, 37.2f); Background_2.push_back(*arg);
	arg->set_argument(35, ECOLOGIC, true, 72.4f, 82.9f); Background_2.push_back(*arg);
	arg->set_argument(36, ECOLOGIC, true, 62.4f, 61.2f); Background_2.push_back(*arg);
	arg->set_argument(37, ECOLOGIC, true, 52.6f, 32.7f); Background_2.push_back(*arg);
	arg->set_argument(38, ECOLOGIC, false, 80.1f, 70.5f); Background_2.push_back(*arg);
	arg->set_argument(39, ECOLOGIC, false, 59.3f, 25.1f); Background_2.push_back(*arg);
	arg->set_argument(40, ECONOMIC, true, 30.0f, 71.2f); Background_2.push_back(*arg);
	arg->set_argument(41, ECONOMIC, false, 27.4f, 69.3f); Background_2.push_back(*arg);
	arg->set_argument(42, ECONOMIC, false, 22.8f, 91.0f); Background_2.push_back(*arg);

	// Setting up the 3th background (general knowledge)
	arg->set_argument(43, ECONOMIC, true, 90.0f, 60.0f); Background_3.push_back(*arg);
	arg->set_argument(44, ECONOMIC, true, 89.0f, 56.5f); Background_3.push_back(*arg);
	arg->set_argument(45, ECONOMIC, true, 83.5f, 71.2f); Background_3.push_back(*arg);
	arg->set_argument(46, ECONOMIC, true, 76.3f, 42.9f); Background_3.push_back(*arg);
	arg->set_argument(47, ECONOMIC, false, 61.4f, 81.8f); Background_3.push_back(*arg);
	arg->set_argument(48, ECONOMIC, false, 51.0f, 61.3f); Background_3.push_back(*arg);
	arg->set_argument(49, ECONOMIC, false, 49.2f, 51.2f); Background_3.push_back(*arg);
	arg->set_argument(50, SOCIAL, true, 91.1f, 91.3f); Background_3.push_back(*arg);
	arg->set_argument(51, SOCIAL, true, 83.6f, 22.8f); Background_3.push_back(*arg);
	arg->set_argument(52, SOCIAL, true, 81.9f, 54.8f); Background_3.push_back(*arg);
	arg->set_argument(53, SOCIAL, true, 77.0f, 62.7f); Background_3.push_back(*arg);
	arg->set_argument(54, SOCIAL, false, 51.5f, 52.1f); Background_3.push_back(*arg);
	arg->set_argument(55, SOCIAL, false, 27.4f, 37.2f); Background_3.push_back(*arg);
	arg->set_argument(56, SOCIAL, false, 72.4f, 82.9f); Background_3.push_back(*arg);
	arg->set_argument(57, ECOLOGIC, true, 92.4f, 61.2f); Background_3.push_back(*arg);
	arg->set_argument(58, ECOLOGIC, true, 82.6f, 32.7f); Background_3.push_back(*arg);
	arg->set_argument(59, ECOLOGIC, true, 70.1f, 70.5f); Background_3.push_back(*arg);
	arg->set_argument(60, ECOLOGIC, true, 59.3f, 25.1f); Background_3.push_back(*arg);
	arg->set_argument(61, ECOLOGIC, false, 70.0f, 71.2f); Background_3.push_back(*arg);
	arg->set_argument(62, ECOLOGIC, false, 67.4f, 69.3f); Background_3.push_back(*arg);
	arg->set_argument(63, ECOLOGIC, false, 52.8f, 91.0f); Background_3.push_back(*arg);

	for (int i = 0; i < NUM_LISTENERS; i++) { initial_scores[i] = Listeners_list[i].Get_verdict(); }

	for (int i = 0; i < NUM_LISTENERS; i++) {
		if (i % 3 == 0) { Listeners_list[i].Add_set_arguments(Background_1); }
		else if(i%3 == 1){ Listeners_list[i].Add_set_arguments(Background_2); }
		else{ Listeners_list[i].Add_set_arguments(Background_3); }
	}

	for (int i = 0; i < NUM_LISTENERS; i++) { before_scores[i] = Listeners_list[i].Get_verdict();}

	for (int i = 0; i < NUM_LISTENERS; i++) {
		printf("\nListener %d\n",i+1);
		printf("Initial score: %f  After Background: %f\n", initial_scores[i], before_scores[i]);
	}

	system("pause");

}

