#include "func.h"

int sc_memoryInit()
{
	for (int i = 0; i < 100; i++)
		mem[i] = 0;
	return 0;
}

int sc_memorySet(int address, int value)
{
	if (address < 0 || address > 99) {
		printf("ERROR: wrong address");
		return -1;
	}
	mem[address] = value;
	return 0;
}

int sc_memoryGet(int address, int * value)
{
	if (address < 0 || address > 99) {
		printf("ERROR: wrong address");
		return -1;
	}
	*value = mem[address];
	return 0;
}

int sc_memoryLoad(char * filename)
{
	bfile = fopen(filename, "r+b");//r+b - open binary file for read/write 
	if (bfile == NULL) {
		printf("ERROR: file doesn't exist");
		return -2;
	}
	for (int i = 0; i < MEM_SIZE; i++) {
		fread(&mem, sizeof(int), 100, bfile);
	}
	return 0;
}

int sc_memorySave(char * filename)
{
	bfile = fopen(filename, "r+b");//r+b - open binary file for read/write 
	if (bfile == NULL) {
		bfile = fopen(filename, "wb");//wb - create binary file for write
		if (bfile == NULL) {
			printf("ERROR: file doesn't exist");
			return -2;
		}
	}
	for (int i = 0; i < MEM_SIZE; i++) {
		fwrite(&mem, sizeof(int), 100, bfile);
	}
	fclose(bfile);
	return 0;
}

int sc_regInit()
{
	flag = 0;
	return 0;
}

int sc_regSet(int reg, int value)
{
	if (reg == OEO || reg == DBZ || reg == OOA || reg == IÑP || reg == WC) {
		if (value == 0) {
			flag = flag & ~reg;
		}
		else if (value == 1) {
			flag = flag | reg;
		}
		else {
			return 0;
		}
	}
	return 0;
}

int sc_regGet(int reg, int * value, int print)
{
	if (reg == OEO || reg == DBZ || reg == OOA || reg == IÑP || reg == WC) {
		if ((flag & reg) != 0) {
			* value = 1;
		}
		else {
			* value = 0;
		}
	}
	if (print == 1)
		printf("\n%d", *value);

	return 0;
}

int sc_commandEncode(int command, int operand, int * value)
{
	if (command < 10 || (command > 11 && command < 20) || (command > 21 && command < 30) || (command > 33 && command < 40) || (command > 43 && command < 51) || command > 76)
		return 1;

	if (operand > 127 || operand < 0)
		return 1;

	*value = (command << 7) | operand;
	return 0;
}

int sc_commandDecode(int value, int *command, int *operand)
{
	if ((value >> 14) != 0)
		return 1;

	*command = value >> 7;
	*operand = value & 0x7F;

	return 0;
}

int sc_regFlagPrint()
{
	printf("\n%d\n", flag);
	return 0;
}
void sc_printMem()
{
	for (int i = 0; i < 100; i++) {
		printf("%.4d\t ", mem[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
}