#include <stdio.h>
#include <string.h>

int main()
{
    char str1[80], str2[80];
    gets(str1);
    gets(str2);
    
    printf("%s\n", strcat(str1, str2));
    
    return 0;
}
