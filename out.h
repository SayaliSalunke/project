short AND(short a, short b);
short OR(short a, short b);
short NAND(short a, short b);
short NOR(short a, short b);
short XOR(short a, short b);
short XNOR(short a, short b);
short NOT(short a);
void glowled(ckt *c);/* function will find prime output(all the leds ) by tracking ckt from inputs */
void print(ckt *c);// call two functions below
char ** Boolean(ckt *c); /* function will make a boolean equation(string) from ckt by back tracking it */
void TruthTable(int nos, char **str); /* function will print a truthtable for a boolean equation given by above one , nos is no of switch*/

