#include<stdio.h>

void swap(int A[], int i, int j);
void quicksort(int A[], int i, int j);

int main(void){
	int n,x,y;
	int sum = 0;
	scanf("%d", &n);
	int Location[10];
	for (int i = 0; i < n; i++){
		scanf("%d%d", &x, &y);
		Location[i] = y;
	}	
	quicksort(Location, 0, n - 1);
	for (int i = 0; i < n / 2; i++){
		sum += Location[n / 2] - Location[i];
	}
	for (int i = n / 2; i < n; i++){
		sum += Location[i] - Location[n /2];
	}
	printf("%d",sum);
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