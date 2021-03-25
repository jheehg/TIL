#include <stdio.h>
#include <string.h>


int main()
{
	char str1[100] = { 0, };
	char* strToken = NULL;
	gets(str1);

	char* strSep = " ";
	strToken = strtok(str1, strSep);

	while (strToken != NULL)
	{
		puts(strToken);
		strToken = strtok(NULL, strSep);
	}
	

	return 0;
}