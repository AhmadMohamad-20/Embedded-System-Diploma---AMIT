#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1 = 0;   /*First Number initialized*/
    int num2 = 0;
    char _coutinue;   /*Second Number initialized*/


    printf("Enter two numbers : ");
    scanf("%d %d", &num1, &num2);   /*taking the number values from the user*/
    printf(" => The summing result = %d\n", (num1 + num2));    /*printing the sum of the two numbers*/
    printf(" => The subtraction result = %d\n", (num1 - num2));    /*printing the subtraction of the two numbers*/
    printf(" => The production result = %d\n", (num1 * num2));    /*printing the product of the two numbers*/
    printf(" => The division result = %0.2f\n", ((float)num1 / (float)num2));    /*printing the division of the two numbers*/


    return 0;
}
