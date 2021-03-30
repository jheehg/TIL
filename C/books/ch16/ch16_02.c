#include <stdio.h>

typedef struct STUDENT {
    char name[30];
    char id[12];
    char phone[16];
    char korean;
    char english;
    char math;
    char order;
} STUDENT;

int main()
{
    STUDENT student = {
        "홍길동", "1234567", "010-1234-5678", 95, 80, 85, 10
    };
    
    printf("%s\n", student.name);
    printf("%s\n", student.id);
    printf("%s\n", student.phone);
    printf("국어: %d, 영어: %d, 수학: %d, 석차: %d\n",
           student.korean, student.english, student.math, student.order);
    
    
    return 0;
}

