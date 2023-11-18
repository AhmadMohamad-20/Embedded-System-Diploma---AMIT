#include <stdio.h>
#include <stdlib.h>
int MaxNumInArray(int *arr,int *arraySize)
{
    int maxNum = 0;
    
    for (int counter = 0; counter < arraySize ; counter++)
    {
        maxNum = (*arraySize > arr[counter])? *arraySize : arr[counter];
    }
    return maxNum;
}

void ReturnUniqueArray(int *arr, int*arraysize);

int main()
{
   return 0; 
}
void ReturnUniqueArray(int *arr, int*arraysize)
{

}