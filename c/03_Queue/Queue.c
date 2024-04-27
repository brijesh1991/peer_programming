#include "Queue.h"

int main(){
    Queue *q1=createQueue();
    Enqueue(q1,121);
    Enqueue(q1,3);
    Enqueue(q1,6);
    Enqueue(q1,9);
    Enqueue(q1,22);
    printQueue(q1);
    Dequeue(q1);
    printQueue(q1);
    return 0;
}