#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include "screen.h"


action * get_action() {
	action * a = (action *)malloc(sizeof(action));
	return a;

}

void initial_window() {
	//all screen loading 
	initscr();
	printw(" Toolbox ");
	refresh();
	getch();
	endwin();
}

void changeLED(led * l, short type ) {

}
