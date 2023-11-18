#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

int main()
{
    int number1 = 0;
    int number2 = 0;
    int result = 0;
    float result2 = 0.0;
    unsigned char operation = NULL;
    unsigned char continuity = NULL;
    printf("Part 1 => A proper calculator\n\n");
    while (1)
    {
        printf("\t\tWelcome the calculator v3 !!!! \n\n");
        printf("First -> Enter the Operator \n => '+' for addition.\n => '-' for subtraction.\n => '*' for production.\n => '/' for division.\n => '!' for factorial.\n => '|' for absolute value. \n");
        printf("\n => The Operator : ");
        scanf("%c", &operation);
        fflush(stdin);
        if (operation != '!' && operation != '|')
        {
            printf("\n\nSecond -> Enter two numbers  \n");
            printf("\n => First Number : ");
            scanf("%d", &number1);
            printf(" => Second Number : ");
            scanf("%d", &number2);
            switch (operation)
            {
            case '+':
                result = Add(number1,number2);
                printf("=> The result : %d \n", result);
                break;
            case '-':
                result = Subtract(number1,number2);
                printf("=> The result : %d \n", result);
                break;
            case '*':
                result = Multiply(number1,number2);
                printf("=> The result : %d \n", result);
                break;
            case '/':
                result2 = Divide(number1,number2);
                printf("=> The result : %0.2f \n", result2);
                break;
            default:
                break;
            }
        }
        else
        {
            printf("\n\nSecond -> Enter a number : ");
            scanf("%d", &number1);
            switch(operation)
            {
            case '!':
                result = Factorial(number1);
                printf("=> The result : %d \n", result);
                break;
            case '|':
                result = Absolute(number1);
                printf("=> The result : %d \n", result);
                break;
            default:
                break;
            }
        }
        printf("\n\nDo you want to continue ?\n => [y] for yes.\n => [n] for no. \n");
        printf("Answer : ");
        scanf("%s",&continuity);
        fflush(stdin);
        if (('n' == continuity) || ('N' == continuity)) break;
        else    continue;
    }
    return 0;
}
