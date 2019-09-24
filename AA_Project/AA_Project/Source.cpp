#include "listener.h"
#include <stdlib.h>
#include <stdio.h>

void main() {
	argument a1(ECONOMIC,false,85,0);
	listener l;
	l.Add_argument(a1);
	printf("\n");
	system("pause");
}