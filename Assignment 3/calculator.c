#include "calculator.h"
int Add(int num1, int num2)
{
    return (num1 + num2);
}

int Subtract(int num1, int num2)
{
    return (num1 - num2);
}

int Multiply(int num1, int num2)
{
    return (num1 * num2);
}

float Divide(int num1, int num2)
{
    return ((float)num1 / (float)num2);
}

int Factorial(int num)
{
    if (num == 1)
    {
        return 1;
    }
    else
    {
        return (num * Factorial(num-1));
    }
}

int Absolute(int num)
{
    if (num < 0)
    {
        num *= -1;
    }
    return num;
}

