#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

#define OEO 0b00000001//overflow on execution of the operation
#define DBZ 0b00000010//divide error by 0
#define OOA 0b00000100// OUT of array
#define IÑP 0b00001000//IGNORING OF CURRENT PULSES
#define WC 0b00010000//WRONG COMMAND
#define MEM_SIZE 100

extern int mem[MEM_SIZE];
extern FILE *bfile;
extern int flag;

int sc_memoryInit();
int sc_memorySet(int address, int value);
int sc_memoryGet(int address, int * value);
int sc_memoryLoad(char * filename);
int sc_memorySave(char * filename);
void sc_printMem();

int sc_regInit();
int sc_regSet(int reg, int value);
int sc_regGet(int, int * value, int print);
int sc_commandEncode(int command, int operand, int * value);
int sc_commandDecode(int value, int *command, int *operand);
int sc_regFlagPrint();

#endif