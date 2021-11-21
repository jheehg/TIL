### Knapsack Problem

최대용량 W의 배낭에 각각 정해진 가격과 무게가 있는 n 개의 물건을 넣을 때 얻을 수 있는 maxinum value 구하기.



1. 각 가격과 무게를 배열로 구성한다.  val[0, ..., n-1], wt[0, ... , n-1]
2. W 용량에 맞게 가장 maximum으로 담을 수 있는 val[]의 서브배열을 구성해본다.
3. 물건을 <u>선택함 or 선택하지 않음</u> 두 가지 경우 중 무조건 하나를 골라야 한다. (0-1 property)

```
value[] = {60, 100, 120};
weight[] = {10, 20, 30};
W = 50;

when w = 10, v = 60
	   w = 20, v = 100
	   w = 30, v = 120
	   w = 10+20, v = 60+100
	   w = 10+30, v = 60+120
	   w = 20+30, v = 100+120  --- maximun value
	   w = 10+20+30, w > 50
	   
```





> Approach 1 (Recursion by Brute-Force algorithm : 완전탐색)

물건을 구성할 수 있는 모든 서브배열 케이스를 만든 후, 그 중 가장 maximum 가격을 구한다.

모든 경우의 수는 아래 두 가지 방법을 모두 고려해야 한다.

1. n번째 물건이 반드시 제외되었다고 가정하는 경우, n번째를 제외한 경우를 카운트함.

2. n번째 물건이 반드시 포함되었다고 가정하는 경우,

   n번째 물건의 가격 + n번째를 제외한 나머지 경우를 카운트하되 capacity에서 n번째 물건의 무게를 뺌.

```java
class Knapsack {
	static int max(int a, int b) {
		return (a > b)? a : b;
  }
  
  static int knapsack(int W, int wt[], int val[], int n) {
    // 배열의 length가 0 또는 배낭의 capacity가 0이면 바로 0 리턴.
		if(n == 0 || W == 0) return 0;
    
    // n번째 물건의 무게가 capacity를 넘기면 n-1번째 물건으로 다시 실행.
    if(wt[n-1] > W) {
			return knapsack(W, wt, val, n-1);
    } else {
			return max(
        				val[n-1]  + knapsack(W - wt[n-1], wt, val, n - 1),
                knapsack(W, wt, val, n-1));
    	/*
  
    		 max(120 + knapsack(20, wt, val, 2), knapsack(50, wt, val, 2));
    		 max(120 + 100, 160); -- maximum value : 220
				-> knapsack(20, wt, val, 2);
				 max(100 + knapsack(0, wt, val, 1), knapsack(20, wt, val, 1));
				 max(100 + 0, 60);
				-> knapsack(50, wt, val, 2);
				 max(100 + knapsack(30, wt, val, 1), knapsack(50, wt, val, 1));
				 max(100 + 60, 60);
				-> knapsack(0, wt, val, 1);
 				return 0;
      	-> knapsack(20, wt, val, 1);
    	 	 max(60 + knapsack(10, wt, val, 0), knapsack(20, wt, val, 0));
    	 	 max(60, 0);
    	  -> knapsack(30, wt, val, 1);
    	   max(60 + knapsack(20, wt, val, 0), knapsack(30, wt, val, 0));
    	   max(60, 0);
    	  -> knapsack(50, wt, val, 1);
    	   max(60 + knapsack(50, wt, val, 0), knapsack(60, wt, val, 0));
    	   max(60, 0);
    	  -> knapsack(10, wt, val, 0)
    	  return 0;
    	  -> knapsack(20, wt, val, 0)
    	  return 0;
    	  -> knapsack(20, wt, val, 0)
    	  return 0;
    	  -> knapsack(30, wt, val, 0)
    	  return 0;
    	  -> knapsack(50, wt, val, 0)
    	  return 0;
    	  -> knapsack(60, wt, val, 0)
    	  return 0;
    	  
    	*/
    
    }
  }
  
  public static void main(String[] args) {
		int val[] = new int[] {60, 100, 120};
    int wt[] = new int[] {10, 20, 30};
    int W = 50;
    int n = val.length;
    System.out.println(knapsack(W, wt, val, n));
  }
}
```

**시간복잡도**

(선택한다 or 선택하지 않는다) 두 가지 경우 ^ n => $$O(2^n)$$





> Approach 2 (Dynamic Programming)

답을 구하기 위한 테이블 크기는 dp\[n + 1][w + 1] 로 구성한다.

(무게가 0일경우 AND 아무 물건도 선택하지 않았을 경우도 카운트하기 위해 n, w에 각 1씩 추가해준다.)

```
value[] = {10, 15, 40};
weight[] = {1, 2, 3};
capacity = 6;

      capacity(c)
item   0  1  2  3  4  5  6 
  0    0  0  0  0  0  0  0   -> 아무것도 선택하지 않은 경우 max가격=0
  1    0  10 10 10 10 10 10  -> c=1에 첫번째 물건 가격 10. 최대무게와 상관없이 첫번째물건만 선택할 수 있으므로 max가격=10
  2    0  10 15 25 25 25 25  -> c=2에 두번째 물건 가격 15. c=3은 첫번째, 두번째 다 더해서 넣으면 max가격=25
  3    0  10 15 40 50 55 65  -> c=3의 경우 첫번째+두번째 or 세번째 인데 세번째를 선택할 경우의 가격이 더 크므로 max가격은 40
                                c=4의 경우 첫번째+세번째, max가격은 50
                                c=5의 경우 두번째+세번째, max가격은 55
                                c=6의 경우 첫번째+두번째+세번째, max가격은 65
          											 
          											 ==> capacity 6으로 구성할 수 있는 물건의 최대 가격은 65
```

각 row와 column을 채울 때의 경우의 수(선택한다 or 선택하지 않는다)를 고려해서 max값이 나올 수 있는 선택을 한다.

이걸 코드로 옮기면,

**<u>선택하지 않을경우</u>**  dp\[i-1][j] 값과 동일함. n번째 물건을 선택하기 전 max가격값을 그대로 가져오게 된다.

**<u>선택할 경우</u>**  dp\[i][j] 는 n번째 물건의 가격 + n번째를 반드시 포함하지 않았을 때의 max가격이 된다.



```java
class Knapsack {
	static int max(int a, int b) {
		return (a > b)? a : b;
  }
  
  static int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[][] = new int[n+1][W+1];
    
    // K[][] 테이블 생성 (Bottom-up)
    for(i = 0; i <= n; i++) {
      for(w = 0; w <= W; w++) {
        if(i == 0 || w == 0) K[i][w] = 0;
        else if(wt[i - 1] <= w)
          // 두가지 경우에서 나올 수 있는 가격을 비교하여 더 큰 값을 선택함.
          // 1) n번째물건 가격 + 선택가능한 물건은 n-1번째까지면서 선택가능한 capacity는 n번째물건의 무게를 뺀 capacity값
          // 2) n번째를 선택안한 경우 = n-1번째의 경우에서 얻었던 max무게 값
          K[i][w] = max(val[i-1] + K[i-1][w - wt[i-1]]), K[i-1][w]);
        else 
          // 선택한 물건의 무게가 현재 capacity보다 무겁다면 선택하지 않음.
          K[i][w] = K[i-1][w];
			}
    }
    
    return K[n][W];
  }
  
  public static void main(String[] args) {
		int val[] = new int[] {60, 100, 120};
    int wt[] = new int[] {10, 20, 30};
    int W = 50;
    int n = val.length;
    System.out.println(knapsack(W, wt, val, n));
  }
}
```

**시간복잡도**

O(n*W)





> Approach 3 (Memorization Technique)

```java
class Knapsack {
	static int max(int a, int b) {
		return (a > b)? a : b;
  }
  static int knapsackRec(int W, int wt[], int val[], int n, int dp[][]) {
    if(W == 0 || n == 0) return 0;
    
    if(dp[n][W] != -1) return dp[n][W];
    
    // Approach 1과 동일하게 탐색하지만 차이점은 이미 계산이 되어 값이 있는 경우 (초기값 -1이 아닌경우)
    // 그 값을 그대로 return하므로 불필요한 계산을 생략하게 됨.
    if(wt[n-1] > W) {
      return dp[n][W] = knapsackRec(W, wt, val, n-1, dp);
    } else {
      return dp[n][W] = max(max[n-1] + knapsackRec(W - wt[n-1], wt, val, n-1, dp), 
                          knapsackRec(W, wt, val, n-1, dp));
    }
  }
  
  static int knapsack(int W, int wt[], int val[], int N) {
    int dp[][] = new int[N + 1][W + 1];
    
    for(int i = 0; 1 < N; i++) {
      for(int j = 0; i < W; j++) {
        dp[i][j] = -1; // dp테이블에 초기값 -1을 넣는다.
      }
    }
    return knapsackRec(W, wt, val, N, dp);
  }
  
 public static void main(String[] args) {
		int val[] = new int[] {60, 100, 120};
    int wt[] = new int[] {10, 20, 30};
    int W = 50;
    int n = val.length;
    System.out.println(knapsack(W, wt, val, n));
  }
}
```

**시간복잡도**

O(n*W)







#### **Reference**

https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

https://www.youtube.com/watch?v=rhda6lR5kyQ