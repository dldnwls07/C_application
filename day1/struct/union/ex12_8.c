#include <stdio.h>

// 공용체 정의: 모든 멤버가 메모리 공간을 공유함
union value {
    char c;
    int i;
    double d;
};

typedef union value number;

int main() {
    number num;

    // 1. char 대입 시
    num.c = 61; // 61은 아스키코드로 '=' 문자
    printf("num.c = %d 를 보관하는 경우\n", num.c);
    printf(" num.c = %d, num.i = %d, num.d = %e \n", num.c, num.i, num.d);

    // 2. int 대입 시 (이전 char 데이터 오염)
    num.i = 541494;
    printf("num.i = %d 를 보관하는 경우\n", num.i);
    printf(" num.c = %d, num.i = %d, num.d = %e \n", num.c, num.i, num.d);

    // 3. double 대입 시 (이전 int 데이터 오염)
    num.d = 3.141592;
    printf("num.d = %lf 를 보관하는 경우\n", num.d);
    printf(" num.c = %d, num.i = %d, num.d = %e \n", num.c, num.i, num.d);

    return 0;
}
