#include <stdio.h>
#include <malloc.h>

int getSumOfArr(int** arr, int n)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			 sum += arr[i][j];
		}
	}

	return sum;
}

int main()
{
	int numArr[5] = {1, 2, 3, 4, 5};
	int nData = 0;
	scanf("%d", &nData);
	
	int** arrData = (int**)malloc(nData * sizeof(numArr));
	memset(arrData, 0, nData * sizeof(numArr));

	for (int i = 0; i < nData; i++)
	{
		arrData[i] = numArr;
	}

	printf("%d\n", getSumOfArr(arrData, nData));

	free(arrData);

	return 0;
}