#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main()
{
	char str1[80] = { 0, }, str2[80] = { 0, };
	gets(str1);
	gets(str2);
	
	int sizeArr = sizeof(str1) + sizeof(str2);
	char* strData = (char*)malloc(sizeArr);
	memset(strData, 0, sizeArr);

	strcpy(str1 + strlen(str1), str2);
	
	int i = 0;
	while (str1[i] != '\0')
	{
		strData[i] = str1[i];
		i++;
	}
	 
	// strData = str1 �� �Ҵ��ϸ� 
	//str1 �ּҷ� ����ǹǷ� free()�Ҷ� ������
	
	puts(strData);

	free(strData);
	
	return 0;
}