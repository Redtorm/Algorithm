#include<stdio.h>

void esitimate(int m, int n);

int main(){
    int m,n,k = 0;
	int data[100][2];
	while (scanf("%d%d", &n, &m) != EOF && (n + m) != 0){
		data[k][0] = n;
		data[k][1] = m;
		k++;
	}
    for (int i = 0; i < k; i++){
		esitimate(data[i][0], data[i][1]);
	}
	return 0;
}

void esitimate(int m, int n){
	if(4 * m < n && 10 * m - 2 * n > 0)       //ssssdssssdss 
		printf("%d\n", 10 * m - 2 * n);
    else if(3 * m < 2 * n && 8 * m - 4 * n > 0) //sssddsssddss
		printf("%d\n", 8 * m - 4 * n);
    else if(2 * m < 3 * n && 6 * m - 6 * n > 0) //ssdddssdddss 
		printf("%d\n", 6 * m - 6 * n);
    else if(m < 4 * n && 3 * m - 9 * n > 0)   //sddddsddddsd
		printf("%d\n", 3 * m - 9 * n);
    else
        printf("NO\n");
}