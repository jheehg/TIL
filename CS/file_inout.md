#### > 파일 입출력



**<< fread() 사용 시 0으로 초기화 해야하는 이유 >>**

파일에 저장된 문자열은 null을 포함하지 않음.

파일에 있는 문자열을 읽으면 이전에 메모리에 저장된 값까지 같이 가져오므로

0으로 초기화 하지 않으면 쓸데없는 값까지 같이 가져오게 됨. 



* fread(_buffer, sizeof(_buffer) -1 , 1, stdin);

**화면**에서 값을 입력받아 버퍼에 저장한다.

단 fread는 무조건 지정된 크기만큼 읽으므로 끝에 null이 들어가도록 읽기 크기는 버퍼 크기보다 1이 적도록 만들어준다.

fread(버퍼, 읽기크기, 읽기횟수, 파일포인터);

읽기크기 * 읽기횟수 = **총 크기(byte)**

   

   

**<< stdin, stdout, stderr = 파일 포인터(FILE *) >>**

stdin = standard input (키보드 입력)

stdout = standard out (콘솔 출력)

stderr = standard error(콘솔 출력)

   

stdin, stdout, stderr 모두 파일포인터이므로 모두 fprintf, fscanf, fread, fwrite에 사용 가능.

   

fscanf, fgets - stdin : 키보드 입력값을 가져옴

fprintf, fputs - stdout, stderr : 콘솔에 값을 출력하게 됨

  



>  출처  https://dojang.io/course/view.php?id=2



  