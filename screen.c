#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ncurse.h"

action * get_action() {
	action * a = (action *)malloc(sizeof(action));
	return a;

}

void initial_window() {
	//all screen loading 
}
