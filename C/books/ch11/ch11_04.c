#include <stdio.h>

void multiply(int data)
{
    for(int i=1; i<10; i++)
    {
        printf("%d * %d = %d\n", data, i, data * i);
    }
}

int main()
{
    int nData = 0;
    scanf("%d", &nData);
    
    multiply(nData);
    
    return 0;
}
