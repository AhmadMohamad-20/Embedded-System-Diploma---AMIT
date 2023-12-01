#include "sdbapp.h"

void SDB_APP()
{
    uint8 choice = 0;
    system("cls");
    printf("\t\t Welcome to Student Management System V2 \n");
    stdArrInit();
    coursesArrInit();
    Sleep(2000);
    while (1)
    {
        system("cls");
        printf("\n Add Entry                =>         (1)");
        printf("\n Get used Size            =>         (2)");
        printf("\n Read student data        =>         (3)");
        printf("\n Get the list of all students IDs => (4)");
        printf("\n Check ID                 =>         (5)");
        printf("\n Delete student data      =>         (6)");
        printf("\n Check Full list          =>         (7)");
        printf("\n Exit                     =>         (0)");
        printf("\n\nEnter an option : ");
        scanf("%u", &choice);
        fflush(stdin);
        SDB_action(choice);
    }
}
void SDB_action(uint8 choice)
{
    bool retVal = false;
    uint8 counter = 0;
    uint8 l_counter = 0;
    uint32 ID = 0;
    uint32 *ID_arr = (uint32 *)malloc(MAXNUM * sizeof(uint32));

    switch (choice)
    {
    case 1:
        system("cls");
        printf("Choice (1) :\n");
        retVal = SDB_AddEntry();
        if (retVal == true)
            printf("\n the operation is completed\n");
        break;
    case 2:
        system("cls");
        printf("Choice (2) :\n");
        counter = SDB_GetUsedSize();
        if (counter == 0)
            printf("\n\nEmpty List !! \n");
        else
        {
            if (counter == 1)
                printf("There is one element in the list");
            else
                printf("There are %u elements in the list", counter);
        }
        break;
    case 3:
        system("cls");
        printf("Choice (3) :\n");
        printf("\n enter ID : ");
        scanf("%u", &ID);
        SDB_ReadEntry(ID);
        break;
    case 4:
        system("cls");
        printf("Choice (4) :\n");
        if (0 == SDB_GetUsedSize())
            printf("Empty List !!!");
        else
        {
            SDB_GetList(&counter, ID_arr);
            ID_arr = realloc(ID_arr, counter * sizeof(uint32));
            printf("The List of IDs => ");
            for (l_counter = 0; l_counter < counter; l_counter++)
            {
                printf("%u  ", ID_arr[l_counter]);
            }
        }
        break;
    case 5:
        system("cls");
        printf("Choice (5) :\n");
        printf("\n enter ID : ");
        scanf("%u", &ID);
        retVal = SDB_IsIdExist(ID, &counter);
        if (retVal == true)
            printf("The ID exist in the List !!");
        else
            printf("The ID you searched doesn't exist in the list !!");
        break;
    case 6:
        system("cls");
        printf("Choice (6) :\n");
        printf("\n enter ID : ");
        scanf("%u", &ID);
        SDB_DeleteEntry(ID);
        break;
    case 7:
        system("cls");
        printf("Choice (7) :\n");
        retVal = SDB_IsFull();
        if (retVal == true)
            printf("Full List !!");
        else
            printf("The List is not full");
        break;
    case 0:
        exit(1);
        break;
    default:
        break;
    }
    Sleep(2000);
}