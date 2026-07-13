#include <stdio.h>

struct Student {
    int id;          // 4 bytes
    char name[16];   // 16 bytes
    int age;         // 4 bytes
}; // 구조체의 메모리 크기는 대략 멤버들의 합 (24 bytes)

union Register {
    char ch;         // 1 byte
    short int sh;    // 2 bytes
    long int lo;     // 8 bytes (64비트 시스템 기준)
}; // 공용체의 메모리 크기는 가장 큰 멤버의 크기 (8 bytes)

int main() {
    struct Student stu1;
    union Register reg1;

    printf("stu1의 메모리 크기 : %d \n", (int)sizeof(stu1));
    printf("reg1의 메모리 크기 : %d \n", (int)sizeof(reg1));

    // 메모리 공유 상태 확인
    reg1.lo = 0x12345678;
    printf("reg1.ch = %8x (가장 하위 1바이트만 출력)\n", reg1.ch);
    printf("reg1.sh = %8x (하위 2바이트 출력)\n", reg1.sh);
    printf("reg1.lo = %8lx \n", reg1.lo);

    return 0;
}
