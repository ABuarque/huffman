#ifndef STACK_H
#define STACK_H

#include "adjacency.h"

typedef struct stack{
	Node *top;
}Stack;

Stack* createStack();
void push(Stack *stack, int item);
int pop(Stack *stack);
int peek(Stack *stack);
int isEmptyStack(Stack *stack);
void printStack(Stack *stack);

#endif