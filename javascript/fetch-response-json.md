### fetch() 사용 시 주의할 점

<br/>

**fetch()로 API로부터 결과를 가져오는 컴포넌트 사용 시 리턴하는 객체 타입 주의하기**

```javascript
export const requestAPI = async (URL) => {
    const response = await fetch(URL);
    console.log(response); // Response 객체 리턴
    return response;
}

```

**그리고 이 리턴한 결과를 다른 컴포넌트에서 사용하려 할 때 문제가 됨**

```javascript

export default function ProductListPage ({app, URL}) {
   // code ...

    this.setRequest = () => {
        return new Promise((resolve, reject) => {
            const response = requestAPI(URL);
            console.log(response);
            resolve(response.json()); // error: response는 json이라는 function이 없음
        })
    }

}
```

<br/>

**실제 리턴하는 객체 확인해보면 requestAPI 함수에서 리턴 시 async/await 사용으로 리턴한 결과가 Response에서 Promise로 바뀜**

**Response 그대로 사용하고 싶으면 비동기 함수 내에서 json() 호출해줘야 함**



Reference.

[async와 await를 사용하여 비동기 프로그래밍을 쉽게 만들기 | MDN](https://developer.mozilla.org/ko/docs/conflicting/Learn/JavaScript/Asynchronous/Promises)


