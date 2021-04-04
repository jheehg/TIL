## ch17. 기본 자료구조

### 선형구조(Linear Structure)

##### 스택(Stack)

- LIFO (Last In First Out)
- c언어에서 지역변수와 자동변수는 스택으로 운영되는 메모리에 할당
- 실행 취소(Undo) 같은 기능을 구현 시 유용
- 배열이나 연결리스트로 구현할 수 있음

<br/>

##### 큐(Queue)

- FIFO(First In First Out)
- 사용자의 키보드 입력 정보는 큐로 관리
- 배열이나 연결리스트로 구현할 수 있음

<br/>

##### 연결리스트(Linked List)

- 자료를 가진 부분, 순서 상 다음에 위치하는 자료가 저장된 메모리에 대한 포인터로 이루어진 노드를 사슬처럼 묶어놓은 자료구조
- 포인터 정보가 한 방향이면 단순 연결 리스트, 양방향이면 이중 연결 리스트
- 자료 추가 또는 삭제가 매우 쉬움
- 배열에 비해 구현하기 어려움

<br/>

<br/>

### 정렬

##### 선택 정렬(Selection Sort)

```c
#include <stdio.h>

void PrintData(int *pnData);
{
  	int i = 0;
  	for(i = 0; i < 5; ++i)
    	printf("%d\t", pnData[i]);
  	printf("\n");
}

int main()
{
    int anData[5] = {4, 2, 5, 1, 3};
    
    int i = 0, j = 0, min = 0, tmp = 0;
    for(i = 0; i < 4; ++i)
    {
        min = i;
        for(j = i + 1; j < 5; ++j)
        {
            if(anData[j] < anData[min]) min = j;
        } 
      	tmp = anData[i];
      	anData[i] = anData[min];
      	anData[min] = tmp;
      	
 	      PrintData(anData); 
    } 
    
    return 0;
}
```

선택 정렬과 버블 정렬이 효율이 좋지 않은 이유는, 정렬이 완료되지 않은 나머지 숫자들이 실제로는 정렬된 상태라 해도 정렬을 시도하기 때문임. 좋은 알고리즘은 최대한 연산을 적게 수행 하는 것.

<br/>

##### 버블 정렬(Bubble Sort)

선택정렬과 비슷하지만 오른쪽으로 정렬된다는 점과 비교조건을 만족하는 경우 **매번** 변수를 교환한다는 점이 다름.

```c
#include <stdio.h>

void PrintData(int *pnData);
{
  	int i = 0;
  	for(i = 0; i < 5; ++i)
    	printf("%d\t", pnData[i]);
  	printf("\n");
}

int main()
{
    int anData[5] = {4, 2, 5, 1, 3};
    int i = 0, j = 0, tmp = 0;
    
    for(i = 4; i >= 1; --i)
    {
        for(j = 0; j < i; ++j)
        {
            if(anData[j] > anData[j + 1])
            {
                tmp = anData[j];
                anData[j] = anData[j + 1];
                anData[j + 1] = tmp;
            }
        }
      	printData(anData);
    }
    return 0;
}
```

<br/>

<br/>

📙 **출처**

> 열혈강의 최호성의 C프로그래밍