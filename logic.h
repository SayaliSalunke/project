/* This Header File contains functions to build the data structure ckt */
#ifndef LOGIC
#define LOGIC


#define AND 	1
#define OR 	2
#define NAND 	3
#define NOR	4
#define XOR 	5
#define XNOR	6
#define NOT 	7
#define INPUT 	8
#define OUTPUT 	9
#define LED  	10
#define SWITCH 	11
#define GATE 	12
#define WIRE 	13
#define STATEC	14
#define DONE 	15
#define RESET 	16

typedef struct wire {
	short val;
	short type1 , type2;// sch led input output
	void * start, * end ;
}wire;

typedef struct sch {
	short index;// identity for a switch
	short state;
	wire *w; 
}sch;

typedef struct led {
	short index;// identity for a led
	short ans;
	wire * w;
}led;

typedef struct output {
	short type ; // type of the corresponding gate  
	short op;
	wire * w;

}output;

typedef struct input {
	short ip;
	wire * w;
}input;


/* this is the structure whose array junction we will be using to build structure i.e. to link the elements with each other */
typedef struct pos {//input output sch led 
	int x, y; /* center of the icon */
	void * ptr;// pointer to the element
	short type;// type of the element 
}pos;

typedef struct gate {
	short type;
	input i1, i2;
	output o;
}gate;


struct pos *junction;
int cnt;// no . of elements in the junction 

typedef struct ckt {
	gate * garray; // array of gates 
	led *larray;// array of leds
	sch * sarray;// array of switches
	wire * warray;// array of wires
	int gi, si, li, wi; // corresponding counters
}ckt;

void inc(ckt * c);
void ingate(gate *, int, int, short);
void ininput(input *, int, int);
void inoutput(output *, int, int, short);
void inwire(wire *, int, int, int, int);
pos *getit(int x, int y);
void inswitch(sch * s, int x, int y, short state);
void inled(led *l, int x, int y);

#endif
