#ifndef MAP_C_
#define MAP_C_

struct map{
    int* key;
    int* value;
    int size;
};

typedef struct map Map;

void _initMap_(Map**);
void insert(Map**, int, int);
void printMap(Map);
int value(Map*, int);

#endif