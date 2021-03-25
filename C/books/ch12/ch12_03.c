#include <stdio.h>
#include <string.h>

int main()
{
    char str1[80], str2[80];
    gets(str1);
    gets(str2);
    
    sprintf(str1 + strlen(str1), "%s\n", str2);
    
    puts(str1);
    
    return 0;
}
