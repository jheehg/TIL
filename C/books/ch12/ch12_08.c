#include <stdio.h>
#include <stdlib.h>

int main()
{
	char mbstr[80] = { 0, };
	gets(mbstr);

	wchar_t wstr[60];
	size_t sizeData = 0;

	sizeData = mbstowcs(NULL, mbstr, 32);
	sizeData = mbstowcs(wstr, mbstr, 32);
	wprintf(L"(%d) %s\n", sizeData, wstr);

	
	return 0;
}