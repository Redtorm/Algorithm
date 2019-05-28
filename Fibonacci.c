#include<stdio.h>

int fibonacci(int n);

int main(void){
	int a;
	int i = 0,j = 0,f = 0;
	int store[1000] = {0};
	while ((scanf("%d", &a) != EOF) && (a != 0)){
		store[i] = a;
		i++;
    }
	for (j = 0; j < 1000; j++){
		if (store[j] == 0) break;
		f = fibonacci(store[j]);
		printf("%d\n", f);
	}
	return 0; 
}

int fibonacci(int n){
	int matrixoe[2] = {0, 1};
	int matrixtw[4] = {0, 1, 1, 1};
	int matrixth[4] = {1, 0, 1, 0};
	int matrixtemp[4] = {0, 1, 1, 1};
	while (n > 0){
		if (n % 2 == 1){
			matrixtemp[0] = (matrixth[0] * matrixtw[0] + matrixth[1] * matrixtw[2]) % 1997;
			matrixtemp[1] = (matrixth[0] * matrixtw[1] + matrixth[1] * matrixtw[3]) % 1997;
			matrixtemp[2] = (matrixth[2] * matrixtw[0] + matrixth[3] * matrixtw[2]) % 1997;
			matrixtemp[3] = (matrixth[2] * matrixtw[1] + matrixth[3] * matrixtw[3]) % 1997;
			for(int i = 0; i < 4; i++) matrixth[i] = matrixtemp[i];
		}
		n = n / 2;
		matrixtemp[0] = (matrixtw[0] * matrixtw[0] + matrixtw[1] * matrixtw[2]) % 1997;
		matrixtemp[1] = (matrixtw[0] * matrixtw[1] + matrixtw[1] * matrixtw[3]) % 1997;
		matrixtemp[2] = (matrixtw[2] * matrixtw[0] + matrixtw[3] * matrixtw[2]) % 1997;
		matrixtemp[3] = (matrixtw[2] * matrixtw[1] + matrixtw[3] * matrixtw[3]) % 1997;
		for(int i = 0; i < 4; i++) matrixtw[i] = matrixtemp[i];
	}
	return matrixth[1];
}
/*
long long fibonacci(int n){
	long long sum = 1, temp1 = 1,temp2 = 1;
	for(int i = 3; i <= n; i++){
		temp1 = temp2;
		temp2 = sum;
		sum = temp1 + temp2;
	}
	return sum;
}
*/