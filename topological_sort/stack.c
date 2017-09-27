#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* createStack(){
	Stack* newStack = malloc(sizeof(Stack));
	newStack->top = NULL;
	return newStack;
}

void push(Stack *stack, int item){
	Node *newNode = malloc(sizeof(Node));
	newNode->item = item;
	newNode->next = stack->top;
	stack->top = newNode;
}

int pop(Stack *stack){
	if(!isEmptyStack(stack)){
		int result = stack->top->item;
		Node *removed = stack->top;
		stack->top = stack->top->next;
		free(removed); 

		return result;
	}

	return -1;
}

int peek(Stack *stack){
	if(!isEmptyStack(stack))
		return stack->top->item;
	return -1;
}

int isEmptyStack(Stack *stack){
	return (stack->top == NULL);
}

void printStack(Stack *stack){
	while(stack->top != NULL){
		printf("%d\n",pop(stack));
	}
}