#include <stdio.h>
#include <stdlib.h>
#define INT_MIN -1

// A linked list node
typedef struct ll_t
{
	int data;		// integer data
	struct ll_t* next;	// pointer to the next node
}ll;

typedef struct Queue_t{
    ll *front;
    ll *tail;
    int size;
}Queue;

//ADT api's
Queue *createQueue();
void Enqueue(Queue *Q, int val);
int Dequeue(Queue *Q);
int size(Queue *Q);
int isEmpty(Queue *Q);
void printQueue(Queue *Q);



//Problem API's
