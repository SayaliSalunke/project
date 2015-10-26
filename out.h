/* THis header File contains fuctions to glow led and print truthtable and boolean equation */
#ifndef OUT
#define OUT

#include "logic.h"

short and(short a, short b);
short or(short a, short b);
short nand(short a, short b);
short nor(short a, short b);
short xor(short a, short b);
short xnor(short a, short b);
short not(short a);
void glowled(ckt *c);/* function will find prime output(all the leds ) by tracking ckt from inputs */

/*followinf three things are optional */
/*
void print(ckt *c); call two functions below
char ** Boolean(ckt *c); /* function will make a boolean equation(string) from ckt by back tracking it 
void TruthTable(int nos, char **str); /* function will print a truthtable for a boolean equation given by above one , nos is no of switch*/
#endif
