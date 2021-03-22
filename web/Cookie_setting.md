## 🍪 쿠키 셋팅 및 확인 방법



### # set

```javascript
// setting
let date = new Date(Date.now() + 86400e3);
date = date.toUTCString();
document.cookie = "user=john; expires="+ data +"; path=/;";
```

<br/>

### # remove 

1. Javascript

```javascript
//remove
document.cookie = "user=john; max-age=0;"; // or 음수값 지정
```

OR

2.  Java

```java
//remove
Cookie[] cookies = request.getCookies();
if(cookies != null) {
	String cookieName = null;
  for(Cookie c : cookies) {
		cookieName = c.getName().replaceAll("\\r","").replaceAll("\\n","");
    	Cookie newCookie = new Cookie(cookieName, null);
		
		newCookie.setMaxAge(0);
		newCookie.setPath("/");
		newCookie.setDomain(".abc.com");
		newCookie.addCookie(newCookie);
	}
}
```

<br/>

### # Attribute

**expires/max-age**

세팅 안되어있으면 session cookie로 지정되어 브라우저 창 닫으면 쿠키 삭제됨.

expires/max-age 모두 지정되어 있는 경우 <u>Max-Age의 값이 적용됨</u>.

0 또는 음수의 값으로 지정할 경우 즉시 만료됨.



**path**

기본경로 = ```/```  이며 해당경로 또는 그 하위경로로만 전송 가능.

<br/>

**domain**

하위도메인 전송 설정 시 ".domain.com" 으로 설정가능.

옵션 설정 없으면 현재 도메인으로 설정됨.

**쿠키가 세팅된 도메인이 다를경우 전송이 안될수 있으므로 하위 도메인 지정이**

**필요할 경우 반드시 해줘야 전송 가능. (\** 쿠키 전송 안될경우 이 attribute 먼저 체크해보기)**

<br/>

**secure**

HTTPS 프로토콜 사용 시에만 전송 가능.

<br/>

**samesite**

XSRF 공격을 막기위한 옵션 (이론상으론 가능하다고 함)

```
//3rd party damain의 요청 허용여부에 따라 3가지 옵션으로 나눠짐
//IE는 samesite 미지원

samesite=strict   // 허용안함
samesite=lax      // 해당 옵션지정 없을경우 default값임 (2020년 크롬 적용)
samesite=none     // 허용. Secure 옵션과 반드시 같이 사용.

```

```samesite=lax``` 은 다음과 같은 경우에 쿠키 전송 허용.

1. 안전한 HTTP의 경우 (GET방식만 허용)
2. 작업이 최상의 탐색에서 이뤄질때

(외부사이트에서 form 전송 또는 ajax 요청 시에는 이뤄지지 않음)

<br/>

**httpOnly**

클라이언트 측에서 document.cookie를 볼수 없게 함.

<br/>

### # 브라우저에서 확인 방법

**IE/EDGE**

F12(개발자도구) → 네트워크 → 목록에서 요청내역 클릭 → 우측 쿠키탭 클릭 → 확인

**CHROME**

F12(개발자도구) → application → Storage 하위메뉴 cookies 클릭 → 확인

<br/>

### # 쿠키 로컬경로

**IE**

```
인터넷옵션 → 일반탭-검색기록 → 설정 클릭 → 웹사이트 데이터설정-임시인터넷파일의 현재위치 확인 또는 
c:\Users\사용자\Appdata\Local\Microsoft\Windows\INetCache\
```

**CHROME**

```
c:\Users\사용자\Appdata\Local\Google\Chrome\User Data\Default\ 내 Cookies 파일 확인
```

(파일이 sqlLite형식인데 어떻게 확인하는지....👀)

chrome의 경우 유저파일을 저장하는 경로를 새로 지정해주면 독립적으로 사용할 수 있음.

💭 윈도우키 + R → chrome.exe —user-data-dir="C:\\temp\\(파일명)" 으로 실행.

(IE처럼 세션 간 데이터를 공유하는 방법을 찾아보았으나 그렇게 작동이 되지 않는 듯 하다...)





### # 참고 자료

> https://ko.javascript.info/cookie
>
> https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Set-Cookie