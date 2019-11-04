* Get

Get과 같이 결과값이 나오는 테스트 같은 경우 

andExpect() 를 통해 리턴값으로 결과가 맞게 나왔는지 체크한다.

*andExpect(ResultMatcher matcher) => Perform an expectation.*

```java
.andExpect(jsonPath("$.name").value("name"));
  // 결과 값이 json으로 나오므로 json타입을 이용해 결과 값 검증을 함.
  // 여기서 $ = object name = field 
  // value() 에 기대하는 결과값을 넣어 검증을 진행한다. 
  // 또는
.andExpect(jsonPath("$.address").isEmpty());
	// or isNumber(); isEmpty(); 등 타입체크, 빈값 체크도 가능하다  

```

<br/>

<br/>

* post

post 역시 호출하고 난 뒤에 값이 제대로 추가가 됬는지 여부를 확인할 수 없다.

test 에서 확인하는 방법은 여러가지가 있지만 여기서는 간단한 테스트이므로

findAll()을 통해 id를 최신순으로 정렬 후 가장 첫번째 객체를 가져와 그 값을 검증하는 방법으로 진행한다.

assertAll()은 assertThat()을 모두 실행하며 검사 중 실패했을 때 exception을 던지지 않고 모두 검사한다. 

```java
Person result = personRepository.findAll(Sort.by(Sort.Direction.DESC, "id")).get(0);

assertAll(
  ()-> assertThat(result.getName()).isEqualTo("name"),
  ()-> assertThat(result.getHobby()).isEqualTo("hobby"),
);

```

<br/>

<br/>

* Put

수정도 역시 수정을 완료한 다음에 정확한 검증을 위해 findById로 매칭되는 객체를 찾은 후 같은 방법으로 검증

```java
Person result = personRepository.findById(1L).get();
    
assertAll(
  ()->   assertThat(result.getName()).isEqualTo("name"),
  ()->   assertThat(result.getHobby()).isEqualTo("hobby"),
);
```

<br/>

<br/>

* delete

repository를 통해 데이터를 삭제하고 난 후 실제로 데이터가 삭제가 되었는지 검사한다.

stream 클래스의 .anyMatch() 를 통해  이미 삭제된 목록에 데이터가 존재하는 지 확인하고

그에 해당하는 결과로 boolean값을 리턴한다. 여기서는 삭제된 목록에 있어야 하므로  assertTrue()로 검사.

```java
assertTrue(personRepository.findPeopleDeleted().stream()
        									 .anyMatch(person -> person.getId().equals(1L)));

```

<br/>

<br/>

* ObjectMapper

```java
@Autowired
private ObjectMapper objectMapper;

private String toJsonString(Object object) throws JsonProcessingException {
        return objectMapper.writeValueAsString(object);
}
```

위와 같이 메서드를 생성해 놓으면 json형태의 문자열을 content()에 넣어주지 않아도

데이터가 담긴 객체 생성 후에 인자로 넘기면 jsonString으로 파싱해주는 기능을 한다.

```java
.content(toJsonString(object)
```

<br/>

<br/>

* 출처

패스트캠퍼스 자바 웹 개발 마스터

