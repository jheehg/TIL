#include <stdio.h>


int Fibonacci(int num1, int num2)
{
    printf("%d\n", num1);
    if(num2 >= 60) return 0;
    
    return Fibonacci(num2, num1 + num2);
}

int main()
{
    int initVal = 1;
    Fibonacci(initVal, initVal);
    
    return 0;
}
