#### spring boot JPA 서비스로직

<br/>

데이터 요청과 전송은 Header 클래스를 통해 이루어진다.

request, response에 사용되는 데이터는 클래스를 나누어 따로 관리하고 각 클래스를 Header의 필드로 지정한다.

<br/>

**com.example.study.controller.api**

**+--- UserApiController**

**+---ItemApiController**

**+--- xxxApiController**

들어온 요청에 따라 위 패키지 내의 Controller를 통해 맵핑된 각 메서드가 실행된다.

이때 받는 요청 또한 Header클래스에 request타입으로 지정해서 받게 되고 

받은 객체에 대해서는 LogicService의 메서드로 넘겨준다.

LogicService는 받은 데이터를 어떻게 처리할건지에 관한 **실질적 로직**이 진행되는 역할, 

ApiController는 클라이언트로부터 그에 맞는**요청을 받아 넘겨주는** 역할을 하게 된다.

<br/>

**com.example.study.service**

**+--- UserApiLogicService**

**+--- ItemApiLogicService**

**+--- xxxLogicService**

<br/>

service클래스에서 요청을 받으면 Header클래스 내의 필드인 data로 처리하게 된다.

**(❗️data가 클라이언트의 요청 데이터를 담고있는 객체)**

Repository에 넘겨줄 새 객체를 생성한다

새 객체에 넣어줄 인자들은 요청온 데이터를 하나씩 getter()로 셋팅시킨다.

Repository. save() 를 통해 DB에 데이터를 저장한다.

처리 후 리턴한 객체를 새 객체를 선언해 담게 되고 ( 기존 객체 사용 x )

**최종적으로 얻은 결과를 Header클래스를 통해서 response를 전송**

<br/>

<br/>

패스트캠퍼스 자바 웹 개발 마스터 강의를 듣고 공부한 내용을 정리했습니다. 

