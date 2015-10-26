/* THis Header Files contains functions to do screen manipulation */

#ifndef SCREEN
#define SCREEN
#include "logic.h"
typedef struct action {
	int x2, x3, y2, y3;
	short type;
}action;

action * get_action();// gives about the action performed on the screen

void initial_window();/* above window gives toolbox and a field to draw the ckt */

void changeLED(led *, short ); /* changes state of the led to given as argument */

#endif
