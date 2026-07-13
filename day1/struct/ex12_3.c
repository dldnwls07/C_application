#include <stdio.h>

struct Point {
    int x;
    int y;
};

// struct Point 타입을 point라는 새 이름으로 재정의(typedef)
typedef struct Point point;

int main() {
    struct Point A;
    point B = {5, 8}; // 재정의된 타입명 point 사용
    
    A.x = 3;
    A.y = 4;

    printf("A점의 좌표 값: (%d, %d) \n", A.x, A.y);
    printf("B점의 좌표 값: (%d, %d) \n", B.x, B.y);

    return 0;
}
