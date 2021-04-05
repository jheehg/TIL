#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void BubbleSort(char** memData)
{
    char tmp[100] = { 0, };
    for(int i = 4; i >= 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(strcmp(memData[j], memData[j + 1]) > 0) {
                strcpy(tmp, memData[j + 1]);
                strcpy(memData[j + 1], memData[j]);
                strcpy(memData[j], tmp);
            }
        }
    }
}

void PrintStr(char** data)
{
    for(int i = 0; i < 5; i++)
    {
        printf("%s\n", data[i]);
    }
}

int main()
{
    char* str;
    char** memStr_o = (char**)malloc(500);
    memset(memStr_o, 0, 500);
    char* memStr = NULL;
    
    for(int i = 0; i < 5; i++)
    {
        gets(str);
        memStr = (char*)malloc(strlen(str));
        memset(memStr, 0, strlen(str));

        strcpy(memStr, str);
        *(memStr_o + i) = memStr;
    }

    BubbleSort(memStr_o);
    PrintStr(memStr_o);


    for(int i = 0; i < 5; i++)
    {
        free(*(memStr_o + i));
    }

    free(memStr_o);

    return 0;
}
