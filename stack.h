#ifndef STACK
#define STACK

#define MAX 128
/* array a and curr become global now */
typedef struct node {
	void * ptr;
	short type;
}node;

typedef struct stack {
	node a[MAX];
	int curr;
}stack;

void push(stack *s, node * n); 
node * pop(stack *s);
void init(stack *s); 
int empty(stack *s);
int full(stack *s);

#endif
