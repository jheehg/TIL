## ch18. 파일 입출력

### 파일의 기본 이해

##### 파일

특정 정보의 집합을 파일 시스템에서 식별하기 위한 단위. 메모장으로 열어볼 수 있는 텍스트파일과 나머지 전체를 지칭하는 바이너리 파일로 나뉨. 텍스트 파일과 바이너리 파일의 가장 큰 차이는 **-1**을 해석하는 방법임.

텍스트 파일의 **-1** 은 파일의 끝 (EOF, End Of File)로 처리하지만 바이너리 파일에서는 다른 값과 동일하게 처리됨. 따라서, 두 파일을 다루는 코드나 함수가 다를 수 있음. 텍스트 파일도 바이너리 파일이라 할 수 있으나 저장된 데이터가 **아스키 코드나 문자열로 해석할 수 있는 2진수**로 구성되어 있다는 점이 특징임.

<br/>

##### 파일 시스템

파일 단위의 정보를 생성, 삭제, 저장, 검색할 수 있도록 정보를 구성하는 방법. 

파일위치를 말할 때 트랙과 섹터의 번호로도 표현 가능함. 특정 파일에 대해 이름과 이 번호들을 묶어서 관리 하는 테이블을

FAT(File Allocation Table) 이라 한다. 

윈도우 운영체제의 대표적 파일 시스템은 NTFS(하드디스크), FAT32(Thumb Drive)임.

<br/>

##### 장치의 추상화와 스트림

장치는 파일로 추상화됨으로써 우리는 실제 장치를 알필요 없이 단지 파일을 다루는 공통적인 방법만으로 다양한 장치를 움직일 수 있음. 장치를 파일로 추상화하는 이유는 장치가 달라지면서 사용자가 모든 프로그램을 다시 개발할 일이 없도록 하기 위해서임.

스트림의 개념적 의미는 정보의 흐름. 스트리밍을 위해 메모리를 사용하는 데 이 메모리를 버퍼라고 하며 서버에서 수신하여 컴퓨터의 메모리에 저장하는 것이 버퍼링임.

<br/>

### 파일 열기와 닫기

**FILE *fopen(const char *filename, const char *mode);**

반환값 : FILE 구조체에 대한 주소를 반환하며, 오류 발생 시 NULL 반환.

반환된 FILE구조체는 fclose()함수로 반드시 닫아야 함.

<br/>

**int close(FILE *stream);**

반환값 : 성공하면 0 반환, 오류 발생 시 EOF 반환.

표이 함수는 파일의 입출력을 끝내고 파일을 닫는다.

<br/>

**int _fcloseall(void);**

반환값 : 닫은 파일의 갯수.

프로그램에서 열어둔 파일을 모두 닫는다.

```c
#include <stdio.h>

int main()
{
    FILE *fp = NULL;
    fp = fopen("Test.txt", "w");
    if(fp == NULL)
    {
        puts("ERROR : Failed to open file!");
        return 0;
    }
    // TODO : File I/O
    
    fclose(fp);
    
    return 0;
}
```

<br/>

*os x에서는 _fcloseall() 함수를 사용할 수 없으므로 파일 포인터 배열로 저장해서 fclose() 함수를 실행시켜야 한다고 함..*      

```c
#include <stdio.h>

int main()
{
    FILE *fp[3] = { 0 };
    int nClosed = 0;

    fp[0] = fopen("Test1.txt", "w");
    fp[1] = fopen("Test2.txt", "w");
    fp[2] = fopen("Test3.txt", "w");
    
    for(int i = 0; i < 3; i++)
    {
        fclose(fp[i]);
        nClosed++;
    }
    
    if(nClosed == 3) printf("every file has been closed.\n");
    else printf("something went wrong.\n");
    
    return 0;
}
```



### 텍스트 파일 입출력 함수

**int fprintf(FILE *stream, const char *format [, argument]...);**

반환값 : 출력된 바이트 수 반환.

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = NULL;
    fp = fopen("Test.txt", "w");
    
    fprintf(fp, "%s\n", "Test string");
    fprintf(fp, "%s\n", "Hello world!");
    // 첫번째 인자를 stdout으로 바꾸면 콘솔에 출력결과를 얻을 수 있음.
    
    fclose(fp);
    
    system("notepad.exe Test.txt");
    
    return 0;
}
```

<br/>

**int fscanf(FILE *stream, const char *format[, argument ]...);**

반환값 : 성공적으로 읽어들인 항목(Field)의 개수를 반환.

```c
#include <stdio.h>

int main()
{
    int nData = 0;
    char szBuffer[128] = {0};
    FILE *fp = NULL;
    
    fp = fopen("fscanTest.txt", "w");
    fprintf(fp, "%d,%s\n", 20, "Test"); // 문자열 파일에 쓰기
    fclose(fp);
    
    fp = fopen("fscanTest.txt", "r");
    fscanf(fp, "%d,%s", &nData, szBuffer); // 문자열 파일에서 읽어오기
    fclose(fp);
    
    printf("%d, %s\n", nData, szBuffer);
    
    return 0;
}
```

fscanf() 함수로 문자열을 읽을 때 빈 칸 까지만 읽어 내기 때문에 단어 하나를 읽는 것은 상관 없으나 문장을 읽을 때는 fgets() 함수를 사용하는 것이 좋음.

<br/>

**int fgetc(char *stream);**

대상 파일에서 문자를 읽어들이는 함수. 읽어들인 문자를 반환하며 오류 발생 시. EOF 반환.

```c
#include <stdio.h>

int main()
{
    FILE *fp = NULL;
    char ch;
    
    fp = fopen("Test.txt", "w");
    fputs("Test String!", fp);
    fclose(fp);
    
    fp = fopen("Test.txt", "r");
    if(fp == NULL) return 0;
    
    while((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }
    fclose(fp);
    return 0;
}
```

**int fputc(int c, FILE *stream);**

c는 파일에 쓸 문자임. 정상적인 경우 파일의 쓴 문자 반환, 오류 발생 시 EOF 반환.

<br/>**char *fgets(char *string, int n, FILE *stream);**

대상 파일에서 문자를 읽어 들이는 함수. fputs() 함수의 경우 반복문으로 문자열을 행 단위로 읽음.

정상적이면 string인자로 전달받은 주소를 반환, 오류 발생 시 NULL반환.

```c
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = NULL;
    char szBuffer[512] = {0};
    
    fp = fopen("Test.txt", "w");
    fputs("Test\n", fp);
    fputs("String\n", fp);
    fputs("Data\n", fp);
    
    fclose(fp);
    
    fp = fopen("Test.txt", "r");
    if(fp == NULL) return 0;
    
    while(fgets(szBuffer, sizeof(szBuffer), fp))
    {
        printf("%s", szBuffer);
        memset(szBuffer, 0, sizeof(szBuffer));
      	// 개행문자 기준으로 반복문을 통해서 문자열을 출력하며
        // 기본적으로 문자열 끝에 NULL을 입력하지만 
      	// 예상할 수 없는 외부요인을 방지하기 위해 szBuffer를 0으로 초기화해줌.
    }
    
    fclose(fp);
    
    return 0;
}
```

<br/>

**int fputs(const char *string, FILE *stream);**

대상 파일의 문자열을 출력하는 함수. 정상적이면 음수가 아닌 값을 반환. 오류 발생 시 EOF반환.

fgets() 는 파일 내용을 읽어들인다면 fputs()는 파일에 내용을 쓰는 함수.

<br/>

**int fflush(FILE *stream);**

파일에 대한 입출력을 완료한 후, 파일 입출력과 관련된 정보를 초기화한다. 단, 메모리를 초기화 하진 않음.

성공 시 0 반환, 실패하면 EOF 반환.

<br/>

### 바이너리 파일 입출력 함수

**size_t fread(void *buffer, size_t size, size_t count, FILE *stream);**

바이너리 모드로 대상 파일에서 정보를 <u>읽어 들이는</u> 함수. 성공 시 읽어들인 메모리 블록 수 반환.

**size_t fwrite(const void *buffer, size_t size, size_t count, FILE *stream);**

바이너리 모드로 대상 파일에 정보를 <u>쓰는</u> 함수. 쓰기에 성공한 메모리 블록 수를 반환.

```c
#include <stdio.h>

typedef struct _USERDATA
{
    char szName[16];
    char szPhone[16];
} USERDATA;

int main()
{
    FILE *fp = NULL;
    USERDATA UserData = {"Ho-sung", "123-1234"};
    fp = fopen("Test.dat", "wb"); // 바이너리 쓰기 모드
    if(fp == NULL) return 0;
    
    fwrite(&UserData, sizeof(USERDATA), 1, fp);
    fclose(fp);
    
    return 0;
}
```

```c
#include <stdio.h>

typedef struct _USERDATA
{
    char szName[16];
    char szPhone[16];
} USERDATA;

int main()
{
    FILE *fp = NULL;
    USERDATA UserData = {0};
    fp = fopen("Test.dat", "rb"); // 바이너리 읽기 모드
    if(fp == NULL) return 0;
    
    fread(&UserData, sizeof(USERDATA), 1, fp);
    puts(UserData.szName);
    puts(UserData.szPhone);
    
    fclose(fp);
    
    return 0;
}
```

위 예제에서 fread() 함수 실행 시 반환값은 메모리를 1회 읽는 데 성공한 값 1임.

만약 읽어들일 수 있는 정보의 크기가 USERDATA 구조체의 크기보다 작다면 함수가 실패하여 0을 반환.

<br/>

파일은 논리적으로 마치 배열처럼 하나로 이어진 선형 메모리라 할 수 있음. 파일에 정보를 쓰면 그 크기만큼 <u>자동</u>으로 늘어남. 

<u>파일 입출력 포인터</u>는 파일 입출력이 완료된 위치를 저장하고 있는 포인터.

일반적으로 파일을 열었을 때, 맨 앞에 있으며 입출력이 발생한 크기 만큼 증가한다.

<br/>

**int fseek(FILE *stream, long offset, int origin);**

특정 위치로 파일 입출력 포인터(입출력 대상지점)를 이동하는 함수. 성공 시, 0 반환하고 실패하면 음수를 반환함.

origin은 이동하려고 하는 기준 위치로 SEEK_SET: 처음, SEEK_CUR: 현재, SEEK_END: 끝 을 의미한다.

<br/>**long ftell(FILE *stream);**

입출력 대상이 되는 파일 입출력 포인터의 위치를 알아내는 함수. 이를 이용해 파일 크기를 계산할 수 있음.

함수 반환은 현재 위치(0 이상의 값)을 반환하며 실패하면 -1L을 반환.

```c
#include <stdio.h>

int main()
{
  FILE *fp = NULL;
  fp = fopen("Test.dat", "rb");
  
  // 파일 끝으로 위치 이동하여 파일의 크기를 출력.
  fseek(fp, 0, SEEK_END); 
  printf("size of Test.dat: %u\n", ftell(fp));
  fclose(fp);
}
```

<br/>

**void rewind(FILE *stream);**

파일 입출력 포인터를 맨 앞으로 이동시킴. = fseek(fp, 0, SEEK_SET) 과 같은 의미.

<br/>

### **기타 유용한 함수**

**int feof(FILE *stream);**

파일 입출력 포인터가 파일의 맨 끝에 있는 상태인지 검사하는 함수.

현재 파일의 끝에 있으면 0이 아닌 값을 반환하고 그렇지 않으면 0을 반환함.

<br/>

**int _access(const char *path, int mode);**

특정 파일의 존재유무와 접근 권한을 확인하는 기능을 제공하는 함수. 이 함수는 ANSI 함수가 아니다.

0을 반환하면 파일에 대해 mode로 전달받은 접근이 허용되지만, -1을 반환하면 파일이 없거나 접근할 수 없음을 의미함.

<br/>

<br/>

📙 **출처**

> 열혈강의 최호성의 C프로그래밍