#include <stdio.h>

int main()
{
    char fileStr[50];
    fgets(fileStr, sizeof(fileStr), stdin);
    fputs(fileStr, stdout);
    
    return 0;
}
