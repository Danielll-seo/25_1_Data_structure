#ifndef STACK_H
#define STACK_H
#define MAX 100
typedef struct {
	int data[MAX];
	int top;
} Stack;

void initStack(Stack* s);
int isEmpty(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);

#endif // STACK_H
