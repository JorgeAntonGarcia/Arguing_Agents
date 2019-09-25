#include "listener.h"
#include <stdlib.h>
#include <stdio.h>

void main() {
	listener l1(1), l2(1), l3(2), l4(3), l5(1);
	argument arg1(ECONOMIC, true, 100.0f, 100.0f), arg2(ECONOMIC, true, 1.0f, 100.0f), arg3(ECONOMIC, true, 1.0f, 100.0f),
		arg4(ECONOMIC, true, 1.0f, 50.0f), arg5(ECONOMIC, true, 1.0f, 50.0f), arg6(ECONOMIC, true, 1.0f, 70.0f),
		arg7(ECONOMIC, true, 1.0f, 40.0f), arg8(ECONOMIC, true, 1.0f, 60.0f), arg9(ECONOMIC, true, 1.0f, 10.0f);

	printf("%f ",l1.Get_economic_op());
	l1.Add_argument(arg1);
	printf("%f ", l1.Get_economic_op());
	l1.Add_argument(arg1);
	printf("%f ", l1.Get_economic_op());

	system("pause");

}