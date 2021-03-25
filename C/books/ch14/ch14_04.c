#include <stdio.h>
#include <string.h>

void PrintString(char* pszData)
{
	static char strData[50] = { 0, };
	if ((int)(strlen(strData) - strlen(pszData)) < 0) 
		printf("%s\n", pszData);
	
	strcpy(strData, pszData);
}

int main()
{
	PrintString("Test");
	PrintString("String");
	PrintString("Data");
	PrintString("New");

	return 0;
}