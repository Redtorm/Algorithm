#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
#define INF 999999

typedef struct Node{
	int serialNum;
	float distance;
}HeapNode, *PHeapNode;
typedef struct Heap{
	PHeapNode *HeapArray;
	int maxSize;
	int length;
}MinHeap, *PMinHeap;

void InitHeap(PMinHeap minHeap, int maxSize);
int CheckHeap(PMinHeap minHeap);
void ClearHeap(PMinHeap minHeap);
void InsertHeap(PMinHeap minHeap, PHeapNode NewNode);
void ShiftDown(PMinHeap minHeap, int i);
PHeapNode DeleteMin(PMinHeap minHeap);
float find(int (*coor)[2], int m);
float **compute(int (*coor)[2], int m);

int main(void){
	int i, m, k = 0;
	while (scanf("%d", &m) != EOF && m != 0){
		int (*coor)[2] = (int (*)[2])malloc(m * 2 * sizeof(int));
		for (i = 0; i < m; i++){
			scanf("%d", *(coor + i));
			scanf("%d", *(coor + i) + 1);
		}
		printf("%.3f\n", find(coor, m));
	}
    return 0;
}

float find(int (*coor)[2], int m){
	int i;
	float **c = compute(coor, m);
	float *dist = (float *)malloc(m * sizeof(float));
	for (i = 0; i < m; i++) dist[i] = INF;
	PMinHeap minHeap = (PMinHeap)malloc(sizeof(MinHeap));
	InitHeap(minHeap, MAXSIZE);
	PHeapNode source = (PHeapNode)malloc(sizeof(HeapNode));
	source->serialNum = 0;
	source->distance = 0;
	dist[0] = 0;
	InsertHeap(minHeap, source);
	while (!CheckHeap(minHeap)){
		PHeapNode cur = DeleteMin(minHeap);
		for (i = 0; i < m; i++){
			if (i == cur->serialNum) continue;
			float max;
			if (c[cur->serialNum][i] > cur->distance) max = c[cur->serialNum][i];
			else max = cur->distance;
			if (max < dist[i]){
				dist[i] = max;
				PHeapNode liveNode = (PHeapNode)malloc(sizeof(HeapNode));
				liveNode->serialNum = i;
				liveNode->distance = dist[i];
				InsertHeap(minHeap, liveNode);
			}
		}
		free(cur);
	}
	return dist[1];
}
float **compute(int (*coor)[2], int m){
	int i, j;
	float **c = (float **)malloc(m * sizeof(float *));
	for (i = 0; i < m; i++) *(c + i) = (float *)malloc(m * sizeof(float));
	for (i = 0; i < m; i++)
		for (j = 0; j < m; j++){
			int dx = (*(coor + i))[0] - (*(coor + j))[0];
			int dy = (*(coor + i))[1] - (*(coor + j))[1];
			c[i][j] = sqrt(dx * dx + dy * dy);
		}
	return c;
}

void InitHeap(PMinHeap minHeap, int maxSize){
	minHeap->HeapArray = (PHeapNode *)malloc(maxSize * sizeof(PHeapNode));
	if (minHeap->HeapArray == NULL) exit(-1);
	minHeap->maxSize = maxSize;
	minHeap->length = 0;
}
int CheckHeap(PMinHeap minHeap){
	if (minHeap->length == 0) return TRUE;
	else return FALSE;
}
void ClearHeap(PMinHeap minHeap){
	if (minHeap != NULL){
		minHeap->length = 0;
	}
}
void InsertHeap(PMinHeap minHeap, PHeapNode NewNode){
	int i, j;
	if (minHeap->length == minHeap->maxSize){
		minHeap->HeapArray = (PHeapNode *)realloc(minHeap->HeapArray, 2 * minHeap->maxSize * sizeof(PHeapNode));
		minHeap->maxSize *= 2;
	}
	minHeap->HeapArray[minHeap->length] = NewNode;
	minHeap->length++;
	i = minHeap->length - 1;
	while (i != 0){
		j = (i - 1) / 2;
		if (NewNode->distance > minHeap->HeapArray[j]->distance) break;
        PHeapNode temp = minHeap->HeapArray[i];
		minHeap->HeapArray[i] = minHeap->HeapArray[j];
        minHeap->HeapArray[j] = temp;
		i = j;
	}
}
void ShiftDown(PMinHeap minHeap, int i){
	int m = minHeap->length / 2;
	while (i < m){
		int r = 2 * i + 2;
		int l = 2 * i + 1;
		if ((r < minHeap->length) &&  (minHeap->HeapArray[r]->distance <  minHeap->HeapArray[l]->distance))
			l = r;
		if (minHeap->HeapArray[i]->distance < minHeap->HeapArray[l]->distance) return;
		PHeapNode temp = minHeap->HeapArray[i];
		minHeap->HeapArray[i] = minHeap->HeapArray[l];
		minHeap->HeapArray[l] = temp;
		i = l;
	}
}
PHeapNode DeleteMin(PMinHeap minHeap){
	int m = minHeap->length - 1;
	PHeapNode temp = minHeap->HeapArray[0];
	minHeap->HeapArray[0] = minHeap->HeapArray[m];
	if (m != 0) ShiftDown(minHeap, 0);
	minHeap->length--;
	return temp;
}