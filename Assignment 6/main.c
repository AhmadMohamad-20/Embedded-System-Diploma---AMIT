
#include "linkedlist.h"

extern node_t *head;
extern node_t *temp;
int main()
{
    uint8 option = 0;
    uint8 number = 0;
    uint8 position = 0;
    while (1)
    {
        system("cls");
        printf("\t\tLinKed List Assignment\n\n");
        printf("Choose an option:\n");
        printf("Push an element => 1\n");
        printf("Append an element => 2\n");
        printf("Insert an element in a certain position => 3\n");
        printf("Delete an element => 4\n");
        printf("Reverse a list => 5\n");
        printf("Print List => 6\n");
        printf("Print Reversed List => 7\n");
        printf("Exit => 8\n");
        printf("Option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            system("cls");
            printf("\tOption 1 : Push an element\n");
            printf("Enter a number : ");
            scanf("%d", &number);
            Push(number);
            printf("The number is added to the list successfully\n\n");
            Sleep(2000);
            break;
        case 2:
            system("cls");
            printf("\tOption 2 : Append an element\n");
            printf("Enter a number : ");
            scanf("%d", &number);
            Append(number);
            printf("The number is added to the list successfully\n\n");
            Sleep(2000);
            break;
        case 3:
            system("cls");
            printf("\tOption 3 : Insert an element in a certain position\n");
            printf("Enter a number : ");
            scanf("%d", &number);
            printf("Enter the Number position : ");
            scanf("%d", &position);
            Insert(number, position);
            printf("The number is added to the list successfully\n\n");
            Sleep(2000);
            break;
        case 4:
            system("cls");
            printf("\tOption 4 : Delete an element\n");
            printf("Enter the Number position : ");
            scanf("%d", &position);
            Delete(position);
            printf("The number is deleted successfully\n\n");
            Sleep(2000);
            break;
        case 5:
            system("cls");
            printf("\tOption 5 : Reverse a list\n");
            printf("Please Wait\n");
            Sleep(2000);
            ReverseList();
            printf("The list is reversed successfully\n\n");
            Sleep(2000);
            break;
        case 6:
            system("cls");
            printf("\tOption 6 : Print a list\n");
            printf("Please Wait\n");
            Sleep(2000);
            printf("The List => ");
            PrintList();            
            Sleep(2000);
            break;
        case 7:
            system("cls");
            printf("\tOption 6 : Print a reversed list\n");
            printf("Please Wait\n");
            Sleep(2000);
            printf("The Reversed List => ");
            PrintReversed();          
            Sleep(2000);
            break;
        case 8:
            exit(1);
            break;
        default:
            break;
        }
    }
    return 0;
}