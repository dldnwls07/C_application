#include <stdio.h>

struct Point {
    int x;
    int y;
};

// 다른 구조체(Point)를 멤버로 가지는 중첩 구조체
struct Circle {
    struct Point center; // 중심점 좌표
    int radius;          // 반지름
};

int main() {
    struct Circle cir_1;
    
    // 중첩 구조체의 멤버에 접근할 때 온점(.)을 거듭 사용
    cir_1.center.x = 4;
    cir_1.center.y = 5;
    cir_1.radius = 10;

    printf("원 cir_1의 중심점의 위치: (%d, %d) \n", cir_1.center.x, cir_1.center.y);
    printf("원 cir_1의 반경: %d \n", cir_1.radius);

    return 0;
}
