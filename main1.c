#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifndef SCREEN
#define SCREEN
#include "screen.h"
#endif
#define LOGIC
#ifndef OUT
#define OUT
#include "out.h"
#endif
#ifndef STACK
#define STACK
#include "stack.h"
#endif

int main() {
	pos *posptr;
	sch *s;
	action * a;
	short ans;
	initial_window();
	/* now complete track of the user movement is kept */
	ckt c;
	inc(&c);	
	int x2 ,y2, x3, y3;
	short type;
	a = get_action();
	while(a) {
		type = a->type;
		if(type == RESET) {
			inc(&c);
			initial_window();
		}
		else {
			while(type != DONE) {
				x2 = a->x2;
				y2 = a->y2;
				x3 = a->x3;
				y3 = a->y3;
				switch(type) {
					case AND : case OR : case NOR : case XOR :
					case NAND : case XNOR : case NOT :
						if(c.gi == 0) {
							c.garray = (gate*)malloc(sizeof(gate));
						}
						else
							c.garray = (gate *)realloc(c.garray, sizeof(gate) * (c.gi + 1));
						ingate((c.garray + c.gi), x2, y2, type);
						c.gi++;
						break;

					case WIRE :
						if(c.wi == 0) {
							c.warray = (wire *)malloc(sizeof(wire));
						}
						else
							c.warray = (wire *)realloc(c.warray, sizeof(wire) + (c.wi + 1));
						inwire((c.warray + c.wi), x2, y2, x3, y3); // in case of wire x3 and y3 are start and end points 
						c.wi++;
						break;

					case SWITCH :
						if(c.si == 0) {
							c.sarray = (sch *)malloc(sizeof(sch));
						}
						else
							c.sarray = (sch *)realloc(c.sarray, sizeof(sch) * (c.si + 1));
						c.sarray[c.si].index = c.si;
						inswitch((c.sarray + c.si), x2, y2, x3);// in case of switch x3 is state 
						c.si++;
						break;

					case LED :
						if(c.li == 0) {
							c.larray = (led *)malloc(sizeof(led));
						}
						else
							c.larray = (led*)realloc(c.larray, sizeof(led) * (c.li + 1));
						inled((c.larray + c.li), x2, y2);
						c.li++;
						break;

					case STATEC :
						posptr = (pos *)getit(x2, y2);
						s = (sch *)posptr->ptr;
						s->state = x3; // x3 is the new state 
						break;

				}
				a = get_action();
			 }
			/* you r here because circuit is completed 
			Now i got all the information regarding the same 
			task is to light the led according to the switches
			and print the boolean equation 
			and print the truthtable*/
			glowled(&c);/* Here i will have a fuction that will change the look of the led */
			//print(&c);
		}
		a = get_action();
	}
	return 0;
}
