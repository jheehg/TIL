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


int main()
{
    char* str;
    int len = 0;
    
    gets(str);
    
    len = getLength(str);
    printf("%d\n", len);
    
    return 0;
}
