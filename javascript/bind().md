#### bind() 알아둬야 할 점
bind 메서드는 파라미터로 `this` 에 해당하는 객체를 넣고 호출을 바로 하지만<br>
리턴값이 그 함수를 호출한 리턴값이 아닌 지정한 `this` 값 및 초기 인수를 파라미터로 사용하는 변경된 원본 함수의 복제본이다.

#### 함수 props에서의 활용
함수 자체를 prop으로 넘기는 것이기 때문에 함수를 호출한 리턴값이 되면 안되고 함수 자체로 넘겨줘야 한다.<br>
만약 넘겨줘야 하는 함수에 동적으로 파라미터를 넣어줘야 하는 상황이라면,

1) 콜백함수를 사용한다.
2) bind() 메서드를 사용한다.

```js
const cartItems =
	<ul className={classes['cart-items']}>
	{cartCxt.items.map((item, id) => {
		return <CartItem key={id}
			name={item.name}
			price={item.price}
			onRemove={() => removeItemHandler(item)}
			onAdd={() => addItemHandler(item)}/>;
	})}
	</ul>;
```
OR
```js
const cartItems =
	<ul className={classes['cart-items']}>
	{cartCxt.items.map((item, id) => {
		return <CartItem key={id}
			name={item.name}
			price={item.price}
			onRemove={removeItemHandler.bind(null, item)}
			onAdd={addItemHandler.bind(null, item)}/>;
	})}
	</ul>;

```
