## ch12. 문자열과 문자열 처리 함수

<br/>

### **문자열의 구분**

영문  => 1 byte

한글  => 2 byte



- MBCS (Multi-Bytes Character Sets)

영문은 1byte, 한글은 2byte로 표현되며 문자열은 NULL(0)로 끝남.

- 유니코드 (Unicode)

영문, 한글 관계없이 모두 **한 글자당 2 byte** 메모리 사용, 문자열의 끝이 NULL 두 개로 끝남.

(영문은 실제 "영문자 + NULL"로 이루어져 **2 byte** 로 표현됨)

메모리를 일부 낭비하더라도 문자열 처리에 일관성을 유지하도록 만들어짐.

MBCS와 문자 타입과 문자열 관련 함수를 다르게 사용 하므로 반드시 유니코드 기반의 함수를 사용해야 한다.

```c
#include <stdio.h>

void main(void)
{
	/* 
		<< unicode >>
		char      -> wchart    : 2 byte
		문자열상수 앞에 L 붙여 사용.
		printf()  -> wprintf()
		sprintf() -> swprintf()
	*/
	wchar_t *pwszData = L"String";
	wchar_t wszData[32];
	
	swprintf(wszData, L"%s", pwszData);
	wprintf(L"%s\n", wszData);
}
```

<br/>

### 문자처리함수

*반환값은 조건이 맞지 않으면 0, 맞으면 0이 아닌 값 반환으로 동일함.*

**int isalpha(int c);  /  unicode: int iswalpha(int c);**

: A-Z, a-z에 속하는 문자인지 검사하는 함수.

**int isdigit(int c);   /  unicode: int iswdigit(int c);**

: 0~9에 속하는 문자인지 검사하는 함수.

**int isxdigit(int c);  /  unicode: int iswxdigit(int c);**

: 0~9, a~f, A~F에 속하는 문자인지 검사하는 함수.

**int isalnum(int c);**

: 0~9, a~z, A~Z에 속하는 문자인지 검사하는 함수.

```c
#include <stdio.h>
#include <ctype.h>

int main()
{
    printf("%d, %d\n", isalpha('A'), isalpha(0x41));
    // 1, 1
    // 'A'의 아스키코드값: 0x41
    printf("%d, %d\n", isalpha(1), isalpha('#'));
    // 0, 0
    // 정수 상수, 특수문자는 알파벳이 아님.
    printf("%d, %d\n", isdigit(5), isdigit('5'));
    // 0, 1
    // 정수 상수는 문자가 아님.
    printf("%d, %d\n", isxdigit('F'), isxdigit('G'));
    // 1, 0
    printf("%d, %d\n", isalnum('0'), isalnum('9'));
    // 1, 1
    printf("%d, %d\n", isalnum(0), isalnum(9));
    // 0, 0
    
    return 0;
}
```

<br/>

**int islower(int c);  /  unicode: int iswlower(int c);**

: a~z에 속하는 문자인지 검사하는 함수. lower-case.

**int isupper(int c);  /  unicode: int iswupper(int c);**

: A~Z에 속하는 문자인지 검사하는 함수. upper-case.

**int isspace(int c);  /  unicode: int iswspace(int c);**

: 0x09(수평 탭) ~ 0x0D(복귀)나 0x20에 속하는 화이트 스페이스 문자인지 검사하는 함수.

```c
#include <stdio.h>
#include <ctype.h>

int main()
{
    /*
     ' ' : 스페이스
     '\n': 개행
     '\t': 수평 탭
     '\v': 수직 탭
     '\f': 피드
     '\r': 캐리지 리턴
     */
    printf("%d, %d\n", islower('a'), islower('A'));
    // 1, 0
    printf("%d, %d\n", isupper('a'), isupper('A'));
    // 0, 1
    printf("%d, %d\n", isspace('\t'), isspace(' '));
    // 1, 1
    printf("%d, %d\n", isspace('\r'), isspace('\n'));
    // 1, 1
    printf("%d, %d\n", isspace('a'), isspace('1'));
    // 0, 0
    
    return 0;
}
```

<br/>

**int toupper(int c);  /  unicode: int towupper(int c);**

: 영문 소문자를 대문자로 변환하는 함수. 조건에 맞는 대문자를 반환함.

**int tolower(int c);  /  unicode: int towlower(int c);**

: 영문 대문자를 소문자로 변환하는 함수. 조건에 맞는 소문자를 반환함.

<br/>

### 문자열 처리 함수

**int sprintf(char *buffer, const char *format[, argument] ...);**

buffer: 출력 문자열이 저장될 메모리의 주소.

format: 형식 문자열이 저장된 메모리의 주소.

[, argument]: 형식 문자열에 대응하는 가변 인자들.

형식 문자열에 맞추어 특정 메모리에 문자열을 출력하는 함수, 출력된 문자열 길이를 반환함.

printf() 함수와 기능이 같지만 출력하는 대상이 표준 출력 장치(console)가 아닌 <u>**메모리**</u>.

```c
#include <stdio.h>

int main()
{
    char* apszData[] = {"Test", "String", "Data"};
    char szBuffer[128] = {0};
    int i = 0, nOffset = 0;
    
    for(i = 0; i < 3; ++i)
    {
        nOffset += sprintf(szBuffer + nOffset,
                           "%d) %s\n", i, *(apszData + i));
    }
		// apszData에 저장된 문자열을 출력하면서 반환된 길이를 nOffset에 더해줌으로써
	  // szBuffer에 하나씩 저장한다.

		// sprintf()는 메모리에 출력했으므로 console 출력은 puts() 함수로 한다.
    puts(szBuffer);
    
    return 0;
}
```

<br/>

**int sprintf_s(char *buffer, size_t sizeOfBuffer, const char *format [,argument] ...);**

sprintf()는 보안이 취약한 함수로 sprintf_s() 함수를 대신 사용하라는 경고가 나오는데

이 sprintf_s()함수는 **윈도우**에서만 사용이 가능한 것으로 리눅스, 유닉스에서는 사용할 수 없음.

저장될 대상 메모리의 크기에 대한 정보를 인자로 받음.

<br/>

**size_t strlen(const char *string);  /  unicode: wcslen()**

: 공백을 포함한 문자열의 길이를 반환하는 함수로 끝을 명시하는 NULL은 제외함.

<br/>

**int strcmp(const char *string1, const char *string2);**

: 두 문자열이 같으면 0, 0보다 크면 string1이 알파벳 순서상으로 나중 문자열, 0보다 작으면 string2이 나중 문자열임.

**int strncmp(const char *string1, const char *string2, <u>size_t count</u>);**

: strcmp()함수와 같은 기능을 하지만 주어진 길이 만큼 두 문자열을 비교하는 함수.

<br/>

**char *strcpy(char *strDestination, const char *strSource); / unicode: wcscpy()**

: 원본 메모리의 문자열을 대상 메모리에 복사하는 함수. 형식문자열을 사용안한다는 것 제외하고 sprintf()함수와 유사함.

**char *strncpy(char *strDestination, const char *strSource, <u>size_t count</u>); / unicode: wcsncpy()**

: 주어진 길이만큼 대상 메모리에 문자열을 복사하는 함수.

<br/>

<br/>

📙 출처

\> *열혈강의 최호성의 C프로그래밍*

