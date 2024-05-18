#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void generate(int);
void prettyPrint(int**, int);

int main(){
    int n;
    printf("Enter number of rows:");
    scanf("%d", &n);
    generate(n);
    return 0;
}

void prettyPrint(int** matrix, int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            printf(" ");
        }
        for(int j = 0; j <= i; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void generate(int numRows){
    int **result = (int**)calloc(numRows, sizeof(int*));
    for(int i = 0; i < numRows; i++){
        result[i] = (int*)calloc((i+1), sizeof(int));
        result[i][0] = 1;
        result[i][i] = 1;
        if(i > 1){
            for(int j = 1; j < i; j++){
                result[i][j] = result[i-1][j-1] + result[i-1][j];
            }
        }
    }
    prettyPrint(result, numRows);
}