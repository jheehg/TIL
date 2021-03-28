#include <stdio.h>

char* NumCompare(int num1, int num2)
{
    if(num1 > num2) return "first value is bigger";
    else if(num1 < num2) return "second value is bigger";
    else return "values are the same";
}

int main()
{
    int numVal1 = 0, numVal2 = 0;
    char* (*TestFunc15_03) (int, int) = NULL;
    TestFunc15_03 = NumCompare;
    
    scanf("%d %d", &numVal1, &numVal2);
    printf("%s\n", TestFunc15_03(numVal1, numVal2));
    
    return 0;
}
