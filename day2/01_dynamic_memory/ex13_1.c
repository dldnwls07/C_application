#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, *p;
    
    // 크기 5의 int형 배열 동적 할당
    p = (int *)malloc(5 * sizeof(int));
    if (p == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    // 배열 인덱스 표기법 사용
    for (i = 0; i < 5; i++) {
        p[i] = i;
        printf("p[%d]에는 %d이 들어 있습니다. \n", i, p[i]);
    }
    printf("\n");
    
    // 포인터 연산 표기법 사용
    for (i = 0; i < 5; i++) {
        *(p + i) = i;
        printf("*(p+%d)에는 %d이 들어 있습니다. \n", i, *(p + i));
    }
    
    // 할당받은 메모리 해제
    free(p);
    
    return 0;
}
