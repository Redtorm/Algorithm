#include<stdio.h>
#include<stdlib.h>

#define NUM 10

void combination(int *A, int n, int m, int t);

int main(){
    int n, m, i, j, k = 0;
    int Input[NUM][2];
    while (scanf("%d%d", &n, &m) != EOF && (n + m) != 0){
        Input[k][0] = n;
        Input[k][1] = m;
        k++;
    }
    for (i = 0; i < k; i++){
        n = Input[i][0];
        m = Input[i][1];
        int *A = (int *)malloc(n * sizeof(int));
        combination(A, n, m, 1);
    }
    return 0;
}

void combination(int *A, int n, int m, int t){
    if (t > n){
        int i, j = 0, s = 0;
        for (i = 0; i < n; i++) s += A[i];
        if (s == m){
            for (i = 0; i < n; i++){
                if (A[i] == 1) {
                    j++;
                    if (j == m) printf("%d\n", i + 1);
                    else printf("%d ", i + 1);     
                }
            }
        }
        return;
    }
    A[t - 1] = 1;
    t++;
    combination(A, n, m, t);
    t--;
    A[t - 1] = 0;
    t++;
    combination(A, n, m, t);
    t--;
}