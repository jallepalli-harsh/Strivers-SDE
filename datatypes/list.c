#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void _initNode_(List** newNode){
    *newNode = (List*)malloc(sizeof(List));
    (*newNode)->val = 0;
    (*newNode)->next = NULL;
}

void add(List** head, int x){
    List *newNode;
    _initNode_(&newNode);
    newNode->val = x;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    List *tmp = *head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void printList(List *head){
    List *tmp = head;
    printf("The list is: ");
    while(tmp != NULL){
        printf("%d -> ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}