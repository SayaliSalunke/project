#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void glowled(ckt *c) {
	int nol;
	for(nol = 0; nol <= c->li; nol ++) {
		
	}
}

void print(ckt *c) {
	char ** bool;
	int i;
	bool = Boolean(c);
	printf("\n Bolean equation : \n ");
	for(i = 0; i <= c->li; i++) {
		printf(" Y%d = %s \n", i, *bool[i]); 		
	}
	TruthTable(c->si, bool);
}

char ** Boolean(ckt *c) {
	int i;
	char ** strarr;
	strarr = (char **)malloc(sizeof(char *) * (c->li + 1));
	for(i = 0; i <= c->li; i++) {
		strarr[i] = (char *)malloc(50);		
	}
	

	
	return strarr;
} 
void TruthTable(int nos, char **str) {

} 

short AND(short a, short b) {
	if(a && b)
		return 1;
	return 0;
}
short OR(short a, short b) {
	if(a || b)
		return 1;
	return 0;
}
short NAND(short a, short b) {
	return NOT(AND(a, b));
}
short NOR(short a, short b) {
	return NOT(OR(a, b));
}
short XOR(short a, short b) {
	if(a != b)
		return 1;
	return 0;
}
short XNOR(short a, short b) {
	if(a == b)
		return 1;
	return 0;
}
short NOT(short a) {
	if(a == 1)
		return 0;
	return  1;
}


