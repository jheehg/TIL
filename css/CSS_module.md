⚠️ css파일로 styling을 할때의 scoping 문제점을 보완
- styled-components
- CSS module
<br>

#### CSS module?
CRA로 만든 프로젝트에서는 확장자를 ```.module.css```로 한다.

```css
/* in Button.module.css */

.Button {
	width: 100%;
	padding: 0.5rem 1.5rem;
	border: 1px solid #8b005d;
	color: white;
	background: #8b005d;
	box-shadow: 0 0 4px rgba(0, 0, 0, 0.26);
	cursor: pointer;
}
```

```js
/* in Button.js */

import React from "react";
import styles from './Button.module.css';

const Button = props => {
	return (
		<button type={props.type} className={styles.button}>
			{props.children}
		</button>
	);
};

export default Button;
```

결과는 default CSS file을 사용한 것과 동일하지만,
차이점은 class명이 ```CSS module명_class명_해쉬값``` 으로 생성된다는 점이다. 
<br><br>

#### 동적 Styling
```css
/* in CourseInput.module.css */

.form-control input {
	display: block;
	width: 100%;
	border: 1px solid #ccc;
	background-color: transparent;
	padding: 0 0.25rem;
}

.form-control.invalid input {
	border: 1px solid red;
	background-color: salmon;
}
```

- ```isValid``` 값에 따라 invalid 클래스가 추가되며 그에 맞는 styling이 적용된다.
- 여러 클래스를 동시에 적용하고 싶을때 backtick으로 클래스명을 나열해준다.

```js
/* in CourseInput.js */

import React from "react";
import styles from './CourseInput.module.css';

const CourseInput = props => {
	// code..
	return (
		<form>
			<div className={`${styles['form-control']} ${!isValid && styles.invalid}`}>
				<label className={`${styles['form-control']} ${!isValid && styles.invalid}`}>
          Course Goal
         </label>
				<input type="text" onChange={goalInputChangeHandler} />
			</div>
			<Button type="submit">Add Goal</Button>
		</form>
	);
};

export default CourseInput;
```
<br>

#### CSS module 장점
- default CSS file을 따로 구분해서 사용이 가능하다.
- module 파일명에 따라 해쉬값을 통해 클래스명을 지정하기 때문에 CSS 파일 내부에 클래스명이 동일해도 중복 적용되지 않는다.

<br>

#### 출처
[Udemy] React 완벽 가이드 with Redux, Next.js, TypeScript
