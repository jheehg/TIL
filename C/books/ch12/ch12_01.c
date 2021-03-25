#include <stdio.h>
#include <ctype.h>

int main() {
    char str[80];
    gets(str);
    
    int i = 0;
    while(str[i] != '\0')
    {
        if(isupper(str[i]))
        {
            str[i] = tolower(str[i]);
        }
        else
        {
            str[i] = toupper(str[i]);
        }
        i++;
    }
    puts(str);
   
    return 0;
}
