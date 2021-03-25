### **strcat()/strncat()**

: 두 문자열을 이어 붙이는 기능. 보안 결함으로 인한 대체 함수는 strcat_s(). / unicode: wcscat(), wcscat_s()

**char *strcat(char *strDestination, const char \*strSrouce);**

첫번째 인자에 두번째 인자로 전달받은 문자열을 추가하는 함수.

**char *strncat(char *strDestination, const char \*strSrouce, <u>size_t count</u>);**

strcat() 함수와 같은 기능이나 주어진 길이(count) 만큼 추가하는 함수.

<br/>

### **strstr()/strchr()**

: 특정 문자열에서 문자열 또는 문자를 찾아주는 함수.  / unicode: wcsstr(), wcschr()

**char *strstr(const char *string, const char \*strCharset);**

첫번째 인자의 문자열에서 두번째 인자의 문자열을 찾는 함수. 찾으면 저장된 **메모리의 주소** 반환. 못 찾으면 NULL.

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char szBuffer[128] = {0};
    char szWord[16] = {0};
    char *pszResult = NULL, *pszStart = szBuffer;
    int nWordLength = 0;

    printf("Input String: ");
    gets(szBuffer); // banana apple kiwi
    printf("Input string to find: ");
    gets(szWord);   // apple

    // 입력한 단어의 길이 구하기
    nWordLength = strlen(szWord);

    // 기존 문자열에서 입력받은 문자열의 메모리주소를 구해서 pszResult에 넣기
    while( (pszResult = strstr(pszStart, szWord)) != NULL)
    {
        printf("[%p] %s\n", pszResult, pszResult ); // [0x7ffeefbff427] apple kiwi
        // pszResult부터 입력받은 문자만큼 이동한 메모리주소를 pszStart에 넣기
        pszStart = pszResult + nWordLength;
        // 검색을 시작할 문자열이 저장된 주소를 검색어 다음의 주소가 되도록 수정.
        printf("%s\n", pszStart); // kiwi
    }
    return 0;
}
```

<br/>

**char *strchr(const char *string, int c);**

임의의 대상 문자열에서 특정 문자를 검색하는 함수. 찾으면 저장된 **메모리의 주소** 반환. 못 찾으면 NULL.

```c
#include <stdio.h>
#include <string.h>

int main()
{
    char szBuffer[128] = {0};
    char ch = 0;
    char *pszStart = szBuffer;
    printf("Input string: ");
    gets(szBuffer);
    printf("Input char: ");
    ch = getchar();

    while((pszStart = strchr(pszStart, ch)) != NULL)
    {
        // 찾으려는 문자의 메모리주소에서 원래 메모리 주소의 차이로 인덱스를 구함.
        printf("[p%] Index: %d\n", pszStart, pszStart - szBuffer);
        pszStart++;
    }

}
```

<br/>

**char *strpbrk(const char \*string, const char *strCharSet);  / unicode : wcspbrk() **

임의의 대상 문자열에서 특정 문자집합을 검색하는 함수. strstr()은 문자열을 찾는 것에 반해,  strpbrk()는 string 문자열 내에서 stCharSet에 속하는 모든 문자를 차례대로 다 저장한 집합임. 반환값은 문자가 저장된 메모리 주소, 못 찾으면 NULL.

```c
#include <stdio.h>
#include <string.h>

int main()
{
	char szBuffer[128] = { 0 };
	char szSet[128] = { 0 };
	char* pszStart = szBuffer;

	printf("Input string: ");
	gets(szBuffer);
	printf("Input character set: ");
	gets(szSet);

	while ((pszStart = strpbrk(pszStart, szSet)) != '\0')
	{
		printf("[%p] Index: %d, %c\n", pszStart, pszStart - szBuffer, *pszStart);
		pszStart++;
	}

	return 0;
}
```

<br/>

**char *strtok(char *strToken, const char \*strDelimit);, strtok_s()  /  unicode: strtok_s()**

임의의 문자열을 구분자로 토큰화하는 함수. 내부적으로 정적변수를 사용하므로 주의해야 함.

strToken: 토큰화 될 문자열이 저장된 메모리 주소

strDelimit: 토큰의 기준이 되는 구분자 집합

반환값: 구분자 집합의 문자 중 하나라도 찾으면 해당 문자가 저장된 메모리의 내용을 **NULL**로 바꾸고 문자열의

시작 주소를 반환.

```c
#include <stdio.h>
#include <string.h>

int main()
{
	char szBuffer[128] = { "nData = x + y;\nnReset = a * b" };
	char* pszSep = " *+=;\n"; // 문자열에 해당되는 모든 문자 구분자로 지정
	char* pszToken = NULL;

	// 구분자에 해당되는 문자는 모두 NULL로 치환되며 문자열 주소를 반환함.
	pszToken = strtok(szBuffer, pszSep);
	
	while (pszToken != NULL)
	{
		puts(pszToken); // puts()함수는 NULL 만나면 문자열 출력
		
		// 첫번째 인자에 NULL을 넣는 이유는 해당 함수가 정적변수를 사용하므로
		// 한번 저장한 값이 계속 유지되기 때문임. 
		pszToken = strtok(NULL, pszSep);
	}
	printf("\nszBuffer: %s\n", szBuffer);
	// pszToken()에 의해 NULL로 치환됐으므로 nData까지만 출력.

	return 0;
}
```

<br/>

**유니코드 → MBCS**

**size_t wcstombs(char *mbstr, const wchar_t \*wcstr, size_t count);, wcstombs_s()**

mbstr: MBCS로 변환한 문자열을 저장할 메모리 주소

wcstr: 변환할 유니코드 문자열이 저장된 메모리 주소

count: 변환할 문자열의 최대 길이

반환값: MBCS로 변환한 문자열의 길이를 반환. 첫번째 인자가 NULL이면 변환을 위해 필요한 메모리 크기를 반환.

**MBCS → 유니코드**

**size_t mbstowcs(wchar_t\* wchar_t, const char \*mbstr, size_t count);, mbstowcs_s()**

wchar_t: 변환한 유니코드의 문자열을 저장할 메모리주소

mbstr: 유니코드로 변환할 MBCS문자열이 저장된 메모리주소

count : 변환할 문자열의 최대 길이

반환값: 유니코드로 변환한 문자열의 길이를 반환. 첫번째 인자가 NULL이면 변환을 위해 필요한 메모리 크기를 반환.

<br/>

<br/>

<br/>

📙 **출처**

> **열혈강의 최호성의 C프로그래밍**