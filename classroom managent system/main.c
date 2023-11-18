#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "stdtypes.h"
#include "bitmath.h"

typedef struct
{
    char firstName[15];
    char lastName[15];
    float32 GPA;
    uint8 ID;
    uint8 coursesNum;
} student_t;

student_t studentArr[50];
uint8 latestElement(student_t *studentArr);
uint8 latestElement_2(student_t *studentArr);
static uint8 checkID(student_t *studentArr, uint8 ID)
{
    int length = latestElement(studentArr);
    for (int counter = 0; counter < length; counter++)
    {
        if (ID == studentArr[counter].ID)
        {
            return ID;
        }
    }
    return 0;
}
static uint8 checkString(char *arr, const char *array)
{
    uint8 counter = 0;
    if (strlen(arr) != strlen(array))
        return 0;
    while (array[counter] != 0)
    {
        if (arr[counter] == array[counter])
        {
            counter++;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
static uint8 searchID(student_t *studentArr, uint8 ID)
{
    uint8 length = latestElement(studentArr);
    uint8 counter = 0;
    for (counter = 0; counter < length; counter++)
    {
        if (studentArr[counter].ID == ID)
        {
            return counter;
        }
    }
    return 50;
}
static void checkStringLetters(char *str)
{
    int counter = 0;
    while (((str[counter] >= 'A') && (str[counter] <= 'Z')) || ((str[counter] >= 'a') && (str[counter] <= 'z')) || (str[counter] == ' ') || (str[counter] == '-') || (str[counter] == '.'))
    {
        counter++;
    }
    str[counter] = '\0';
    return;
}
void AddNewStudent(student_t *studentArr);
void SearchByID(student_t *studentArr, uint8 ID);
void SearchByFirstName(student_t *studentArr, char *FirstName);
void SearchByCoursesNum(student_t *studentArr, uint8 coursesTaken);
void DeleteStudent(student_t *studentArr);
void modifyStudent(student_t studentArr[]);
int main()
{
    uint8 ID = 0;
    char name[10];
    uint8 courseNum = 0;
    uint8 cont = 1;
    uint8 choiceNum = 0;
    while (cont)
    {
        system("cls");
        printf("\n\t\t Class Management System\n\n");
        printf("\t\t Welcome to the system \n\n");
        printf("Please Choose an option : \n\n");
        printf("=> (1) Add the student details.\n");
        printf("=> (2) Find the student details by ID number.\n");
        printf("=> (3) Find the student details by first name.\n");
        printf("=> (4) Find the student details by number of courses taken.\n");
        printf("=> (5) Get the total students number.\n");
        printf("=> (6) Delete the student details.\n");
        printf("=> (7) update the student details.\n");
        printf("=> (8) exit the program.\n");
        printf("\n=> the Option : ");
        scanf("%d", &choiceNum);
        fflush(stdin);

        switch (choiceNum)
        {
        case 1:
            AddNewStudent(studentArr);
            printf("\athe student data is added successfully !\n\n");
            break;
        case 2:
            printf("\nEnter the ID number : ");
            scanf("%d", &ID);
            SearchByID(studentArr, ID);
            break;
        case 3:
            printf("\nEnter the First Name : ");
            gets(name);
            SearchByFirstName(studentArr, name);
            break;
        case 4:
            printf("\nEnter the number of courses taken : ");
            scanf("%d", &courseNum);
            SearchByCoursesNum(studentArr, courseNum);
            break;
        case 5:
            printf("\nthe total student number : %d .\n", latestElement(studentArr));
            break;
        case 6:
            DeleteStudent(studentArr);
            break;
        case 7:
            modifyStudent(studentArr);
            printf("\athe student data is updated successfully !");
            break;
        case 8:
            printf("Thank you for using the system.\n");
            exit(1);
            break;
        default:
            break;
        }
        if (choiceNum != 8)
        {
            printf("\n\nDo you want to continue ?  [1] => yes - [0] => no  \t  Ans : ");
            scanf("%d", &cont);
        }
    }
    return 0;
}

uint8 latestElement(student_t *studentArr)
{
    int i = 0;
    int counter = 0;
    for (i = 49; i >= 0; i--)
    {
        if (studentArr[i].ID != 0)
        {
            counter++;
        }
    }
    return counter;
}

uint8 latestElement_2(student_t *studentArr)
{
    int i = 0;
    int counter = 0;
    for (i = 49; i >= 0; i--)
    {
        if (studentArr[i].firstName[0] != '\0')
        {
            counter++;
        }
    }
    return counter;
}

void AddNewStudent(student_t *studentArr)
{
    static uint8 index = 0;
    uint8 ID = 0;
    static uint8 flag = 0;
    index = latestElement_2(studentArr);
    if (index == 50)
    {
        printf("\aError !!! the classroom reached the maximum capacity !!");
    }
    else
    {
        printf("\nEnter the student's First Name : ");
        gets(&(studentArr[index].firstName));
        checkStringLetters(&(studentArr[index].firstName));
        printf("Enter the student's Last Name : ");
        gets(&(studentArr[index].lastName));
        checkStringLetters(&(studentArr[index].lastName));
        printf("Enter the student's ID : ");
        scanf("%d", &ID);
        flag = checkID(studentArr, ID);
        while ((ID == flag) || (ID > 50) || (ID < 1))
        {
            if (ID == flag)
                printf("\aError !!! Already existing ID !! enter a different ID => ");
            else if (ID > 50)
                printf("\aError !!! ID exceeding the maximum limit (50) !! enter a different ID => ");
            else if (ID < 1)
                printf("\aError !!! ID exceeding the minimum limit (1) !! enter a different ID => ");
            else
            { /*Nothing*/
            }
            scanf("%d", &ID);
            flag = checkID(studentArr, ID);
        }
        studentArr[index].ID = ID;

        printf("Enter the student's GPA : ");
        scanf("%f", &studentArr[index].GPA);
        printf("Enter The registered number of courses : ");
        scanf("%d", &studentArr[index].coursesNum);
        printf("\n\n Thank you for the registration . \n");
    }
}

void SearchByID(student_t *studentArr, uint8 ID)
{
    uint8 length = latestElement(studentArr);
    uint8 counter = 0;
    printf("Please wait");
    for (int i = 0; i < 5; i++)
    {
        printf(" . ");
        Sleep(250);
    }
    for (counter = 0; counter < length; counter++)
    {
        if (studentArr[counter].ID == ID)
        {
            printf("\n\nthe data of student with ID %d : \n", ID);
            printf("=> First Name : %s \n", studentArr[counter].firstName);
            printf("=> Last Name : %s \n", studentArr[counter].lastName);
            printf("=> ID : %d \n", studentArr[counter].ID);
            printf("=> GPA : %0.2f \n", studentArr[counter].GPA);
            printf("=> Number of Courses Taken : %d \n", studentArr[counter].coursesNum);

            break;
        }
        else
        {
            if (counter == length - 1)
            {
                printf("\n\n\aThe ID you searched doesn't have data in the system !");
            }
            else
            {
                continue;
            }
        }
    }
}

void SearchByFirstName(student_t *studentArr, char *FirstName)
{
    uint8 length = latestElement(studentArr);
    uint8 counter = 0;
    uint8 flag = 1;
    printf("Please wait");
    for (int i = 0; i < 5; i++)
    {
        printf(" . ");
        Sleep(250);
    }
    for (counter = 0; counter < length; counter++)
    {
        if (checkString((studentArr[counter].firstName), FirstName))
        {
            printf("\n\nStudent (%d) : \n", flag);
            printf("=> First Name : %s \n", studentArr[counter].firstName);
            printf("=> Last Name : %s \n", studentArr[counter].lastName);
            printf("=> ID : %d \n", studentArr[counter].ID);
            printf("=> GPA : %0.2f \n", studentArr[counter].GPA);
            printf("=> Number of Courses Taken : %d \n\n", studentArr[counter].coursesNum);
            flag++;
        }
        else
        {
            if (counter == length - 1)
            {
                printf("\n\n\aThe First Name you searched doesn't have data in the system !");
            }
            else
            {
                continue;
            }
        }
    }
}

void SearchByCoursesNum(student_t *studentArr, uint8 coursesTaken)
{
    uint8 length = latestElement(studentArr);
    uint8 counter = 0;
    uint8 flag = 1;
    printf("Please wait");
    for (int i = 0; i < 5; i++)
    {
        printf(" . ");
        Sleep(250);
    }
    for (counter = 0; counter < length; counter++)
    {
        if (studentArr[counter].coursesNum == coursesTaken)
        {
            printf("\n\nStudent (%d) : \n", flag);
            printf("=> First Name : %s \n", studentArr[counter].firstName);
            printf("=> Last Name : %s \n", studentArr[counter].lastName);
            printf("=> ID : %d \n", studentArr[counter].ID);
            printf("=> GPA : %0.2f \n", studentArr[counter].GPA);
            printf("=> Number of Courses Taken : %d \n\n\n", studentArr[counter].coursesNum);
            flag++;
        }
        else
        {
            if (counter == length - 1)
            {
                printf("\n\n\aThe Number of taken courses you searched doesn't have data in the system !");
            }
            else
            {
                continue;
            }
        }
    }
}

void DeleteStudent(student_t *studentArr)
{
    static uint8 studentIndex = 0;
    static uint8 stdNum = 0;
    uint8 ID = 0;
    uint8 trials = 3;
    stdNum = latestElement(studentArr);
    if (stdNum == 0)
    {
        printf("\a\nError !!! the classroom is empty !!\n\n\n");
    }
    else
    {
        printf("\nEnter the student ID you want to delete : ");
        scanf("%d", &ID);
        studentIndex = searchID(studentArr, ID);
        while ((ID > 50) || (ID < 1))
        {
            if (ID > 50)
                printf("\aError !!! ID exceeding the maximum limit (50) !! enter a different ID => ");
            else if (ID < 1)
                printf("\aError !!! ID exceeding the minimum limit (1) !! enter a different ID => ");
            else
            { /*Nothing*/
            }
            scanf("%d", &ID);
        }
        studentIndex = searchID(studentArr, ID);
        while ((studentIndex == 50) && (trials > 0))
        {
            trials--;
            printf("\a\nthe ID you searching is not valid !!! Try again => ");
            scanf("%d", &ID);
            studentIndex = searchID(studentArr, ID);
        }
        if ((studentIndex == 50) && (trials == 0))
        {
            printf("\ayour trial has ended ... please Return to the main page\n\n");
            return;
        }
        trials = 3;
        printf("Please wait");
        for (int i = 0; i < 5; i++)
        {
            printf(" . ");
            Sleep(250);
        }
        for (int counter = (studentIndex); counter < stdNum; counter++)
        {
            if (counter == stdNum - 1)
            {
                studentArr[counter].firstName[0] = '\0';
                studentArr[counter].lastName[0] = '\0';
                studentArr[counter].GPA = 0;
                studentArr[counter].ID = 0;
                studentArr[counter].coursesNum = 0;
            }
            else
            {
                studentArr[counter] = studentArr[counter + 1];
            }
        }
        printf("\nthe student data is deleted successfully !\n\n\n");
    }
}

void modifyStudent(student_t studentArr[])
{
    static uint8 studentIndex = 0;
    static uint8 stdNum = 0;
    static uint8 ID = 0;
    static uint8 ID_Neutral = 0;
    static uint8 flag = 0;
    uint8 modifyIndex = 1;
    static uint8 trials = 3;
    char firstName[10];
    char lastName[10];
    stdNum = latestElement(studentArr);
    if (stdNum == 0)
    {
        printf("\a\nError !!! the classroom is empty !!\n\n\n");
    }
    else
    {
        printf("\nEnter the student ID you want to update : ");
        scanf("%d", &ID_Neutral);
        while ((ID_Neutral > 50) || (ID_Neutral < 1))
        {
            if (ID_Neutral > 50)
                printf("Error !!! ID exceeding the maximum limit (50) !! enter a different ID => ");
            else if (ID_Neutral < 1)
                printf("Error !!! ID exceeding the minimum limit (1) !! enter a different ID => ");
            else
            { /*Nothing*/
            }
            scanf("%d", &ID_Neutral);
        }
        studentIndex = searchID(studentArr, ID_Neutral);
        while ((studentIndex == 50) && (trials > 0))
        {
            trials--;
            printf("\a\nthe ID you searching is not valid !!! Try again => ");
            scanf("%d", &ID_Neutral);
            studentIndex = searchID(studentArr, ID_Neutral);
        }
        if ((studentIndex == 50) && (trials == 0))
        {
            printf("\ayour trial has ended ... please Return to the main page\n\n");
            return;
        }
        trials = 3;
        while (modifyIndex != 0)
        {
            printf("\n\nChoose what do you want to update : \n");
            printf("-> (1) First Name \n");
            printf("-> (2) Last Name \n");
            printf("-> (3) ID \n");
            printf("-> (4) GPA \n");
            printf("-> (5) Number of courses taken \n");
            printf("-> (0) Done \n");

            printf("\n=> the option : ");
            scanf("%d", &modifyIndex);
            switch (modifyIndex)
            {
            case 1:
                printf("Enter the new First Name : ");
                memset(&firstName, 15, '\0');
                scanf("%s", &firstName);
                memset(&(studentArr[studentIndex].firstName), 15, '\0');
                strcpy(&(studentArr[studentIndex].firstName), firstName);
                break;
            case 2:
                printf("Enter the new Last Name : ");
                memset(&lastName, 15, '\0');
                scanf("%s", &lastName);
                memset(&(studentArr[studentIndex].lastName), 15, '\0');
                strcpy(&(studentArr[studentIndex].lastName), lastName);

                break;
            case 3:
                printf("Enter the new ID : ");
                scanf("%d", &ID);
                while ((ID > 50) || (ID < 1))
                {
                    if (ID > 50)
                        printf("Error !!! ID exceeding the maximum limit (50) !! enter a different ID => ");
                    else if (ID < 1)
                        printf("Error !!! ID exceeding the minimum limit (1) !! enter a different ID => ");
                    else
                    { /*Nothing*/
                    }
                    scanf("%d", &ID);
                }

                if (ID == ID_Neutral)
                {
                    flag = 0;
                }
                else
                {
                    flag = checkID(studentArr, ID);
                }
                while (ID == flag)
                {
                    printf("Error !!! Already existing ID !! enter a different ID => ");
                    scanf("%d", &ID);
                    if (ID == ID_Neutral)
                    {
                        flag = 0;
                    }
                    else
                    {
                        flag = checkID(studentArr, ID);
                    }
                }
                studentArr[studentIndex].ID = ID;
                break;
            case 4:
                printf("Enter the new GPA : ");
                scanf("%f", &(studentArr[studentIndex].GPA));
                break;
            case 5:
                printf("Enter the new number of registered courses : ");
                scanf("%d", &(studentArr[studentIndex].coursesNum));
                break;
            case 0:
                printf("\nThank you for updating the data\n");
                break;
            default:
                break;
            }
        }
    }
}
