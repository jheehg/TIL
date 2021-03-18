#include <stdio.h>

void swap(int* data, int i, int j)
{
    int tmp = 0;
    tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}

void sortArr(int* data, int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(data[i] > data[j]) swap(data, i, j);
        }
    }
}

int main()
{
    int arr[6] = {3, 7, 4, 10, 2, 8};
    int len = sizeof(arr)/sizeof(int);
    sortArr(arr, len);
    
    for(int i=0; i<len; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
