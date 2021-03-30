## ch16. 구조체와 공용체

### 구조체

**<u>여러 자료형</u>**을 하나로 묶어 새로 구성된 자료형. 한가지 자료형으로만 묶을 수 있는 배열과는 차이가 있음.

구조체안의 멤버변수 선언과 일반적인 변수 선언은 관련이 없음을 주의.

<br/>

##### 구조체의 선언과 활용

struct 구조체_이름 { 자료형 멤버변수\_이름; };

전체 구조체가 스코프로 묶여있으며 안에 **하나 이상의 멤버변수**를 선언한다. 변수 선언처럼 <u>기억부류나 초깃값</u>을 지정할 수 없음.

예제1 )

```c
#include <stdio.h>

struct USERDATA
{
    int nAge;					// 4 byte
    char szName[16];  // 16 byte
    char szPhone[16]; // 16 byte
  										// 구조체 USERDATA의 크기는 36 byte
};

int main()
{
    struct USERDATA UserData = {0};
    UserData.nAge = 20;
    sprintf(UserData.szName, "%s", "Hong kil-dong");
    sprintf(UserData.szPhone, "%s", "010-2222-4444");
    
    return 0;
}
```

예제 2) 초기화 하는 방법이나 형태는 다차원 배열을 초기화 하는 것과 유사함.

```c
#include <stdio.h>

struct USERDATA
{
    int nAge;
    char szName[16];
    char szPhone[16];
};

int main()
{
    struct USERDATA UserData = {
        20, "Hong kil-dong", "010-2222-4444" };
    printf("%d\n", UserData.nAge);
    puts(UserData.szName);
    puts(UserData.szPhone);
    
    return 0;
}
```

예제3 ) 구조체에 대하여 포인터 변수로 선언 후 멤버변수를 '->' 연산자로 접근.  간접지정연산자(*)와 구조체 멤버 접근 연산자 (.) 를 합친 것과 같다.

```c
#include <stdio.h>

struct USERDATA
{
    int nAge;
    char szName[16];
    char szPhone[16];
};

int main()
{
    struct USERDATA UserData = {
        20, "Hong kil-dong", "010-2222-4444" };
    
    struct USERDATA *pData = &UserData;
    
    printf("%d\n", pData->nAge);
    puts(pData->szName);
    puts(pData->szPhone);
    
    return 0;
}
```

<br/>

##### 구조체를 멤버로 가지는 구조체

구조체의 멤버는 기본 자료형 외에도 열거형상수 또는 새로 정의된 자료형, 다른 구조체도 될 수 있다.

```c
#include <stdio.h>

struct PERSON
{
    int nAge;
    char szName[16];
};

struct USERDATA
{
    struct PERSON person;
    char szPhone[16];
};

int main()
{
    struct USERDATA UserData = {
        { 20, "Hong kil-dong" },
        "010-2222-4444"
    };
    
    puts(UserData.person.szName);
    puts(UserData.szPhone);
    
    return 0;
}
```

<br/>

##### typedef 문과 조합한 선언 방법

```c
#include <stdio.h>

typedef struct _USERDATA
{
    int nAge;
    char szName[16];
    char szPhone[16];
} USERDATA;

int main()
{
    USERDATA UserData =   {
        20, "Hong kil-dong" , "010-2222-4444"
      };
    printf("%d\n", UserData.nAge);
    puts(UserData.szName);
    puts(UserData.szPhone);
    
    return 0;
}
```

<br/>

##### 자기 참조 구조체

구조체 멤버로 자기 자신을 가리키는 포인터를 가진 구조체.

보통은 단일 포인터이며 **<u>Linked List</u>** 또는 **<u>Tree</u>** 형태의 자료구조를 구현하는 데 자주 사용.

```c
typedef struct _USERDATA {
    char szName[16];
    char szPhone[16];
    struct _USERDATA *pText;
} USERDATA;
```

<br/>

##### 비트 필드

크기가 1byte 미만인 자료형을 구조체 멤버로 선언하는 방법. 하드웨어를 제작하고 제어할 목적으로 활용하는 경우 사용.

```c
#include <stdio.h>

typedef struct _DATAFLAG {
    unsigned char main : 1; // 변수명 : bit (사이즈)
    unsigned char left : 2;
    unsigned char right : 3;
    unsigned char top : 2;
} DATAFLAG;


int main()
{
    DATAFLAG flagSwitch = {0, 3, 7, 4};
    // 정수 4는 2bit에 담을 수 없으므로 0 처리
    printf("%d\n", flagSwitch.main);
    printf("%d\n", flagSwitch.left);
    printf("%d\n", flagSwitch.right);
    printf("%d\n", flagSwitch.top);
    
   // printf("%X\n", (unsigned char)flagSwitch); 일반 자료형으로 출력할 수 없음.
    printf("%X\n", *((unsigned char *)&flagSwitch)); // 포인터로 접근하면 출력 가능
    // 0x3E (00111110)
    // 멤버변수 main부터 순차적으로 2진수로 변환. (2^0 -> 2^7)
    printf("%d\n", sizeof(flagSwitch));  // 1byte
    
    return 0;
}
```

<br/>

### 공용체(Union)

한 메모리에 대해서 여러 자료형을 부여하는 것. 메모리를 해석하는 다양한 방법을 제공하여 좀더 쉽게 메모리를 다룰 수 있도록 해줌. 구조체는 멤버변수가 모두 각각의 메모리에 부여되지만 공용체는 모두 <u>**같은 메모리**</u>에 부여되고 이를 여러 이름을 가진 멤버가 모두 공유함.

```c
#include <stdio.h>

typedef union _IP_ADDR {
    int nAddress;
    short awData[2];
    unsigned char addr[4];
} IP_ADDR;

int main()
{
    IP_ADDR Data = {0}; // Data 객체의 크기 : 4 byte
    Data.nAddress = 0x41424344;
    printf("%c%c%c%c\n", Data.addr[0], Data.addr[1], Data.addr[2], Data.addr[3]);
  	// (char타입) 44 = D, 43 = C, 42 = B, 41 = D
    printf("%X, %d\n", Data.awData[0], Data.awData[0]);
    // 4344, 17220
    printf("%X, %d\n", Data.awData[1], Data.awData[1]);
  	// 4142, 16706
    
    return 0;
}
```

공용체 멤버의 크기가 서로 다를 경우 가장 큰 멤버의 자료형 크기를 갖게 됨,

```c
#include <stdio.h>

union USERDATA2 {
    int nData;  
    short wData;
    char chData;
};

int main()
{
    union USERDATA2 test = {0};
    test.chData = 10;
    printf("%d, %d\n", sizeof(union USERDATA2), test.nData);
  	// 4, 10 (이름은 다르지만 같은 메모리이므로 값 동일)
   
    return 0;
}
```

<br/>

<br/>

📙 **출처**

> 열혈강의 최호성의 C프로그래밍