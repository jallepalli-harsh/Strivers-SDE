#ifndef STACK_H_
#define STACK_H_

struct stack{
    int* elements;
    int size;
};

typedef struct stack Stack;

void _initStack_(Stack**);
void push(Stack*, int);
int pop(Stack*);
int getTop(Stack*);
int getSize(Stack*);
void printStack(Stack s);

#endif