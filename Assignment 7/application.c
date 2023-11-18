#include "queue.h"

queue_t queue;
int main()
{
    unsigned int option = 0;
    unsigned int number = 0;

    /* Queue Initialization */
    queue.maxNum = 5;
    queue.queueArray = (int *)malloc(queue.maxNum * sizeof(int));
    queue.elementsNumber = 0;
    queue.dequeueIndex = -1;
    queue.enqueueIndex = -1;

    while (1)
    {
        system("cls");
        printf("\t\tQueue Assignment\n\n");
        printf("Choose an option:\n");
        printf("Enqueue an element => 1\n");
        printf("Dequeue an element => 2\n");
        printf("Get the number of element in queue => 3\n");
        printf("Get the First and Last  Elements => 4\n");
        printf("Print queue => 5\n");
        printf("Exit => 6\n");
        printf("Option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            system("cls");
            printf("\tOption 1 : Enqueue an element\n");
            printf("Enter a number : ");
            scanf("%d", &number);
            Enqueue(&queue, number);
            printf("The number is Enqueued successfully\n\n");
            Sleep(2000);
            break;
        case 2:
            system("cls");
            printf("\tOption 2 : Dequeue an element\n");
            Dequeue(&queue);
            printf("The number is dequeued successfully\n\n");
            Sleep(2000);
            break;
        case 3:
            system("cls");
            printf("\tOption 3 : Get the number of element in queue\n");
            number = GetElementNumber(&queue);
            if (number == 1)
                printf("There is only one element in the queue\n");
            else if (number == 0)
                printf("Empty Queue !!\n");
            else
                printf("There are %d elements in the queue\n", number);
            Sleep(2000);
            break;
        case 4:
            system("cls");
            printf("\tOption 4 : Get the First and Last  Elements\n");
            QueueFirstLastElements(&queue, &number, &option);
            if (queue.elementsNumber == 0)
                printf("Empty Queue !!");
            else
                printf("First Element : %d \nLast Element : %d \n", number, option);
            Sleep(2000);
            break;
        case 5:
            system("cls");
            printf("\tOption 5 : Print queue\n");
            printf("Please Wait\n");
            Sleep(1500);
            PrintQueue(&queue);
            Sleep(2000);
            break;
        case 6:
            system("cls");
            exit(1);
            break;
        default:
            break;
        }
    }
    return 0;
}