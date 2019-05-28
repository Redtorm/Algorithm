#include<stdio.h>

#define NUM 100
#define HEAP 100

int main(void){
	int n, k = 0;
	int stoneheap[NUM][HEAP];
	int heapnum[NUM][2];
	while (scanf("%d", &n) != EOF && n != 0){
		for (int i = 0; i < n; i++) scanf("%d", &stoneheap[k][i]);
		heapnum[k][0] = n;
		k++;
	}
	
	for (int order = 0; order < k; order++){
		int temp =heapnum[order][0];
		int design[temp][temp];
		int designx[temp][temp];
		for (int i = 0; i < temp; i++){
			for (int j = 0; j < temp; j++){
				design[i][j] = 0;
				designx[i][j] = 0;
			}	
		}	
		for (int len = 2; len <= temp; len++){
			for (int start = 0; start < temp; start++){
				int sum = 0;
				for (int i = 0; i < len; i++) sum += stoneheap[order][(start + i) % temp];	
				designx[start][(start + len -1 ) % temp] = sum + designx[(start + 1 + temp) % temp][(start + len - 1) % temp];
				for (int l = start; l <= start + len - 1; l++){
					int mid = designx[start][l % temp] + designx[(l + 1) % temp][(start + len - 1) % temp] + sum;
					if (mid < designx[start][(start + len -1 ) % temp]) designx[start][(start + len -1 ) % temp] = mid;
				}
				design[start][(start + len -1 ) % temp] = sum + design[(start + 1 + temp) % temp][(start + len - 1) % temp];
				for (int l = start; l < start + len - 1; l++){
					int mid = design[start][l % temp] + design[(l + 1) % temp][(start + len - 1) % temp] + sum;
					if (mid > design[start][(start + len -1 ) % temp]) design[start][(start + len -1 ) % temp] = mid;
				}		
			}
		}
		int choosemax = 0;
		int choosemin = 100000;
		for (int i = 0; i < temp; i++){
			if (design[i][(i + temp - 1) % temp] > choosemax) choosemax = design[i][(i + temp - 1) % temp];
			if (designx[i][(i + temp - 1) % temp] < choosemin) choosemin = designx[i][(i + temp - 1) % temp];
		}
		heapnum[order][0] = choosemin;
		heapnum[order][1] = choosemax;	
	}
	for (int i = 0; i < k; i++){
		printf("%d %d\n", heapnum[i][0], heapnum[i][1]);
	}
	return 0;
}

//if (design[(start + 1 + temp) % temp][(start + len - 1) % temp] > design[start][(start + len - 2) % temp])
					//design[start][(start + len -1 ) % temp] = sum + design[(start + 1 + temp) % temp][(start + len - 1) % temp];
				//else design[start][(start + len - 1) % temp] = sum + design[start][(start + len - 2) % temp];
				//printf("%d\n",design[start][(start + len) % temp]);
				//printf("%d",w);
		//printf("%d\n",design[0][0]);
		//printf("%d\n",design[0][1]);
		//printf("%d\n",design[0][2]);
		//if (designx[(start + 1 + temp) % temp][(start + len - 1) % temp] < designx[start][(start + len - 2) % temp])
				//	designx[start][(start + len -1 ) % temp] = sum + designx[(start + 1 + temp) % temp][(start + len - 1) % temp];
				//else designx[start][(start + len - 1) % temp] = sum + designx[start][(start + len - 2) % temp];