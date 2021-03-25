#include <stdio.h>
#include <string.h>

int main()
{
    char str1[80], str2[80];
    gets(str1);
    gets(str2);
    
    char *res = (strlen(str1) > strlen(str2))? str1 : str2;
    printf("%s\n", res);
    
    return 0;
}
