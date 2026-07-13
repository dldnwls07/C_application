#include <stdio.h>
#include <math.h> // sqrt() 함수 사용

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
    float lx, ly;
    double length;

    ln.p1.x = 4;
    ln.p1.y = 6;
    ln.p2.x = 14;
    ln.p2.y = 16;

    // 두 점 사이의 가로, 세로 거리 계산
    lx = (float)(ln.p2.x - ln.p1.x);
    ly = (float)(ln.p2.y - ln.p1.y);
    
    // 피타고라스 정리를 이용한 두 점 사이의 직선 길이 계산
    length = sqrt(lx * lx + ly * ly);

    printf("p1의 좌표 : (%d, %d)\n", ln.p1.x, ln.p1.y);
    printf("p2의 좌표 : (%d, %d)\n", ln.p2.x, ln.p2.y);
    printf("ln의 길이 : %lf \n", length);

    return 0;
}
