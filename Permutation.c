#include<stdio.h>
#include<stdlib.h>

#define NUM 10

void printans(int *A, int *B, int n, int m);

int main(){
    int n, k = 0;
    int Input[NUM];
    while (scanf("%d", &n) != EOF && n != 0){
        Input[k] = n;
        k++;
    }
    for (int i = 0; i < k; i++){
        int t = Input[i];
        int *A = (int *)malloc(t * sizeof(int));
        int *B = (int *)malloc(t * sizeof(int));
        for(int j= 0; j < t; j++) B[j] = 0;
        printans(A, B, 1, t);
    }
    return 0;
}

void printans(int *A, int *B, int n, int m){
    if (n > m){
        for (int i = 0; i < m - 1; i++){
            printf("%d ", A[i]);
        }
        printf("%d\n", A[m - 1]);

        return;
    }
    for (int i = 0; i < m; i++){
        if (B[i] != 1){
            A[n - 1] = i + 1;
            B[i] = 1;
            n++;
            printans(A, B, n, m);
            n--;
            B[i] = 0;
        }
    }       
}