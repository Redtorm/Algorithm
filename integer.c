#include<stdio.h>
#include<stdlib.h>

#define NUM 100
#define MAXDEP 30
#define FALSE 0
#define TRUE 1

int integer(int dep, int k, int n, int m);
int change(int n, int f);

int main(){
    int n, m, i, k = 0;
    int Input[NUM][2];
    while (scanf("%d%d", &n, &m) != EOF && (n + m) != 0){
        Input[k][0] = n;
        Input[k][1] = m;
        k++;
    }
    for (i = 0; i < k; i++){
        int s = 1;
        n = Input[i][0];
        m = Input[i][1];
        while (!integer(1, s, n, m)){
            s++;
            if (s > MAXDEP) break;
        }
        printf("%d\n", s);
    }
    return 0;
}
int integer(int dep, int k, int n, int m){
     if (dep > k) return FALSE;
     for (int i = 0; i < 2; i++){
         int nc = change(n, i);
         if (nc == m || integer(dep + 1, k, nc, m))
            return TRUE;
     }
     return FALSE;
}
int change(int n, int f){
    if (f == 0) return n / 2;
    else return n * 3;
}