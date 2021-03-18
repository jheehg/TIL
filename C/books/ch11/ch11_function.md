## ch11. 함수



#### 함수의 구성

main함수 위로 TestFunc함수의 선언이 없었다면 컴파일 오류 발생.

```c
# include <stdio.h>

int TestFunc(int); // ***

void main(void)
{
	TestFunc(5);
  TestFunc(15);
}

int TestFunc(int nData)
{
  if(nData > 10)
  {
    puts("OK");
    return 1;
  }
  puts("return");
  return 0;
}
```



#### 스택과 스코프

함수의 두인자 중 **오른쪽 인자**부터 차례대로 스택에 먼저 들어가게 됨.

함수를 호출하면 호출받은 함수가 반환하기 전까지 호출자의 스택은 계속 쌓이게 된다.

(스택이 늘어나는 주소 방향은 마이너스 방향) ⁇

일정범위 이상 스택이 커지면 메모리 오류 발생 => Stack Overflow





#### 함수의 설계 원칙

- 함수 이름이 길어지더라도 이름에 함수의 기능 명시
- 두 줄 이상의 코드가 같은 구조로 2회이상 반복 시 함수로 만들기
- 특정 기능이 다른 프로그램에서 사용가능성이 있을 때 고려하기
- 함수 내부에서 메시지를 출력하지 말고 **반환값**에 여러 의미 부여하기

- 매개 변수가 너무 많으면 구조체를 활용을 검토하기
- 함수의 정의 부분이 자신이 주로 사용하는 편집기를 기준으로 두페이지가 넘으면 두 함수로 분할하기
- 별도의 라이브러리를 통째로 만들 시 함수이름 앞에 라이브러리를 의미하는 전치사 붙이기





#### 매개변수의 전달 방식

함수를 호출하는 쪽 데이터의 변경 여부로 값 호출(Call by value) 방식, 참조 호출(Call by reference) 로 나뉨.



> 값 호출 방식(Call by value)

원본 메모리와 똑같이 복사된 메모리가 추가로 할당되어 원본 데이터는 그대로 남고 복사본 데이터는 피호출자의 매개변수로 넘겨짐. 피호출자 내에서 변경이 있더라도 <u>원본에 영향을 주지 않음</u>.

```c
#include <stdio.h>

void Swap(int nA, int nB)
{
	int nTmp = 0;
	nTmp = nA;
	nA = nB;
	nB = nTmp;
}

void main(void)
{
	int x = 5, y = 9;
	Swap(x, y);
	printf("%d, %d\n", x, y);   // 5, 9
}
```

Swap 함수 내부에서 사용되었던 변수가 함수를 끝내는 스코프를 만나면서 모두 사라짐.





> 참조 호출 방식 (Call by reference)

함수로 매개 변수 전달 시 원본 데이터를 전달. 복사본 이용하지 않고 원본 메모리 그대로 참조함.

참조 호출 방식 구현을 위해 메모리의 값이 아닌 <u>주소</u>를 전달함. (= Call by address)

```c
#include <stdio.h>

void Swap(int* pnA, int* inB)
{
	int nTmp = 0;
	nTmp = *pnA;
	*pnA = *pnB;
	*pnB = nTmp;
}

void main(void)
{
	int x = 5, y = 9;
	Swap(&x, &y);
	printf("%d, %d\n", x, y);   // 9, 5
}
```







📙 출처

> 열혈강의 최호성의 C프로그래밍