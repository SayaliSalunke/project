/* array a and curr become global now */
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
void push(stack *s, node * n) {
	s->a[s->curr].ptr = n->ptr;
	s->a[s->curr].type = n->type;
	s->curr++;
}
node * pop(stack *s) {
	node * n;
	n = (node *)malloc(sizeof(node));
	n->ptr = s->a[s->curr - 1].ptr;
	n->type = s->a[s->curr - 1].type;
	s->curr--;
	return n;
}
/* This function gets added, because with a type declration, we can't do curr = 0 */
void init(stack *s) {
	s->curr = 0;
}
int empty(stack *s) {
	return s->curr == 0;
}
int full(stack *s) {
	return s->curr == 128;
}
