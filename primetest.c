#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef unsigned int Uint;
void mod(Uint a, Uint p, Uint n, Uint *result, _Bool *composite);
_Bool isPrime(Uint n, Uint k);

int main(){
    Uint n;
    while (scanf("%d", &n) != EOF && n != 0){
        if (isPrime(n, 100)) printf("YES!\n");
        else printf("NO!\n");
    }
    return 0;
}

_Bool isPrime(Uint n, Uint k){
    if (n == 3 || n == 2) return true;
    Uint a;
    Uint *result = (Uint *)malloc(sizeof(Uint));
    _Bool *composite = (_Bool *)malloc(sizeof(_Bool));
    *composite = false;
    for (int i = 0; i < k; i++){
        a = rand() % (n - 3) + 2;
        mod(a, n - 1, n, result, composite);
        if ((*composite) || (*result != 1)) return false;
    }
    return true;
}
void mod(Uint a, Uint p, Uint n, Uint *result, _Bool *composite){
    Uint *x = (Uint *)malloc(sizeof(Uint));
    if (p == 0) *result = 1;
    else{
        mod(a, p / 2, n, x, composite);
        *result = ((*x) * (*x)) % n;
        if ((*result == 1) && (*x != 1) && (*x != n - 1)) *composite = true;
        if (p % 2 == 1) *result = (*result * a) % n;
    }
}