#include <stdio.h>

char cData[80] = { 0, };

void PrintData()
{
	printf("%s\n", cData);
}

int main()
{
	gets(cData);
	PrintData();

	return 0;
}