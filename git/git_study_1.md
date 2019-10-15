### Git 사용법 정리 (1)

> 생활코딩 - 지옥에서 온 git 강의를 듣고 입문자 입장에서 공부한 내용을 정리한 글

<br/>

* 사용 프로그램

  - Sourcetree  :  git 버전 관리를 보다 쉽게 도와주는 GUI프로그램 

    ​                       프로젝트의 규모에 따른 적절한 git기능을 활용해야 함 

    ​                       운영체제마다 UI의 차이가 있다.

  - Beyond Compare :  커밋 시 충돌하는 두 파일의 차이점을 분석하는 프로그램.

    ​                                  ( 당장 사용할 일은 없겠지만 알아두기 )



❗️GUI 프로그램 외에도  git을 터미널로 제어하는 방법 또한 알아둬야 한다.

<br/>

<br/>

#### sourcetree에 bookmark하기

1. new - Create Local Repository 

   로컬에서 생성한 파일을 북마크 목록에 추가한다.

   or

2. new - Add Existing Local Repository

   이미 저장소가 만들어진 파일을 북마크 목록에 추가한다.

<br/>

<br/>

#### 버전 생성하기

* 로컬에서 저장소가 있는 폴더에 파일을 추가하면 sourcetree 좌측 목록 중 File status에 unstaged 목록에 생성된다.

* 체크박스에 체크를 하면 해당 파일이 stage area에 올라간다.

* 프로그램 하단에 commit message 작성 후 commit 버튼을 누른다. => **하나의 버전이 생성됨.**

  or

  ```
  git add <파일명>
  git commit -m "커밋메시지"
  ```

  -m ( only for file on staging area )

<br/>

<br/>

#### 기본적 구조

* Branches

  master 에서 커밋한 파일들을 관리. 

  분리된 작업영역으로 여러 버전을 독립적으로 관리할 수 있다.

* Project Directory

  1. Working Directory ( 실제 작업 내역 )

     Stage area ( working directory -> stage area 로 **add** :  commit할 파일들의 대기소 )

  2. Repository.git
  
     id ( 고유식별값 ) ⭐️
  
     parent: 현재 master인 대상의 parent ( 바로 전에 커밋했던 대상 )
  
     message
  
     tree ( stage area의 snapshot )
  
* Master 

  리스트상 **첫번째**에 있는 대상 ( 가장 최근에 커밋한 대상 )

* Head

  Head -> Master ( 기본적으로 head는 master를 경유하여 대상을 가리킴 )

<br/>

<br/>

#### 버전 복원하기

* checkout

  sourcetree에서 더블클릭으로 실행 또는 오른쪽 마우스 클릭 후 checkout

  checkout한 대상의 시점에 저장 했던 버전으로 다시 복귀

  ( 그 시점에 저장했던 tree = snapshot 을 기존 working directory에 가져옴 )

  checkout하면 Head가 가리키는 대상이 checkout한 대상으로 바뀌는데

  이 때 master를 경유하지 않고 head가 바로 checkout한 대상을 가리키게 된다.

* detached head

  head가 가장 최근에 커밋한 시점을 가리키는게 아닌 상태를

  “HEAD가 BRANCH로 부터 DETACHED된 상태” 라고 한다.

  head가 master(branch)를 가리키고 있지 않으면 detached 상태이며 버전 수정 중임을 의미한다.

   즉, 현재 진행단계를 알고싶으면 head를 찾으면 된다.

* detached상태에서 원래로 돌아가기

   현재 master인 대상을 git checkout master를 해주면 다시 head가 master를 가리키게    된다.

   ( 마지막 커밋이 만들어진 시점으로 돌아감 )

   Head가 master(branch)를 가리키고 있는 attached상태로 된다.

   꼭 attached 상태로 돌리고 작업 시작해서 사고 예방하기 ( 반드시는 아니지만 초보자에게는 권장 )

* 만약 detached상태에서 commit한다면?

   ```C <- B <- A ```

   1. 기존에 시간의 흐름대로 커밋된 타임라인

   ```D   C  <- B <- A```
   
   <---------------------- (  기존 커밋기록인 A로부터 뻗어나온 타임라인 )
   
   2. 현재 head가 가리키는 대상으로부터 나온 타임라인

   <br/>

   현재 head가 가리키는 대상으로부터 타임라인이 하나 더 생성된다.

   ( sourcetree에서 보면 1의 타임라인이 빨간 줄로 나타나고 warning message를 띄우니 확인해보기 )

   이 상태로 checkout master 를 하게 되면 Head가 다시 가장 최근 커밋 ( C ) 을 가리키게 되는데
   
   문제점은 log를 제대로 기록하지 않아서 기존에 추가된 ( D이후 생성된 ) 타임라인의 커밋이 아예 사라지게 된다.

<br/>

<br/>

#### 버전 삭제하기

* reset 

   오른쪽 클릭 - **reset master to this commit**

   or

   ```
   git --hard reset <커밋아이디>
   ```

   옵션으로는 --hard, --soft, --mixed 가 있음.

   head가 가리키는 branch(master)를 바꾸어 커밋 대상을 바꾼다.

   기존에 최근커밋이었던 대상을 가리키고 있다가 reset 후에 가리키는 대상이 바뀌면 

   최근 커밋은 삭제. ( 눈에 보이지 않을 뿐이지 진짜 없어진 건 아님 )

   만약 실수로 reset 했다면 다시 reset 명령어로 (특정 커밋아이디 지정) 복구할수 있다.


