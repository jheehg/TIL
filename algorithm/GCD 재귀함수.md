### GCD 재귀함수



**a, b 두 수의 최대공약수 구하기**

1. a, b 중 큰 수를 작은 수로 나눔.

   (ex. a > b면, a % b == 0일때, b가 최대공약수)

2. 1번 과정에서 나온 나머지가 0이 아니라면,

   a 에 b 대입.

   b 는 1번 과정에서 나온 나머지 대입.

3. 두 수를 나눈 나머지가 0이 나올때까지 2번 과정 계속 반복.

   

<u>방법 1) 반복문</u>

```java
public int gcd_itr(int a, int b) {
  while(b != 0) {
    b = a % b;
    a = b;
  }
  return b;
}

```



<u>방법 2) 재귀함수</u>

```java
public int gcd_recur(int a, int b) {
  return (a % b == 0)? b : gcd_recur(b, a % b); 
}
```



