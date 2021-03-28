#include <stdio.h>
#include <string.h>

void PutString(char* pszData, int len)
{
    if(len < 0) {
        putchar('\n');
        return;
    }
    putchar(*pszData);
    
    return PutString(pszData - 1, len - 1);
}

int main()
{
    char strData[80] = { 0, };
    gets(strData);
    
    int len = (int)strlen(strData) - 1;
    PutString(strData + len, len);

    return 0;
}
