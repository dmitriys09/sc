#include "func.h"

int main()
{
	int value;
	sc_memoryInit();
	sc_memorySet(0, 1);
	sc_memorySet(1, 10);

	sc_memoryGet(1, &value);
	printf("\nvalue = %d\n", value);
	
	sc_printMem();
	printf("\nvalue = %d\n", mem[1]);

	return 0;
}