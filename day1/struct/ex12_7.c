#include <stdio.h>

typedef struct Student {
    int id;
    char name[10];
    int age;
} student;

// 함수 선언
void stuPrn(student temp);
student stuInput();

int main() {
    student stu1;
    
    // 함수 반환값(구조체)을 변수에 대입
    stu1 = stuInput();
    
    printf("\n 학번 이름 나이 \n");
    printf("============================\n");
    
    // 구조체를 인수로 함수에 전달 (값에 의한 전달)
    stuPrn(stu1);
    printf("\n");

    return 0;
}

// 구조체를 출력하는 함수 (값에 의한 전달로 복사본을 받음)
void stuPrn(student temp) {
    printf("%d %s %d \n", temp.id, temp.name, temp.age);
}

// 키보드 입력을 받아 구조체 변수를 통째로 반환하는 함수
student stuInput() {
    student temp;
    printf("학번을 입력하세요: ");
    scanf("%d", &temp.id);
    
    printf("이름을 입력하세요: ");
    scanf("%s", temp.name);
    
    printf("나이를 입력하세요: ");
    scanf("%d", &temp.age);
    
    return temp;
}
