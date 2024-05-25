#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void _initStack_(Stack** s){
    *s = (Stack*)malloc(sizeof(Stack));
    ((*s)->elements) = (int*)malloc(sizeof(int));
    ((*s)->size) = 0;
}


void push(Stack* s,int x){
    (s->elements)[(s->size)++] = x;
}

int pop(Stack* s){
    if(s->size == 0){
        printf("Stack is empty\n");
        return -1;
    }
    return (s->elements)[(s->size)--];
}

int getTop(Stack* s){
    if(s->size == 0){
        printf("Stack is empty\n");
        return -1;
    }
    return (s->elements)[(s->size) - 1];
}

int getSize(Stack* s){
    if(s->size == 0){
        printf("Stack is empty\n");
        return -1;
    }
    return (s->size);
}

void printStack(Stack s){
    if(s.size == 0){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack:");
    for(int i = 0; i < (s.size); i++){
        printf("%d ", (s.elements)[i]);
    }
    printf("\n");
}