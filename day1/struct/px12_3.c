#include <stdio.h>
#include <math.h>

struct Point {
    int x;
    int y;
};

struct Line {
    struct Point p1;
    struct Point p2;
};

int main() {
    struct Line ln;
    struct Line *pln = &ln; // 구조체 포인터 선언 및 원본 주소 대입
    float lx, ly;
    double length;

    // 구조체 포인터를 사용하여 값 대입
    pln->p1.x = 4;
    pln->p1.y = 6;
    pln->p2.x = 14;
    pln->p2.y = 16;

    // 구조체 포인터(->)를 활용해 원소 간의 연산 수행
    lx = (float)(pln->p2.x - pln->p1.x);
    ly = (float)(pln->p2.y - pln->p1.y);
    length = sqrt(lx * lx + ly * ly);

    printf("p1의 좌표 : (%d, %d)\n", pln->p1.x, pln->p1.y);
    printf("p2의 좌표 : (%d, %d)\n", pln->p2.x, pln->p2.y);
    printf("ln의 길이 : %lf \n", length);

    return 0;
}
