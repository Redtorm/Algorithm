#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define NUM 30
#define LENGTH 50
#define TRUE 1
#define FALSE 0

typedef struct LNODE{
    int level;
    _Bool *flag;
    float result;
    struct LNODE *next;
}LinkNode, *PLinkNode;
typedef struct LList{
    PLinkNode head;
    PLinkNode rear;
}LinkList, *PLinkList;

void InitList(PLinkList Queue);
void InsertRear(PLinkList Queue, PLinkNode NewNode);
int IsEmpty(PLinkList Queue);
PLinkNode DeleteHead(PLinkList Queue);

int search(int n, int m, int *Number);

int main(void){
    int i, n, m, k = 0;
    int Input[NUM][2], NumberSet[NUM][LENGTH];
    while (scanf("%d%d", &n, &m) != EOF && m + n !=0){
        Input[k][0] = n;
        Input[k][1] = m;
        for (i = 0; i < n; i++) scanf("%d", &NumberSet[k][i]);
        k++;
    }
    for (i = 0; i < k; i++){
        n = Input[i][0];
        m = Input[i][1];
        int min = search(n, m, NumberSet[i]);
        if(min == -1) printf("No Solution!\n");//No Solution!
        else printf("%d\n", min);
    }
    return 0;
}

int search(int n, int m, int *Number){
    int i, j, r = 0;
    PLinkList Queue = (PLinkList)malloc(sizeof(LinkList));
    InitList(Queue);
    for (i = 0; i < n; i++){
       if (Number[i] == m) return 0;
       PLinkNode Node = (PLinkNode)malloc(sizeof(LinkNode));
       _Bool *Frag = (_Bool *)malloc(n * sizeof(_Bool));
       for (j = 0; j < n; j++) Frag[j] = 0;
       Frag[i] = 1;
       Node->flag = Frag;
       Node->level = 0;
       Node->result = Number[i];
       InsertRear(Queue, Node);
    }
    while (!IsEmpty(Queue)){
        PLinkNode temp = DeleteHead(Queue);
        if (temp->level < n  ){
            for (i = 0; i < n; i++){
                _Bool *Frag = temp->flag; 
                if (!Frag[i]){
                    for (j = 0; j < 4; j++){
                        PLinkNode NewNode = (PLinkNode)malloc(sizeof(LinkNode));
                        switch (j){
                            case 0: NewNode->result = temp->result + Number[i];break;
                            case 1: NewNode->result = temp->result - Number[i];break;
                            case 2: NewNode->result = temp->result * Number[i];break;
                            case 3: NewNode->result = temp->result / Number[i];break;
                            default: break;
                        }
                        if(NewNode->result == m) {
                            free(NewNode);
                            return temp->level + 1;
                        } 
                        _Bool *newFrag = (_Bool *)malloc(n * sizeof(_Bool));
                        for (r = 0; r < n; r++) newFrag[r] = Frag[r];
                        newFrag[i] = 1;
                        NewNode->flag = newFrag;
                        NewNode->level = temp->level + 1;
                        InsertRear(Queue, NewNode);
                    }
                }
            }
        }
        free(temp->flag); 
        free(temp);
    }
    return -1;
}

void InitList(PLinkList Queue){
    PLinkNode HeadNode = (PLinkNode)malloc(sizeof(LinkNode));
    Queue->head = Queue->rear = HeadNode;
    if (Queue->head == NULL) exit(-1); 
}
void InsertRear(PLinkList Queue, PLinkNode NewNode){
    Queue->rear->next = NewNode;
    Queue->rear = NewNode;
    NewNode->next = NULL;
}
int IsEmpty(PLinkList Queue){
    if(Queue->head == Queue->rear) return TRUE;
    else return FALSE;
}
PLinkNode DeleteHead(PLinkList Queue){
    PLinkNode temp = (PLinkNode)malloc(sizeof(LinkNode));
    temp = Queue->head->next;
    Queue->head = Queue->head->next;
    return temp;
}

