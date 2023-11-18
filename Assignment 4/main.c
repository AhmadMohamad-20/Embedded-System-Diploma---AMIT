#include <stdio.h>
#include <stdlib.h>

void SwapChar(char *letter_1,char *letter_2)
{
    char temp;
    temp = *letter_1;
    *letter_1 = *letter_2;
    *letter_2 = temp;
}
unsigned int StringLength(char *string)
{
    unsigned int counter = 0;
    while(string[counter] != '\0')
    {
        counter++;       
    }

    return counter;
}
int *ReturnUniqueArray(int array[],int *arraySize)
{
    int ite_1 = 0;
    int ite_2 = 0;
    for (ite_1 = 0; ite_1 < *arraySize; ite_1++)
    {
        for (ite_2 = ite_1 + 1; ite_2 < *arraySize; ite_2++)
        {
            if (array[ite_1] != array[ite_2])
            {
                continue;
            }
            else
            {
                if (ite_2 == (*arraySize - 1))   array[ite_2] = -1;
                else
                {
                    if (array[ite_2] == array[ite_2 + 1])
                    {
                        array[ite_2 + 1] = -1;
                        array[ite_2] = -1;
                    }
                    else
                    {
                        array[ite_2] = array[ite_2 + 1];
                        array[ite_2 + 1] = -1;
                    }                    
                }                
            }
        }
    }
    ite_2 = 0;
    for (ite_1 = 0 ; ite_1 < 10 ; ite_1++)
    {
        if (array[ite_1] == -1)
        {
            continue;
        }
        else
        {
            array[ite_2] = array[ite_1];
            ite_2++;
        }
    }
    array[ite_2] = '\0';
    *arraySize  = ite_2;
    return array;
}
char *ReversedString(char *string)
{
    int length = StringLength(string);
    int counter = 0;
    for (counter = 0; counter < (length / 2); counter++)
    {
        SwapChar(&string[counter],&string[length - 1 - counter]);
    }
    string[length + 1] = '\0';
    return string; 
}

int main()
{
    /*   Task 1 : remove repeated numbers in an array   */
    int arr[] = {0,1,4,0,3,3,3,5,3,7,1};
    int arraySize = sizeof(arr) / sizeof(int);
    printf("=> The Old array : ");
    for (int i = 0; i < arraySize;i++)
    {
        printf("%d ",arr[i]);
    }
    ReturnUniqueArray(arr,&arraySize);
    printf("\n=> The New array : ");
    for (int i = 0; i < arraySize;i++)
    {
        printf("%d ",arr[i]);
    }
    /*   Task 2 : reverse a string   */
    char str[] = "Ahmed";
    printf("\n=> the original string : %s",str);
    char *revStr = ReversedString(str);
    printf("\n=> the reversed string : %s",revStr);
    return 0;
}