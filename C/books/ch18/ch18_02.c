#include <stdio.h>

int main()
{
    FILE *fp = NULL;
    char fileStr[100] = {0};
    
    fp = fopen("TestFile.txt", "a");
    if(fp == NULL) return 0;
    
    gets(fileStr);
    fputs(fileStr, fp);
    fputc('\n', fp);
    
    fclose(fp);
    
    return 0;
}
