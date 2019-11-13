#### @Valid annotation

> entity에서 설정한 값들을 지정할 때 어노테이션을 달아 request 받을 시 유효성을 체크한다.
>
> 오류가 있을 시 그에 맞는 오류 처리가 가능하다.



다음은 entity에서 지정할 수 있는 어노테이션이다.

@AssertFalse : 거짓인지?

@AssertTrue : 참인지?

@DecimalMax : 지정 값 이하의 실수인지?

@DecimalMin : 지정 값 이상의 실수인지?

@Digit(integer=, fraction=) : 정수 여부

@Future : 미래 날짜인지

@Past : 과거 날짜인지

@Max : 최대 지정 값 까지 가능 

@Min :  최소 지정 값 까지 가능

@NotNull : null이 아닌지 체크

@Null : null 인지 체크

@NotEmpty : empy가 아닌지 체크. 문자열

@Size(min=, max=) :  문자열 또는 배열의 길이 만족 여부

@Range(min=, max=) : 숫자 범위 체크

@Email : email형식이 맞는지



> 출처

https://appsnuri.tistory.com/115