#include <stdio.h>
#include <string.h>

char* toLowerStr(char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (isupper(str[i])) str[i] = tolower(str[i]);
		i++;
	}
	return str;
}

int main()
{
	char str1[80] = { 0, }, str2[80] = { 0, };
	gets(str1);
	gets(str2);

	strcpy(str1, toLowerStr(str1));
	strcpy(str2, toLowerStr(str2));

	if (strcmp(str1, str2) == 0) printf("same");
	else printf("different");

	return 0;
}