### Spring Security 403 error

spring security 라이브러리를 설정한 프로젝트에서 어떠한 요청에도 계속 403 error을 발생시킴

java.lang.AbstractMethodError 로 이유를 찾아보고 두가지를 원인으로 짐작했었다.

1. dependency의 버전 충돌
2. csrf 활성화

h2-console url을 요청했을 때 로그인 창으로 이동되어서 아이디와 비밀번호까지 입력하고 들어갔는데도,

결국 403 error가 났었다.

하지만, 이미 build.gradle에서는 ```apply plugin: 'io.spring.dependency-management'``` 라는

dependency를 관리해주는 플러그인이 존재했고 

SecurityConfig class에서도 ```csrf().disable()``` 을 해준 상태였다.

계속 오류가 났던 이유는 다음과 같다.

```java
@Configuration
@EnableWebSecurity
public class SecurityConfig extends WebSecurityConfigurerAdapter {

    @Value("${jwt.secret}") // value설정 오류
    private String secret;
  	...
}
```

```application.yml``` 안에 jwt에서 사용할 키를 지정해주었는데 spring 부터 써주지 않아서

지정한 value값을 찾지 못해 발생된 것이다.

Security 사용한 뒤부터 계속 같은 오류였는데 드디어 찾음....😱

==> ( 꼭 spring으로 지정해야 하는 건 아니고 jwt.secret / security.jwt.secret 등으로 해도 되지만

​		어떻게 지정해야 맞는 방법인지 잘 모르겠다. 이 부분은 더 찾아봐야 겠다.

​		오류난 시점의 설정이 spring의 하위 속성으로 있었기때문에 아예 spring에서 빼주고 jwt.secret으로 변경했다 )

Spring security는 로그인 처리하는 부분 더 공부하면서 이해해야 할 것 같다 

