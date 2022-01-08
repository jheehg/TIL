### Array.prototype.sort()

<br/>

<br/>

> 설명

✓ 배열의 요소를 적절한 위치에 정렬 후 반환함

✓ compareFunction (비교함수) 를 생략할 경우, 각 요소를 문자열 변환하여 유니코드 코드 포인트 값에 따라 정렬 ( ex.  "10000" > "80" )

<br/>

> 반환값

정렬한 배열. 기존 배열이 정렬되는 것으로 복사본이 만들어지는게 아님.

<br/>

> 비교함수 반환값에 따른 정렬

 ```compareFunction(a, b) < 0```  ➡  ascending order

 ```compareFunction(a, b) > 0```  ➡  descending order

 ```compareFunction(a, b) === 0```  ➡  변경 없음 (모든 브라우저가 변경없음을 보장하는 것은 아님)

<br/>

⚠️

<u>문자열은  ```a > b ```로 비교함.  ( ```a - b``` 의 경우, NaN을 반환. 숫자는 가능.)</u>

<br/>

> 숫자 정렬

```javascript
let numArr = [5, 3, 100, 44, 1];
numArr.sort((a, b) => a - b);
console.log(numArr); // [1, 3, 5, 44, 100]

/*
반환값이 0보다 작으면 a의 인덱스가 작은 순으로 정렬.
5 - 3 > 0   ==> 둘의 순서를 변경
3 - 100 < 0 ==> 순서 변경 없음
...
*/
```

<br/>

> 문자열 정렬

```javascript
let charArr = ["a", "d", "c", "a", "z", "g"];
charArr.sort((a, b) => a > b);
console.log(charArr); // [1, 3, 5, 44, 100]

/*
반환값이 0보다 작으면 a의 인덱스가 작은 순으로 정렬.
'a' > 'd' // false(0)  ==> 순서 변경 없음
'd' > 'c' // true(1)   ==> 둘의 순서를 변경
...
*/
```



<br/>

<br/>

References.

https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Array/sort



























