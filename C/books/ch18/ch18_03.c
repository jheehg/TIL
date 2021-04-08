#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
    
    char tmpStr[100] = {0};
    
    fp1 = fopen("TestFile.txt", "r");
    fp2 = fopen("DstFile.txt", "w");
    
    if(fp1 == NULL || fp2 == NULL) return 0;
    
    while(fgets(tmpStr, sizeof(tmpStr), fp1))
    {
        fputs(tmpStr, fp2);
        memset(tmpStr, 0, sizeof(tmpStr));
    }
    
    fclose(fp1);
    fclose(fp2);
    
    return 0;
}
