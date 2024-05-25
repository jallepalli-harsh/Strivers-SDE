#include <stdio.h>
#include <stdlib.h>
#include "datatypes/map.h"
#include "datatypes/stack.h"
#include "datatypes/list.h"

int** generatePermutations(int, int[]);
void recursionPermutations(Map**, int, int[]);

int main(){
    int n;
    printf("Enter number of elements:");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        printf("Enter %d element:", (i+1));
        scanf("%d", &arr[i]);
    }
    int** res = generatePermutations(n, arr);
    return 0;
}

// int** recursionPermutations(Map** m, int n, int ar[]){
//     int i = 0;
//     if( == n){
//         *(result)
//     }
// }

int** generatePermutations(int n, int arr[]){
    int* s;
    Map* m;
    _initMap_(&m);
    for(int i = 0; i < n; i++){
        insert(&m, arr[i], 0);
    }
    printMap(*m);
    int** result;
    // recursionPermutations(&result, &s, &m, n, arr);
    return result;
}