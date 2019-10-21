### JPA연관관계 설정

*N : M 관계 일 경우에는 교차 테이블을 중간에 둬야 함*

>  사용 데이터베이스 : mySQL

<br/>

table -> erd 관계 설정

탑메뉴에서  database - reverse engineer - 계정 정보 입력, 사용할 스키마 선택하고 완료버튼

erd -> table로 가져오기

탑메뉴에서  database - forward engineer - 계정정보 입력, 

외래키 설정 여부나, 기존에 설정한 테이블 drop할건지 등 여부 체크해주고 확인한 후 계정 자체를 다시 시작하면 적용된다.

이 방법 말고도 직접 메인페이지에서 테이블 추가 해줘도 된다.



```java
// 1 : N
@OneToMany(fetch = FetchType.LAZY, mappedBy = "{object}")
```

1 : N ->  @OneToMany 어노테이션을 붙임

mappedBy 의 값은 여기서 N 의 입장인 클래스 내 @ManyToOne 어노테이션을 붙인 필드의 명을 그대로 써주면 된다.

( 꼭 매칭시켜야  함 )

One의 대상이 되는 객체를 통해 여러 튜플(데이터) 조회가 가능하다. 보통 List로 조회.

```java
@ManyToOne // N : 1 해당 클래스를 기준으로 잡으면 됨 
private User user; // user_id
//userid가 아닌 User객체로 잡아야 함. hibernate에서 알아서 userid를 찾아간다
```



@OneToOne

@OneToMany

@ManyToOne

@ManyToMany

4가지 어노테이션으로 관계를 설정한다.



> 1 : N 에서 1의 입장이면 (List 사이즈 상관없이)무조건 List 타입으로 데이터를 가져올 것이고,
>
> N : 1 에서 N의 입장이면 무조건 딱 하나의 튜플 = 객체 를 가져올 것이다.



#### JPA장점이자 특징

1. 쿼리문을 써서 여러 테이블을 조인할 필요가 없다.

2. 대신 체이닝 방식을 통해서 필요한 데이터가 나올때까지 연결해서 접근이 가능하다.

   => 1: N, N:1 관계만 잘 이해하면 여러 조인 필요없이 체이닝방식을 사용하면 된다.

<br/>
<br/>

패스트캠퍼스 자바 웹 개발 마스터 강의를 듣고 공부한 내용을 정리했습니다. 





