#include <stdio.h>

struct Student {
    int id;
    char *name;
    int age;
};

int main() {
    // 구조체 변수 선언과 동시에 초기화
    struct Student Hong = {20161512, (char *)"홍길동", 21};
    
    // 구조체 변수 선언 후 개별 멤버 초기화
    struct Student Kim;
    Kim.id = 20161234;
    Kim.name = (char *)"김선달";
    Kim.age = 22;

    printf("학번 : %d, 이름 : %s, 나이 : %d \n", Hong.id, Hong.name, Hong.age);
    printf("학번 : %d, 이름 : %s, 나이 : %d \n", Kim.id, Kim.name, Kim.age);

    return 0;
}
