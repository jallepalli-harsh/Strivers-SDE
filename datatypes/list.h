#ifndef LIST_H_
#define LIST_H_

struct node{
    int val;
    struct node *next;
};

typedef struct node List;

void _initNode_(List**);
void add(List**, int);
void printList(List*);

#endif