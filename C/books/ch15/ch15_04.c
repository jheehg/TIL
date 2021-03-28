#include <stdio.h>
#include <string.h>

char* NumCompare(int num1, int num2)
{
    if(num1 > num2) return "first value is bigger";
    else if(num1 < num2) return "second value is bigger";
    else return "values are the same";
}

int TestCbFunc(char* (*callBack)(int, int))
{
    int numVal1 = 0, numVal2 = 0;
    scanf("%d %d", &numVal1, &numVal2);
    
    return (int)strlen(callBack(numVal1, numVal2));
}

int main()
{
    char* (*TestFunc15_04)(int, int) = NULL;
    TestFunc15_04 = NumCompare;
    
    int (*CbTest)(void*) = NULL;
    CbTest = TestCbFunc;
    printf("%d\n", CbTest(TestFunc15_04));
    

    return 0;
}
