#include<stdio.h>
#include<stdlib.h>

#define NUM 100
#define ORDERNUM 30
#define TRUE 1
#define FALSE 0

int computeMax(int k, int n, int m, int t);
int computeValue(int n, int m, int num);
int check(int *A, int n, int m);

struct Order{
    int start;
    int end;
    int num;
} OrderSet[NUM][ORDERNUM];
typedef struct Node{
    int value;
    int level;
    int *TrainState;
    struct Node *next;
}NODE, *PNODE;
typedef struct Queue{
    PNODE front, rear;
}QUEUE, *PQUEUE;

void InitQueue(PQUEUE);
int IsEmptyQueue(PQUEUE);
void InsertQueue(PQUEUE, PNODE); 
PNODE DeleteQueue(PQUEUE);
void DestroyQueue(PQUEUE);


int main(void){
    int n, m, t, i, j, k = 0;
    int Input[NUM][3];
    while(scanf("%d%d%d", &n, &m, &t) != EOF && (m + n + t) != 0){
        Input[k][0] = n;
        Input[k][1] = m;
        Input[k][2] = t;
        j = t;
        for (i = 0; i < j; i++){
            scanf("%d%d%d", &n, &m, &t);
            OrderSet[k][i].start = n;
            OrderSet[k][i].end = m;
            OrderSet[k][i].num = t;
        }
        k++;
    }
    for (i = 0; i < k; i++){
        n = Input[i][0];
        m = Input[i][1];
        t = Input[i][2];
        Input[i][0] = computeMax(i, n, m, t);
    }
    for (i = 0; i < k; i++) printf("%d\n", Input[i][0]);
    return 0;
}
int computeValue(int n, int m, int num){
    return (m - n) * num;
}
int computeMax(int k, int n, int m, int t){
    PQUEUE Queue = (PQUEUE)malloc(sizeof(QUEUE));
    InitQueue(Queue);
    int *State = (int *)malloc((m + 1) * sizeof(int));
    int maxValue = 0;
    for (int i = 0; i <= m; i++) State[i] = 0;
    PNODE tempnode = (PNODE)malloc(sizeof(NODE));
    PNODE newnode1 =(PNODE)malloc(sizeof(NODE));
    PNODE newnode2 = (PNODE)malloc(sizeof(NODE));
    tempnode->level = 0;
    tempnode->TrainState = State;
    tempnode->value = 0;
    tempnode->next = NULL;
    InsertQueue(Queue, tempnode);
    while (!IsEmptyQueue(Queue)){
        tempnode = DeleteQueue(Queue);
        int e = tempnode->level;
        if (e < t){
            newnode1 = (PNODE)malloc(sizeof(NODE));
            newnode2 = (PNODE)malloc(sizeof(NODE));
            int *LastState = tempnode->TrainState;
            int *NewState = (int *)malloc((m + 1) * sizeof(int));
            int start = OrderSet[k][e].start;
            int end = OrderSet[k][e].end;
            int num = OrderSet[k][e].num;
            for (int i = 0; i <= m; i++) NewState[i] = LastState[i];
            for (int i = start; i < end; i++) NewState[i] += num;
            newnode1->TrainState = NewState;
            newnode1->level = e + 1;
            newnode1->value = tempnode->value + computeValue(start, end, num);
            if (check(NewState, m + 1, n)) InsertQueue(Queue, newnode1);
            else free(newnode1);
            newnode2->level = e + 1;
            newnode2->TrainState = LastState;
            newnode2->value = tempnode->value;
            InsertQueue(Queue, newnode2);
        }
        else{
            if (tempnode->value > maxValue) maxValue = tempnode->value;
        }
    }
    return maxValue;
}
int check(int *A, int n, int m){
    int i;
    for (i = 0; i < n; i++){
        if (A[i] > m) break;
    }
    if (i < n) return FALSE;
    else return TRUE;
}

void InitQueue(PQUEUE Queue){
    Queue->front = Queue->rear = (PNODE)malloc(sizeof(NODE));
    if (Queue->front == NULL) exit(-1);
}
int IsEmptyQueue(PQUEUE Queue){
    if (Queue->front == Queue->rear) return TRUE;
    else return FALSE;
}
void InsertQueue(PQUEUE Queue, PNODE newnode){
        Queue->rear->next = newnode;
        Queue->rear = newnode;
        newnode->next = NULL;
}
PNODE DeleteQueue(PQUEUE Queue){
    PNODE dnode = Queue->front->next;
    Queue->front = Queue->front->next;
    return dnode;
}
