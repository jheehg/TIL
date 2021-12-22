### Concurrently

여러가지 명령어를 같이 실행하고 싶을 때 사용함.

<br/>

> 설치

```bash
npm install concurrently --save
```

<br/>

> 사용법

루트디렉토리에 있는 Package.json에서 다음과 같이 설정

```json
"start": "concurrently \"command1 arg\" \"command2 arg\""
```

```json
"start": "concurrently \"npm run backend\" \"npm run start --prefix client\""
```

<br/>

<u>npm run backend</u> 

서버 실행 시 script 내의 "backend" 라는 property를 run한다. (ex. "backend": "nodemon server/index.js")

<u>npm run start -- prefix client</u>

npm run start는 프론트를 돌리기 위한 명령어고 이 명령어는 루트디렉토리에 있는 package.json이 아닌 

**client 디렉토리 내부**에 있는 package.json으로 설정해줘야 하므로 prefix 옵션을 사용한다.

<br/>

<br/>

> 출처

https://www.npmjs.com/package/concurrently