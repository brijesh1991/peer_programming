#include "Queue.h"

Queue *createQueue() {
    Queue *node= (Queue *)calloc(1,sizeof(Queue));
    node->front =NULL;
    node->tail= NULL;
    node->size=0;
    return node;
}

void Enqueue(Queue *Q, int val){
    ll *node =(ll *)calloc(1,sizeof(ll));
    node->data= val;
    node->next = NULL;

    if(Q->tail != NULL){
        Q->tail->next = node;
    }
    Q->tail=node;

    if(Q->front == NULL)
        Q->front = Q->tail;
    Q->size+=1;
    return;
}


int Dequeue(Queue *Q){
    int val=0;

    if (isEmpty(Q)){
        printf("EmptyQ\n");
        return -1;
    }

    val = Q->front->data;
    ll *temp =Q->front;
    Q->front = Q->front->next;
    Q->size-=1;
    free(temp);
    return val;
}

int size(Queue *Q) {
    return Q->size;
}

int isEmpty(Queue *Q) {
    if (Q->front == NULL)
        return 1;
    else
        return 0;
}

void printQueue(Queue *Q) {
    ll *node= Q->front;
    while(node){
        printf("%3d\t",node->data);
        node=node->next;
    }
    printf("\n");
}