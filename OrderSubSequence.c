#include<stdio.h>

#define NUM 100
#define SIZE 2000

void swap(int A[], int i, int j);
void quicksort(int A[], int i, int j);
int deleteRepe(int A[], int n);
int findsqu(int A[], int B[], int a, int b);

int main(void){
	int n, k = 0;
	int squence[NUM][SIZE];
	int len[NUM];
	while (scanf("%d", &n) != EOF && n != 0){
		for (int i = 0; i < n; i++) scanf("%d", &squence[k][i]);
		len[k] = n;
		k++;
	}
	
	for (int i = 0; i < k; i++){
		int squenceTemp[SIZE] = {0};
		for (int j = 0; j < len[i]; j++){
			squenceTemp[j] = squence[i][j];
		}
		quicksort(squenceTemp, 0, len[i] - 1);
		int m = deleteRepe(squenceTemp, len[i]);
		len[i] = findsqu(squence[i], squenceTemp, len[i] ,m);
	}
	
	for (int i = 0; i < k; i++) printf("%d\n", len[i]);
	
}

void quicksort(int A[], int i, int j){
	if(j <= i) return;
	int pivotindex = (j + i) / 2;
	swap(A, pivotindex, j);
	int l = i - 1;
	int r = j;
	int pivot = A[j];
	do{
		while (A[++l] < pivot);
		while ((l < r) && (pivot < A[--r]));
		swap(A, l, r);
	}while (l < r);
	swap(A,l,j);
	quicksort(A, i, l - 1);
	quicksort(A, l + 1, j);
}
void swap(int A[], int i ,int j){
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
int findsqu(int A[], int B[], int a, int b){
	int design[a][b];
	if (A[0] == B[0]) design[0][0] = 1;
	else design[0][0] = 0;
	for (int j = 1; j < b; j++){
		if(B[j] == A[0]) design[0][j] = 1;
		else design[0][j] = design[0][j - 1];
	}
	for (int i = 1; i < a; i++){
		if(A[i] == B[0]) design[i][0] = 1;
		else design[i][0] = design[i - 1][0];
	}
	for (int i = 1; i < a; i++){
		for (int j = 1; j < b; j++){
			if (A[i] == B[j]) design[i][j] = design[i - 1][j - 1] + 1;
			else{
				if(design[i - 1][j] > design[i][j - 1]) design[i][j] = design[i - 1][j];
				else design[i][j] = design[i][j - 1];
			}
		}
	}
	return design[a - 1][b - 1];
}
int deleteRepe(int A[], int n){
	int i,j;
	for (i = 0, j = 1; j < n; j++)
		if(A[i] != A[j]) A[++i] = A[j];
	return i;
}
/*
int deleteRepe(int A[], int n){
	for(int i = 1; i < n; i++){
		if(A[i] == A[i - 1]){
			for (int j = i; j < n; j++) A[j] = A[j + 1];
			n--;
			i = 1;
		}
	}
	return n;
}*/
/*for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
			design[a][b] = 0;*/