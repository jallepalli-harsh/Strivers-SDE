#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;
#define MAXSIZE 200
#define MINSIZE 1

void readMatrix(vector<vector<int>>*);
void printMatrix(vector<vector<int>>);
void setZeroes(vector<vector<int>>);

int main(){
    int rows, columns;
    cout << "Enter number of rows:";
    cin >> rows;
    cout << "Enter number of columns:";
    cin >> columns;
    if(rows >= MINSIZE && rows <= MAXSIZE){
        if(columns >= MINSIZE && columns <= MAXSIZE){
        } else {
            cout << "Invalid size for columns\n";
            return 2;
        }
    } else {
        cout << "Invalid size for rows\n";
        return 2;
    }
    vector<vector<int>> matrix(rows, vector<int>(columns, 0));
    readMatrix(&matrix);
    cout << "Before:\n";
    printMatrix(matrix);
    cout << "After:\n";
    setZeroes(matrix);
    return 0;
}

void readMatrix(vector<vector<int>>* matrix){
    int m = (*matrix).size();
    int n = (*matrix)[0].size();
    cout << "Enter matrix elements:\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << "Enter matrix element [" << i << "][" << j << "]:";
            cin >> (*matrix)[i][j];
        }
   } 
}

void printMatrix(vector<vector<int>> matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
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

void setZeroes(vector<vector<int>> matrix){
    int m = matrix.size();
    int n = matrix[0].size();
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
    printMatrix(matrix);
}