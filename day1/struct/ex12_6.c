#include <stdio.h>

struct Point {
    int x;
    int y;
    int z;
};

typedef struct Point point;

int main() {
    point A = {3, 4, 5};
    point B = {2, 6, 9};
    point *ptr1, *ptr2;

    ptr1 = &A;
    ptr2 = &B;

    // 1. 일반 구조체 변수로 멤버 접근 (.)
    printf("A점의 좌표 : (%d, %d, %d) \n", A.x, A.y, A.z);
    
    // 2. 구조체 포인터 변수의 역참조 후 멤버 접근 (*ptr1).member
    printf("A점의 좌표 : (%d, %d, %d) \n", (*ptr1).x, (*ptr1).y, (*ptr1).z);
    
    // 3. 구조체 포인터 변수로 직접 멤버 접근 (-> 화살표 연산자)
    printf("B점의 좌표 : (%d, %d, %d) \n", ptr2->x, ptr2->y, ptr2->z);

    return 0;
}
