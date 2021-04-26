#include <stdio.h>
#include <string.h>

int main()
{
    char name1[50] = {0};
    char name2[50] = {0};
    
    scanf("%s", name1);
    scanf("%s", name2);

    if(memcmp(name1, name2, sizeof(char) * sizeof(name1)) == 0)
    {
        printf("%s\n", "같음");
    }
    else
    {
        printf("%s\n", "다름");
    }
    return 0;
}
