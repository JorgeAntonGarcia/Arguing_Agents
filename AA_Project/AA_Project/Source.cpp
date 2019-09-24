#include "argument.h"
#include <stdlib.h>
#include <stdio.h>

void main() {
	argument a1(ECONOMIC,false,85,62);
	
	printf("%d", a1.Get_nature());
	printf("\n");
	system("pause");
}