#### useEffect() 에서 unmount 관리

`useEffect` 에서는 함수를 리턴함으로써 `unmount` 시 필요한 처리를 할 수 있는데 이때 리턴해주는 함수를 `cleanup` 함수라고 부른다.<br>
이와 같은 작업을 하면 `useEffect` 에서 처리된 작업들이 더이상 필요없을 때 정리해줄 수 있다.<br>

아래 `useEffect` 함수에서 setTimeout()함수를 생성하고 unmount할때 clear해줘서 더이상 쓰지 않는 타이머를 삭제해주는 처리를 하고 있다.<br>

```js
useEffect(() => {

	if(items.length === 0) {
		return;

	} else {
		setBtnHighlighted(true);
		const timer = setTimeout(() => setBtnHighlighted(false), 300);

		return () => clearTimeout(timer);
	}

}, [items]);
```

<br><br>
#### 출처<br>
https://react.vlpt.us/basic/16-useEffect.html
