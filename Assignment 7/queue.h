#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct queue queue_t;
struct queue
{
    int *queueArray;
    int enqueueIndex;
    int dequeueIndex;
    unsigned int elementsNumber;
    unsigned int maxNum;
};

void QueueInit(queue_t *);
void Enqueue(queue_t *, int);
int Dequeue(queue_t *);
unsigned int GetElementNumber(queue_t *);
void PrintQueue(queue_t*);
void QueueFirstLastElements(queue_t*, int*, int*);
#endif