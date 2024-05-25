#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void _initMap_(Map** m){
    *m = (Map*)malloc(sizeof(Map));
    ((*m)->key) = (int*)malloc(sizeof(int));
    ((*m)->value) = (int*)malloc(sizeof(int));
    ((*m)->size) = 0;
}

int value(Map* m, int key){
    int i = 0;
    for(; i < (m->size); i++){
        if((m->key)[i] == key){
            return (m->value)[i];
        }
    }
    return -1;
}

void printMap(Map m){
   printf("{"); 
    for(int i = 0; i < (m.size) - 1; i++){
        printf("%d: %d, ", (m.key)[i], (m.value)[i]);
    }
    printf("%d: %d}\n", (m.key)[m.size - 1], (m.value)[m.size - 1]);
}

void insert(Map** m, int a, int b){
    ((*m)->key)[(*m)->size] = a;
    ((*m)->value)[(*m)->size] = b;
    ((*m)->size)++;
}