#include <stdio.h>

struct Student {
    int id;
    char *name;
    int age;
};

int main() {
    int a;
    // 구조체 배열의 선언과 동시에 초기화
    struct Student class_A[3] = {
        {20161001, (char *)"김선달", 22},
        {20161002, (char *)"임꺽정", 21},
        {20161003, (char *)"홍길동", 20}
    };

    for (a = 0; a < 3; a++) {
        printf("학번: %d, 이름: %s, 나이: %d \n", 
               class_A[a].id, class_A[a].name, class_A[a].age);
    }

    return 0;
}
