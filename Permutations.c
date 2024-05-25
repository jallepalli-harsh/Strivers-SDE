#include <stdio.h>
#include <stdlib.h>

int** permute(int*, int, int*);
void backtrack(int*, int, int**, int***, int);
void swap(int*, int*);

int main(){
    int n;
    printf("Enter number of elements:");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        printf("Enter %d element:", (i+1));
        scanf("%d", &arr[i]);
    }
    int returnSize;
    int** res = permute(arr, n, &returnSize);
    for(int i = 0; i < returnSize; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void backtrack(int* nums, int numsSize, int** returnSize, int*** result, int index){
    if(index == numsSize){
        (**returnSize)++;
        *result = (int**)realloc(*result, sizeof(int*) * (**returnSize));
        (*result)[**returnSize - 1] = (int*)malloc(sizeof(int) * numsSize);
        for(int i=0; i<numsSize; i++){
            (*result)[**returnSize - 1][i] = nums[i];
        }
        return;
    }
    for(int i = index; i < numsSize; i++){
        swap(nums+index, nums+i);
        backtrack(nums, numsSize, returnSize, result, index + 1);
        swap(nums+index, nums+i);
    }
}

int** permute(int* nums, int numsSize, int* returnSize){
    int** result;
    *returnSize = 1;

    for(int i = 1; i <= numsSize; i++) (*returnSize) *= i;
    
    result = (int**)malloc(sizeof(int*));
    *returnSize = 0;

    backtrack(nums, numsSize, &returnSize, &result, 0);
    return result;
}