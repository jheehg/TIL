#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    
    if(num1 > num2) return -1;
    if(num1 < num2) return 1;
    
    return 0;
}

int main()
{
    int qArr[5] = { 3, 1, 5, 4, 2 };
    qsort(qArr, sizeof(qArr)/sizeof(int), sizeof(int), compare);
    
    for(int i = 0; i < 5; i++)
        printf("%d ", qArr[i]);
    
    printf("\n");
    
    return 0;
}
