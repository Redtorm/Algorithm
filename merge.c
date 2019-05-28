#include<stdio.h>

#define NUM 100
#define SIZE 1000

void quicksort(int A[], int i, int j);
void swap(int A[], int i ,int j);

void main(void){
	int n,k = 0;
	int data[NUM][SIZE];
	int num[NUM][2];
	while(scanf("%d", &n) != EOF && n != 0){
		for (int i = 0; i < n; i++) scanf("%d", &data[k][i]);
		num[k][0] = n;
		k++;
	}
	for (int i = 0; i < k; i++){
		int sumin = 0, sumax = 0;
		quicksort(data[i], 0, num[i][0] - 1);
		int tempone = data[i][0];
		int temptwo = data[i][num[i][0] - 1];
		for (int j = 1; j < num[i][0]; j++){
			temptwo = temptwo + data[i][num[i][0] - 1 - j];
			sumax = temptwo + sumax - 1;
		}
		for (int j = 1; j < num[i][0]; j++){
			tempone = tempone + data[i][j];
			sumin = tempone + sumin - 1;
			if (tempone > data[i][j + 1]){
				data[i][j] = tempone;
				quicksort(data[i], j, num[i][0] - 1);
				tempone = data[i][j];
			}
		}
		num[i][0] = sumax;
		num[i][1] = sumin;
	}
	for(int i = 0; i < k; i++) printf("%d %d\n", num[i][0], num[i][1]);
	return 0;
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