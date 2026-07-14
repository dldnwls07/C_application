#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, *p;
    
    // calloc()을 통해 0으로 초기화된 메모리를 5 * sizeof(int) 크기로 할당
    p = (int *)calloc(5, sizeof(int));
    if (p == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }
    
    // 0으로 초기화된 상태 확인 및 출력
    for (i = 0; i < 5; i++) {
        printf("p[%d] : %d ", i, p[i]);
    }
    printf("\n\n");
    
    // 값 대입 후 출력
    for (i = 0; i < 5; i++) {
        p[i] = i;
        printf("p[%d]에는 %d이 들어 있습니다. \n", i, p[i]);
    }
    printf("\n");
    
    // 메모리 해제
    free(p);
    
    return 0;
}
