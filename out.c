
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "out.h"
#include "stack.h"

gate *getgate(ckt * c, output * o) {
	int i;
	for(i = 0; i <= c->gi; i++) {
		if((o->type == c->garray[i].type) && (&(c->garray[i].o) == o))
			return (c->garray + i);
	}
	return NULL;

}
void pushit(ckt * c, stack *s, void *ptr, short typecurr) {//typecurrs possible are input led wire
	wire * w;
	input * i;
	led * l;	
	node * n;
	gate  * g;
	n = (node *)malloc(sizeof(node));
	switch(typecurr) {
		case WIRE :
			w = (wire *)ptr;
			switch(w->type1) {
				case SWITCH :
					n->ptr = w->start;
					n->type = SWITCH;
					push(s, n);
					return;
				case OUTPUT :
					n->ptr = w->start;
					n->type = OUTPUT;
					push(s, n);
					g = getgate(c, w->start);
					n->ptr = &(g->i2);
					n->type = INPUT;
					push(s, n);
					push(s, n);
					n->ptr = &(g->i1);
					push(s, n);
					push(s, n);
					return;	
			}
			
		case INPUT :
			i = (input *)ptr;
			n->ptr = w;
			n->type = WIRE;
			push(s, n);
			return;
		case LED :
			l = (led *)ptr;
			n->ptr = l->w;
			n->type = WIRE;
			push(s, n);
			return;				
	}

}

short fetchit(void * ptr, short type) {//types can be wire input switch
	short val;	
	wire * w;
	sch * s;
	input * i;
	switch(type) {
		case WIRE :
			w = (wire *)ptr;
			val = w->val;
			return val;
		case SWITCH :
			s = (sch *)ptr;
			val = s->state;
			return val;
		case INPUT :
			i = (input *)ptr;
			val = i->ip;
			return val;
	}
}

void putit(void * ptr, short type, short value) { // asked to put in input(here)
	input * i;
	if(type == INPUT) {
		i = (input *)ptr;
		i->ip = value;
	}
}

void glowled(ckt *c) { /* tracks the ckt and changes LED state */
	node * stacknode;
	int nol;
	stack s;
	init(&s);
	output *o;
	short i1, i2, value;
	for(nol = 0; nol <= c->li; nol ++) {
		//code to get ans for each output led
		pushit(c, &s, (c->larray + nol), LED);
		while(!empty(&s)) {
			stacknode = pop(&s);
			if(stacknode->type == OUTPUT) {
				o = (output*)stacknode->ptr;
				switch(o->type) {
					case AND :
						o->op = and(i1, i2);
						break; 
					case OR:
						o->op = or(i1, i2);
						break; 
					case NAND :
						o->op = nand(i1, i2);
						break; 
					case NOR :
						o->op = nor(i1, i2);
						break; 
					case XNOR:
						o->op = xnor(i1, i2);
						break; 
					case XOR:
						o->op = xor(i1, i2);
						break; 
					case NOT :
						o->op = not(i1);
						break; 
				}
				i1 = i2 = -1;
				if(empty(&s)) {
					break;
				}
				continue; // This can be the problem look out whike dddebugging thecode 
			}
			else {
				value = fetchit(stacknode->ptr, stacknode->type);
				if(value == -1) {
					pushit(c, &s, stacknode->ptr, stacknode->type);
				}
				else if(!empty) { 
					stacknode = pop(&s);
					putit(stacknode->ptr, stacknode->type, value);
					if(i1 == -1)
						i1 = value;
					else
						i2 = value;
				}
			}
		}
		c->larray[nol].ans = o->op;
	}
	for(nol = 0; nol <= c->li; nol ++) {
		changeLED(&(c->larray[nol]), c->larray[nol].ans);	
	}
}
/*
void print(ckt *c) {
	char ** bool;
	int i;
	bool = Boolean(c);
	printf("\n Bolean equation : \n ");
	for(i = 0; i <= c->li; i++) {
		printf(" Y%d = %s \n", i, bool[i]); 		
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
*/
short and(short a, short b) {
	if(a && b)
		return 1;
	return 0;
}
short or(short a, short b) {
	if(a || b)
		return 1;
	return 0;
}
short nand(short a, short b) {
	return not(and(a, b));
}
short nor(short a, short b) {
	return not(or(a, b));
}
short xor(short a, short b) {
	if(a != b)
		return 1;
	return 0;
}
short xnor(short a, short b) {
	if(a == b)
		return 1;
	return 0;
}
short not(short a) {
	if(a == 1)
		return 0;
	return  1;
}


