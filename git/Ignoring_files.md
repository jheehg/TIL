# Ignoring files



#### git에 특정 파일이나 폴더 제외하기 (.gitignore)

git repository 루트 디렉토리에 .gitignore 파일 생성 후 아래와 같이 작성

```xml
# 파일 제외
file.txt

# 확장자 제외
*.log

# 디렉토리 제외
/node_modules
/test
```



이미 push된 파일 중 제외 할 것이 있다면 원격저장소에서 파일 제거하기

```bash
git rm --cached FILENAME
```



📌 .gitignore templates

https://github.com/github/gitignore



출처

> https://docs.github.com/en/github/using-git/ignoring-files
>
> https://git-scm.com/book/en/v2/Git-Basics-Recording-Changes-to-the-Repository#_ignoring