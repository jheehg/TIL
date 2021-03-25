#include <stdio.h>

extern char cData[80];

extern void PrintData();

int main()
{
	gets(cData);
	PrintData();

	return 0;
}