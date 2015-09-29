#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AND 	1
#define OR 	2
#define NAND 	3
#define NOR	4
#define XOR 	5
#define XNOR	6
#define NOT 	7

typedef struct ckt {
	short noi;
	gate * last_gate;
	
}ckt;
typedef struct gate {
	short type; /* specifies type of the gate */
	short i1, i2, o; /* inout 1, input 2, output */
	struct gate *to; /* points to a gate to which output of current gate goes as input */
	struct gate *from1, *from2; /* points to a gate from which one of the inputs is inserted */
}gate;

short AND(short a, short b);
short OR(short a, short b);
short NAND(short a, short b);
short NOR(short a, short b);
short XOR(short a, short b);
short XNOR(short a, short b);
short NOT(short a);
void CreateGate(ckt *c);
void InGate(gate *g);
short SolveCkt(ckt *c);/* function will find prime output by tracking ckt from inputs */
void Modelling(ckt *c); /* function will read pictorial information and convert it to code usable */
char * Boolean(ckt *c); /* function will make a boolean equation(string) from ckt by back tracking it */
void TruthTable(char *str); /* function will print a truthtable for a boolean equation given by above one */

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

void CreateGate(ckt *c) {
	gate G, * last_gate;
	InGate(&G);
	Detecting the symbol
		decide type;
	Detecting connecting lines 
		change from1, from2, to;
		i1 = from1->o;
		i2 = from2->o;
	solve for o;
	if(to == NULL)
		c->last_gate = &G;
	if(from1 == NULL || from2 == NULL)
		c->noi++;
	if(from1 == NULL && from2 == NULL)
		c->noi++;
}

void InGate(gate *g) {
	g->to = g->from = NULL;
}

int main() {
	short ans;
	ckt c;
	/* assuming that there will be an interface which will hav a button " CKT DONE " */
	if(button is pressed) {
		ans = SolveCkt(&c);
	}
	printf("\n Answer : %d", ans);
	return 0;
}
