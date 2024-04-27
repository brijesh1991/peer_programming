#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

typedef struct ll_t {
    bnode *node;
    struct ll_t *next;
}ll;

typedef struct Queue_t {
    ll *front;
    ll *tail;
    int size;
}Queue;

Queue *createQueue();
void Enqueue(Queue *Q, bnode *val);
bnode *Dequeue(Queue *Q);
int size(Queue *Q);
int isEmpty(Queue *Q);
void printQueue(Queue *Q);