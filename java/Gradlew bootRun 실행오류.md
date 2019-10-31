### Gradlew bootRun 실행오류

<br/>

지금까지 계속 eclipse로만 학습해왔는데 듣고 있는 온라인 강의에서 intelliJ를 사용하고 있어서

강의를 따라감에 있어서 불편함을 느끼고 결국 설치를 했다

eclipse 에서는 spring boot application 시작을 누르면 바로 run이 되는 방식인 것에 비해

intelliJ에서는 터미널에서 gradle에 대한 명령어를 통해 되는 방식인 것 같다.

<br/>

```./gradlew bootRun```  을 터미널에 실행하면 되는데 이 과정에서 자꾸 directory를 못찾는 오류가 났다.

```
./gradlew JAVA_HOME is set to an invalid directory: /Library/Java/JavaVirtualMachines/jdk1.8.0
```

계속 이렇게 설정되어 있었는데 

```
/Library/Java/JavaVirtualMachines/jdk1.8.0_202.jdk/Contents/Home
```

이렇게 바꿔주고 나서 해결되었다.

또한 homebrew 로 gradle설치도 했는데 계속 같은 문제가 발생했었다.

(설치문제인지는 잘 모르겠다 eclipse 에서도 설치없이 gradle project를 실행했었는데.. 알수가 없네..)

결국 자바 환경변수가 맞지 않게 설정되어 있었던 것이 주요 원인이었던? 대체 뭘까..?

