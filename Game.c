#include<stdio.h>

#define mMax 100
#define nMax 100
#define NUM 100
#define false 0
#define true 1

struct card{
    int num;
    int ismy;
    int issmall;
}CardSet[nMax * nMax];

int main(void){
    int m, n, i, j, l, k = 0;
    int Record[NUM][2], MyCard[NUM][nMax];
    while (scanf("%d%d", &m, &n) != EOF && m + n != 0){
        for (i = 0; i < n; i++) 
            scanf("%d", &MyCard[k][i]);
        k++;
        Record[k][0] = m;
        Record[k][1] = n;
    }
    printf("%d\n", MyCard[0][0]);
    printf("%d\n", MyCard[0][1]);
    printf("%d\n", MyCard[0][2]);2
    for (i = 0; i < k; i++){
        m = Record[i][0];
        n = Record[i][1];
        for (j = 0; j < n * m; j++){
            CardSet[j].num =  j + 1;
            CardSet[j].ismy = false;
            CardSet[j].issmall = false;
        }
        for (j = 0; j < n; j++) CardSet[MyCard[i][j]].ismy = true;
        int ans = n;
        for (j = n * m - 1; i >=1 && ans > 0; i--)
            if (!CardSet[j].ismy)
                for (l = i - 1; l >= 0; l--)
                    if(CardSet[l].ismy && !CardSet[l].issmall){
                        CardSet[j].issmall = true;
                        ans--;
                        break;
                    }
        Record[i][0] = ans;
    }
    for (i = 0; i < k; i++) printf("%d\n", Record[i][0]);
    return 0;
}