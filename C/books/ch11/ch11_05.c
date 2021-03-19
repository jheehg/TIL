#include <stdio.h>


int findChar(char* str, char target)
{
	int idx = -1, i = 0;
	while (*(str + i) != NULL)
	{
		if (*(str + i) == target)
		{
			idx = i; break;
		}
		i++;
	}
	return idx;
}

int main()
{
	char strData[80];
	char ch;
	int idx = 0;
	gets(strData);
	scanf("%c", &ch);

	idx = findChar(strData, ch);
	printf("%d\n", idx);

	return 0;
}