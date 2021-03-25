## ch14. 변수에 대한 고급 이론

### 자동변수

스택 영역의 메모리를 사용하는 변수. 스코프 열릴 때 스택에 추가되었다가 끝나면 자동으로 소멸.

변수 선언 시 기억부류에 대한 명시가 없었다면 자동으로 자동변수가 됨.

<br/>

### 스코프 중첩과 지역변수 접근성

1. 입력값 15가 스택으로 들어옴
2. if문 안에 첫번째 스코프에 할당된 20이 먼저 출력
3. 새로운 스코프에 할당된 30이 출력
4. nInput이 20인 값이 여전히 살아있으므로 20 출력
5. 가장 첫번째 들어왔던 15 출력

```c
#include <stdio.h>

void main()
{
	int nInput = 0;
	scanf("%d", &nInput);  // 15

	if (nInput > 10)
	{
		int inInput = 20;
		printf("%d\n", nInput);   

		{
			int nInput = 30;
			printf("%d\n", nInput);  
		}
		printf("%d\n", nInput);  

	}
	printf("%d\n", nInput); 

}
```

<br/>

### 전역변수

변수 이름에 g_와 같은 접두사를 붙여 이름만으로 지역변수와 식별될 수 있도록 한다.

<br/>

### 외부 변수 선언

다른 외부 소스파일에서 선언된 변수를 현재 파일에서 참조하여 사용하는 변수. 

전역변수로 선언된 것만 사용 가능.

외부 변수 선언 시 타입 앞에 extern 붙이고 초기값은 실제 내용을 정의하는 곳에서 해야함.

```c
#include <stdio.h>

// 전역변수사용시 미리 선언해줘야 메인에서 사용 가능.
void InitCounter(int nData);
void IncreaseCounter();

extern int g_nCounter;

int main()
{
	InitCounter(10);
	printf("%d\n", g_nCounter);
	IncreaseCounter();
	printf("%d\n", g_nCounter);

	return 0;
}
```

외부 변수 및 함수 실제 내용은 Test.c에서

```c
#include <stdio.h>

int g_nCounter = 0;

void InitCounter(int nData)
{
	g_nCounter = nData;
}

void IncreaseCounter()
{
	g_nCounter++;
}
```

소스파일이 2개면 오브젝트 파일도 2개인데 링크할 때 이 2개를 하나로 합치면서 선언된 것들의 실체가

어느 오브젝트 내용에 있는지 짝을 맞추게 되며 이때 제대로 찾지 못하면 오류가 발생함.

<br/>

### 변수 식별 순서

전역변수와 지역변수가 같은 변수명으로 선언이 될 경우 지역변수가 먼저 식별이 되고 가장 나중에 전역변수가 식별된다.

<br/>

### 정적 변수

지역변수를 정적변수로 선언할 때 : 스택에 변화와 관련없이 메모리에 저장된 값을 유지시킬 수 있음.

전역변수를 정적변수로 선언할 때 : 연속성에는 큰 의미가 없지만 접근성을 해당 소스파일 내로 제한할 수 있음.

```c
#include <stdio.h>

int TestFunc()
{
	static int nResult = 10; // 정적변수 선언
	nResult++;
	return nResult;
}

void main(void)
{
	printf("%d\n", TestFunc()); // 11
	printf("%d\n", TestFunc()); // 12
	printf("%d\n", TestFunc()); // 13
}
// TestFunc()에서 선언된 변수지만 static이기 때문에 값이 그대로 저장되서 1씩 증가함.
// static변수가 아니면 계속 11 출력.
```

<br/>

### 레지스터 변수

RAM이 아닌 CPU의 일부인 레지스터 메모리를 사용. 스택이 아닌 레지스터에 위치하므로 연산속도가 훨씬 빠름.

매우 제한적임. 레지스터 용량이 부족하다면 자동변수로 전환됨.

**전역변수, 정적변수로 선언할 수 없고 레지스터 변수에 대한 주소 연산 수행을 할 수 없음.**

```c
#include <stdio.h>

int main()
{
	int nTotal = 0;
	register int i = 0;
	for (i = 0; i < 10; ++i)
	{
		nTotal += i;
	}

	printf("%d\n", i);
	//printf("%p\n", &i); // 주소연산 수행이 안되므로 오류발생.
	return 0;
}
```

<br/>

### 형한정어

읽기는 가능하지만 쓰기 불가능한 메모리 사용 시 const 사용.

**const ⇒ 심볼릭 상수(Symbolic Constant)**

```c
#include <stdio.h>

int main()
{
	char szName[16];
	const int nData = 10;

	// 3 = 4; 리터럴 상수. 눈에 보이는 것 자체가 이미 값임. A는 영문자 상수, 10은 정수 상수.
	// szName = 'A';
	// nData = 20;
	return 0;
}
```

**volatile ⇒ 기계어로 번역 시 코드가 최적화될 때 의도하지 않은 오류발생이 될 경우를 차단하기 위해 사용. 컴파일러 최적화 대상에서 제외됨.**

```c
#include <stdio.h>

int main()
{
	int i = 0, nVariable = 0;
	int nResult = 10;
	volatile int nData = 10;

	for (i = 0; i < 10; ++i)
		nResult += nVariable * 10; // 0 * 10이 되므로 최적화대상
	for (i = 0; i < 10; ++i)
		nData += nVariable * 10;  // 위와 같은 코드이나 volatile로 선언될 경우 
    							  // 최적화대상에서 제외

	printf("%d, %d\n", nData, nResult);

	return 0;
}
```

위 코드에서 nVariable의 값이 변동될 가능성이 있을 경우 사용 고려할 수 있음.

<br/>

### 사용자 정의 자료형

기존 자료형을 단순하게 사용할 수 있게 새로운 자료형으로 만드는 것.

```c
#include <stdio.h>
#include <string.h>

typedef unsigned int UINT;

int main()
{
	UINT uData = 0;

	printf("%d\n", ++uData);
}
```

<br/>

### 열거형상수

숫자에 이름을 붙인 상수. 실질적으론 int형 자료가 됨.

아무런 값을 붙이지 않았다면 0부터 시작하며 만약 특정한 값을 붙이고 싶다면 **상숫값 = 정수** 형식으로 정의해준다. 값을 새로 정의해주면 뒤에는 자동으로 +1 되어 값이 부여됨.

```c
#include <stdio.h>

enum ACTION {MOVE, JUMP, ATTCK};
typedef enum COLOR { RED = 100, GREEN, BLUE } COLOR;

int main()
{
	enum ACTION action = MOVE;
	COLOR color = GREEN;

	printf("action: %d, color: %d\n", action, color);
}
```

<br/>

<br/>

<br/>

📙 **출처**

> 열혈강의 최호성의 C프로그래밍

