#### ReactDOM.createPortal()
```js
ReactDOM.createPortal(child, container);
```
- child: element 또는 fragment 같은 렌더링이 가능한 child.
- container: DOM element
<br>

#### 용도
- 부모 컴포넌트의 DOM 계층 구조 외부에 새로 DOM 노드를 생성해서 렌더링 하는 방법.
- 부모 컴포넌트에 시각적으로 overlay 되어 보여야 하는 경우에 사용. ex) modal, tooltip, dialog...
<br>

#### 장점
- DOM 트리 위치와 상관없이 **portal은 여전히 React 트리에 존재**하므로 독립적인 구조를 갖추면서도 동일한 결과를 가질 수 있다.
- portal로 DOM element를 구분했던 안했던 이벤트 버블링이 여전히 가능하다. (portal 내부에서 발생한 이벤트는 React트리에 포함된 상위로 전파된다.)
<br>

#### 사용법
- DOM element에 portal을 사용할 DOM element를 생성한다.
```html
<!-- in index,html -->
<body>
	<noscript>You need to enable JavaScript to run this app.</noscript>
	<div id="backdrop-root"></div>
	<div id="overlay-root"></div>
	<div id="root"></div>
</body>
<!-- ... -->
```

- ReactDOM.createPortal() 함수에 사용할 child element와 index.html에서 생성한 DOM element를 파라미터로 넣고 호출한다.
```js

// in ErrorModal.js

const ErrorModal = (props) => {

return (
  <>
    {ReactDOM.createPortal(
     <Backdrop onConfirm={props.onConfirm} />,
     document.getElementById('backdrop-root'))}
    {ReactDOM.createPortal(
     <ModalOverlay
      title={props.title}
      message={props.message}
      onConfirm={props.onConfirm}/>,
     document.getElementById('overlay-root'))}
   </>
);
```
<br><br>

#### 출처
https://ko.reactjs.org/docs/portals.html <br>
[Udemy] React 완벽 가이드 with Redux, Next.js, TypeScript
