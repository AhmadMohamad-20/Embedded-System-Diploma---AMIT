#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* part 1 : A proper calculator */
    int number1 = 0;
    int number2 = 0;
    int sum = 0;
    float sum2 = 0.0;
    unsigned char operation = NULL;
    unsigned char continuity = NULL;
    printf("Part 1 => A proper calculator\n\n");
    while (1)
    {
        printf("\t\tWelcome the calculator v2 !!!! \n\n");
        printf("First -> Enter the Operator \n => '+' for addition.\n => '-' for subtraction.\n => '*' for production.\n => '/' for division.\n => '!' for factorial.\n");
        printf("\n => The Operator : ");
        scanf("%c", &operation);
        fflush(stdin);
        switch (operation)
        {
        case '+':
            printf("\n\nSecond -> Enter two numbers  \n");
            printf("\n => First Number : ");
            scanf("%d", &number1);
            printf(" => Second Number : ");
            scanf("%d", &number2);
            sum = number1 + number2;
            printf("The result = %d .\n", sum);
            break;
        case '-':
             printf("\n\nSecond -> Enter two numbers  \n");
            printf("\n => First Number : ");
            scanf("%d", &number1);
            printf(" => Second Number : ");
            scanf("%d", &number2);
            sum = number1 - number2;
            printf("The result = %d .\n", sum);
            break;
        case '*':
            printf("\n\nSecond -> Enter two numbers  \n");
            printf("\n => First Number : ");
            scanf("%d", &number1);
            printf(" => Second Number : ");
            scanf("%d", &number2);
            sum = number1 * number2;
            printf("The result = %d .\n", sum);
            break;
        case '/':
            {
                printf("\n\nSecond -> Enter two numbers  \n");
                printf("\n => First Number : ");
                scanf("%d", &number1);
                printf(" => Second Number : ");
                scanf("%d", &number2);
                if (0 == number2)   printf("Error !!!! \n");
                else
                {
                    sum2 = (float)number1 / (float)number2;
                    printf("The result = %0.2f .\n", sum2);
                }
                break;
            }
        case '!':
            printf("\n\nSecond -> Enter a number : ");
            scanf("%d", &number1);
            if ((0 == number1) || (0 == number1))   sum = 1;
            else
            {
                sum = 1;
                while (number1 > 0)
                {
                    sum *= number1;
                    number1--;
                }

            }
            printf("The result = %d .\n", sum);
            break;

        default:
            printf("Error !!!! \n");
            break;
        }



        printf("\n\nDo you want to continue ?\n => [y] for yes.\n => [n] for no. \n");
        printf("Answer : ");
        scanf("%s",&continuity);
        fflush(stdin);
        if (('n' == continuity) || ('N' == continuity)) break;
        else    continue;


    }
    /* part 2 : Toggle bit */
    printf("\n\nPart 2 => Toggle bit\n");
    int num = 0xAAAAAA;

    printf("Num before toggle : 0x%X .\n", num);
    num ^=(1<<4);
    printf("Num after toggle: 0x%X .\n",num);

    /* part 3 : get bit */

    printf("\n\nPart 3 => get bit\n");
    num = 0xAAAAAA;
    num = (num >>= 5 ) & 1 ;

    printf("bit value: %d .\n",num);

    /* part 4 : Middle pyramid */
    printf("\n\nPart 4 => Middle pyramid\n\n");
    int rowNumber = 0;
    int counter1 = 0;
    int counter2 = 0;

    printf("Enter the Row Number : ");
    scanf("%d", &rowNumber);
    for (counter1 = 1 ; counter1 <= rowNumber ; counter1++)
    {
        for (counter2 = 0; counter2 < (rowNumber - counter1) ; counter2++)
        {
            printf("  ");
        }
        for (counter2 = 0 ; counter2 < (2*counter1 - 1) ; counter2++)
        {
            printf("* ");
        }
        printf("\n");
    }

    /* part 5 : Inversed Middle pyramid */
    printf("\n\nPart 5 => Inversed Middle pyramid \n\n");
    rowNumber = 0;
    counter1 = 0;
    counter2 = 0;

    printf("Enter the Row Number : ");
    scanf("%d", &rowNumber);
    for (counter1 = 1 ; counter1 <= rowNumber ; counter1++)
    {
        for (counter2 = 0; counter2 <  counter1 ; counter2++)
        {
            printf("  ");
        }
        for (counter2 = 0; counter2 <= (2*(rowNumber - counter1)) ; counter2++)
        {
            printf("* ");
        }

        printf("\n");
    }

    return 0;
}
