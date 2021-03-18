#include <stdio.h>
#include <string.h>

int getLength(char* str)
{
    int len = 0;
    while(*(str + len) != '\0')
    {
        len++;
    }
    return len;
}


void backWard(char* str, int len)
{
    for(int i=len-1; i>=0; i--)
    {
        printf("%c", str[i]);
    }
    printf("\n");
    
}

int main()
{
    int len = 0;
    char *str;
    gets(str);
    
    len = getLength(str);
    backWard(str, len);

    return 0;
}
