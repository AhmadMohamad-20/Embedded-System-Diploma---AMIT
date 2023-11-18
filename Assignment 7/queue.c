#include "queue.h"

void QueueInit(queue_t *queue)
{
    queue->maxNum = 1;
    queue->queueArray = (int*)malloc(queue->maxNum *sizeof(int));
    queue->elementsNumber = 0;
    queue->dequeueIndex = -1;
    queue->enqueueIndex = -1;    
}

void Enqueue(queue_t *queue, int num)
{
    int temp = 0;
    if (NULL != queue)
    {
        if (queue->elementsNumber == (queue->maxNum))
        {
            // temp = queue->queueArray[queue->dequeueIndex];
            queue->maxNum *= 2;
            realloc((queue->queueArray), (queue->maxNum) * sizeof(int));

            // queue->queueArray[queue->dequeueIndex] = temp;
        }
        if ((queue->enqueueIndex == -1))
        {
            (queue->enqueueIndex)++;
            queue->queueArray[queue->enqueueIndex] = num;
            (queue->dequeueIndex)++;
            (queue->elementsNumber)++;
        }
        else
        {
            if (!((queue->enqueueIndex != 0) && (queue->dequeueIndex == (queue->maxNum - 1))))
            {
                (queue->dequeueIndex)++;
                queue->queueArray[queue->dequeueIndex] = num;
                (queue->elementsNumber)++;
            }
            else
            {
                queue->dequeueIndex = 0;
                queue->queueArray[queue->dequeueIndex] = num;
                (queue->elementsNumber)++;
            }
        }
    }

    else
    { /*Nothing*/
    }
}

int Dequeue(queue_t *queue)
{
    int temp = 404;
    if (NULL != queue)
    {
        if ((queue->enqueueIndex != -1))
        {
            temp = queue->queueArray[queue->enqueueIndex];
            queue->elementsNumber--;
            if (0 == queue->elementsNumber)
            {
                queue->enqueueIndex = -1;
                queue->dequeueIndex = -1;
            }
            if ((queue->enqueueIndex) == (queue->maxNum) - 1)
                queue->enqueueIndex = 0;

            else
                (queue->enqueueIndex)++;
        }
        else
        { /*Nothing*/
        }
    }
    else
    { /*Nothing*/
    }
    return temp;
}

unsigned int GetElementNumber(queue_t *queue)
{
    return (queue->elementsNumber);
}

void PrintQueue(queue_t *queue)
{
    int l_counter = 0;
    unsigned int l_index = queue->enqueueIndex;
    printf("The queue : ");
    for (l_counter = 0; l_counter < (queue->elementsNumber); l_counter++)
    {
        printf("%d ", queue->queueArray[l_index]);
        if (l_index == (queue->maxNum - 1))
            l_index = 0;
        else
            l_index++;
    }
}

void QueueFirstLastElements(queue_t *queue, int *firstElement, int *lastElement)
{
    *firstElement = queue->queueArray[queue->enqueueIndex];
    *lastElement = queue->queueArray[queue->dequeueIndex];
}