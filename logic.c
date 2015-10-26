/* all these functions are called by the main where we handle screen */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "logic.h"

void inc(ckt * c) {
	c->gi = c->wi = c->si = c->li = 0;
}

void ingate(gate * g, int x, int y, short type) {
	g->type = type;
	int x1, x2, x3, y1, y2, y3;
	if(type == NOT) {
		ininput(&(g->i1), x1, y1);
		g->i2.ip = -1;
		inoutput(&(g->o), x2, y2, type);
	}
	else {
		ininput(&(g->i1), x1, y1);
		ininput(&(g->i2), x2, y2);
		inoutput(&(g->o), x3, y3, type);
	}
} 

void ininput(input * i, int x, int y) {
	i->ip = -1;
	i->w = NULL;
	if(cnt == 0) {
		junction = (pos *)malloc(sizeof(pos));
	}
	else
		junction = (pos *)realloc(junction, sizeof(pos) * (cnt + 1));
	junction[cnt].x = x;
	junction[cnt].y = y;
	junction[cnt].type = INPUT;
	junction[cnt].ptr = i;
	cnt++;
}

void inoutput(output * o, int x, int y, short type) {
	o->op = -1;
	o->w = NULL;
	o->type = type;
	if(cnt == 0) {
		junction = (pos *)malloc(sizeof(pos));
	}
	else {
		junction = (pos *)realloc(junction, sizeof(pos) * (cnt + 1));
	}
	junction[cnt].x = x;
	junction[cnt].y = y;
	junction[cnt].type = OUTPUT;
	junction[cnt].ptr = o;
	cnt++;
}

void inwire(wire * w, int x1, int y1, int x2, int y2) {
	pos * p;
	struct input * iptr;
	output * optr;
	sch * sptr;
	led * lptr;
	w->val = -1;
	p = getit(x1, y1);
	w->type1 = p->type;
	w->start = p->ptr;
	switch(w->type1) {
		case INPUT:
			iptr = (input *)w->start;
			iptr->w = w;
			break;
		case OUTPUT:
			optr = (output *)w->start;
			optr->w = w;
			break;
		case SWITCH:
			sptr = (sch *)w->start;
			sptr->w = w;
			w->val = sptr->state;
			break;
		case LED:
			lptr = (led *)w->start;
			lptr->w = w;
			break;

	}
	p = getit(x2, y2);
	w->type2 = p->type;
	w->end = p->ptr;
	switch(w->type2) {
		case INPUT:
			iptr = (input *)w->end;
			iptr->w = w;
			break;
		case OUTPUT:
			optr = (output *)w->end;
			optr->w = w;
			break;
		case SWITCH:
			sptr = (sch *)w->end;
			sptr->w = w;
			w->val = sptr->state;
			break;
		case LED:
			lptr = (led *)w->end;
			lptr->w = w;
			break;
	}
}


void inswitch(sch * s, int x, int y, short state) {
	int x1, y1;
	/*x1 and y1 is actual connecting point */

	s->state = state;
	if(cnt == 0) {
		junction = (pos *)malloc(sizeof(pos));
	}
	else {
		junction = (pos *)realloc(junction, sizeof(pos) * (cnt + 1));
	}
	junction[cnt].x = x1;
	junction[cnt].y = y1;
	junction[cnt].type = SWITCH;
	junction[cnt].ptr = s;
	cnt++;
}

void inled(led *l , int x, int y ) {
	int x1, y1;
	/* x1 and y1 is actual connecting point */
	if(cnt == 0) {
		junction = (pos *)malloc(sizeof(pos));
	}
	else {
		junction = (pos *)realloc(junction, sizeof(pos) * (cnt + 1));
	}
	junction[cnt].x = x1;
	junction[cnt].y = y1;
	junction[cnt].type = LED;
	junction[cnt].ptr = l;
	cnt++;	
}

pos *getit(int x, int y) {
	pos *ptr = (pos *)malloc(sizeof(pos));
	int i = 0;
	for(i = 0; i <= cnt ; i++) {
		if(junction[i].x == x && junction[i].y == y) {
			ptr->x = x;
			ptr->y = y;
			ptr->ptr = junction[i].ptr;
			ptr->type = junction[i].type;
		}
	}
	return ptr;
}
