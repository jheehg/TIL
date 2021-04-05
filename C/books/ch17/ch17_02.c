#include <stdio.h>

int g_anStack[5] = {0};
int g_nStackpointer = -1;

int Push(int nData)
{
    if(g_nStackpointer == 4 || nData < 0)
       return 0;
    else
        g_anStack[++g_nStackpointer] = nData;
    return 1;
}

int Pop(int *pnData)
{
    if(g_nStackpointer == -1) return 0;
    else
    {
      *pnData = g_anStack[g_nStackpointer];
      g_anStack[g_nStackpointer--] = 0;
    }
    return 1;
}

int main()
{
    int nData = 0;
    for(int i = 1; i <= 5; i++)
        Push(i);
    for(int i = 1; i <= 5; i++)
    {
        if(Pop(&nData))
        {
            printf("%d\n", nData);
        }
    }
    return 0;
}
