#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 200
#define MINSIZE 1

void readMatrix(int***, int , int);
void printMatrix(int**, int, int);
void setZeroes(int**, int, int*);
void zeroIt(int***, int, int, int, int);
void initFlagMat(int***, int**, int, int);

int main(){
    int rows, columns;
    printf("Enter number of rows:");
    scanf("%d", &rows);
    printf("Enter number of columns:");
    scanf("%d", &columns);
    if(rows >= MINSIZE && rows <= MAXSIZE){
        if(columns >= MINSIZE && columns <= MAXSIZE){
        } else {
            printf("Invalid size for columns\n");
            return 2;
        }
    } else {
        printf("Invalid size for rows\n");
        return 2;
    }
    int **matrix;
    readMatrix(&matrix, rows, columns);
    printf("Before:\n");
    printMatrix(matrix, rows, columns);
    printf("After:\n");
    setZeroes(matrix, rows, &columns);
    return 0;
}

void readMatrix(int*** matrix, int m, int n){
    *matrix = (int**)calloc(m, sizeof(int*));
    printf("Enter matrix elements:\n");
    for(int i = 0; i < m; i++){
        (*matrix)[i] = (int*)calloc(n, sizeof(int));
        for(int j = 0; j < n; j++){
            printf("Enter matrix element [%d][%d]:", i, j);
            scanf("%d", &(*matrix)[i][j]);
        }
   } 
}

void printMatrix(int** matrix, int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// void initFlagMat(int ***flag, int **matrix, int m, int n){
//     *flag = (int**)calloc(m, sizeof(int*));
//     for(int i = 0; i < m; i++){
//         (*flag)[i] = (int*)calloc(n, sizeof(int));
//         for(int j = 0; j < n; j++){
//             if(matrix[i][j] != 0){
//                 (*flag)[i][j] = 1;
//             }
//             else
//             (*flag)[i][j] = 0;
//         }
//    }
// }

// void zeroIt(int*** matrix, int m, int n, int x, int y){
//     for(int i = 0; i < m; i++){
//         (*matrix)[i][y] = 0;
//     }
//     for(int i = 0; i < n; i++){
//         (*matrix)[x][i] = 0;
//     }
// }
// 
// void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
//     int m = matrixSize;
//     int n = *matrixColSize;
//     int** flag;
//     initFlagMat(&flag, matrix, m, n);
//     for(int i = 0; i < m; i++){
//         for(int  j = 0; j < n; j++){
//             if(flag[i][j] == 0){
//                 zeroIt(&matrix, m, n, i, j);
//             }
//         }
//    }
//    printMatrix(matrix, m, n); 
// }

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int m = matrixSize;
    int n = *matrixColSize;
    int col0 = 1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 0){
                if(j == 0){
                    col0 = 0;
                } else matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }

    if(matrix[0][0] == 0){
        for(int i = 0; i < n; i++) matrix[0][i] = 0;
    }
    if(col0 == 0){
        for(int i = 0; i < m; i++){
            matrix[i][0] = 0;
        }
    }
    printMatrix(matrix, m, n);
}