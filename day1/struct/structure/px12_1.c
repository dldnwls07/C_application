#include <stdio.h>

// 실습문제 12.1: Book 구조체 정의 및 출력
struct Book {
    char title[40];
    char author[40];
    unsigned int year;
};

int main() {
    struct Book book1 = {"염소의 축제", "마리오 바르가스 요사", 2010};

    printf("%s\n", book1.title);
    printf("%s\n", book1.author);
    printf("%d\n", book1.year);

    return 0;
}
