### Promise

**비동기 처리 상태와 처리 결과를 관리하는 객체**

<br/>

> Promise 기본구조

```javascript
new Promise((resolve, reject) => {
    if(/* 비동기 처리 성공 시 */) resolve('success');
    else if(/* 비동기 처리 실패 시 */) reject('failure');
}
```

✓ 비동기 처리 성공 시 처리 결과를 resolve함수에 인수로 전달하면서 호출, 실패 시 reject 함수 호출

<br/>

> fetch 사용

```javascript
function listPage(URL) {
    return new Promise((resolve, reject) => {
        fetch(URL)
        .then(response => response.json())
        .then(data => resolve(data))
        .catch(error => reject(error));
    });
}; 
```

<br/>

> Promise의 비동기 처리 상태 정보

| 상태정보      | 의미                | 상태변경조건          |
| --------- | ----------------- | --------------- |
| pending   | 비동기처리가 수행되기 전 상태 | Promise가 실행된 직후 |
| fulfilled | 비동기처리가 수행된 상태(성공) | resolve함수 호출    |
| rejected  | 비동기처리가 수행된 상태(실패) | reject함수 호출     |

<br/>

> Promise 후속처리 메서드

```javascript
// Promise.prototype.then
// 첫번째 인자 : 성공 시 처리할 콜백함수.
// 두번쨰 인자 : 실패 시 처리할 콜백함수.
new Promise(resolve => resolve('result'))
.then(v => console.log(v), e => console.error(e));

// Promise.prototype.catch
// reject일 경우에만 호출된다.

// Promise.prototype.finally
// resolve, reject 상관없이 무조건 호출된다.
new Promise(resolve => resolve('result'))
.then(v => console.log(v))
.catch(e => console.error(e))
.finally(() => console.log('end'));
```

<br/>

> Promise 에러 처리

✓ Promise.prototype.then 메서드도 두번째 콜백함수로 에러 처리를 할 수 있지만, Promise.prototype.catch 메서드를 사용할 경우 Promise객체 내부 뿐 아니라 <u>then 메서드 내 에러도 잡을 수 있으므로</u> 에러 처리는 **catch메서드**로 하는것을 권장.

<br/>

> Promise 병렬처리 기본 구조

```javascript
const p1 = new Promise(resolve => resolve(1));
const p2 = new Promise(resolve => resolve(3));
const p3 = new Promise(resolve => resolve(5));

Promise.all([p1, p2, p3])
.then(v => console.log(v)); // [1, 3, 5]
```

<br/>

> Promise 병렬처리로 api 호출

```javascript
const products_cart = JSON.parse(localStorage.getItem('products_cart')) || [];

function cartPage(URL) {
    let pid_list = products_cart.map(item => item.productId);
    // 각 상품 id마다 따로 api를 호출하려 함.
    // api를 호출하는 비동기 처리 함수를 담은 배열을 인자로 전달.
    return Promise.all(pid_list.map(pid => cartPageResult(URL, pid)));
};

function cartPageResult(URL, pid) {
    return new Promise((resolve, reject) => {
        
        fetch(`${URL}/${pid}`).then(response => response.json())
        .then(data => {
            /* 각 상품id에 맵핑된 정보 처리하는 코드 */
            resolve(data);
  
        }).catch(e => {
            console.error('Error:', e);
            reject(e);
      });
  });
}; 

// 성공적으로 비동기처리 된 결과를 담아 배열로 전달된다.
cartPage(URL)
.then(v => console.log(v))
.catch(e => console.error(e));

```

<br/>

<br/>



**Reference.**

**[도서] 모던 자바스크립트 딥다이브**


