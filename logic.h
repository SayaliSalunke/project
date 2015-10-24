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
	index;
	short state;
	wire *w; 
}sch;

typedef struct led {
	short ans;
	wire * w;
}led;

typedef struct output {
	short op;
	wire * w;

}output;

typedef struct input {
	short ip;
	wire * w;
}input;

typedef struct pos {//input output sch led 
	int x, y; /* center of the icon */
	void * ptr;
	short type;
}pos;

typedef struct gate {
	short type;
	input i1, i2;
	output o;
}gate;


struct pos *junction;
int cnt;

typedef struct ckt {
	gate * garray;
	led *larray;
	sch * sarray;
	wire * warray;
	int gi, si, li, wi;
}ckt;

void inc(ckt * c);
void ingate(gate *, int, int, short);
void ininput(input *, int, int);
void inoutput(output *, int, int);
void inwire(wire *, int, int, int, int);
pos *getit(int x, int y);
void insch(sch * s, int x, int y, short state);
void inled(led *l, int x, int y);
