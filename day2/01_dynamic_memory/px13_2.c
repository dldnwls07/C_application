#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int *pt;
    
    // 1단계: calloc()으로 크기 5의 int형 배열 동적 생성 (자동 0 초기화됨)
    pt = (int *)calloc(5, sizeof(int));
    if (pt == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }
    
    // 2단계: realloc()으로 크기 10의 int형 배열로 재할당
    int *temp = (int *)realloc(pt, 10 * sizeof(int));
    if (temp == NULL) {
        printf("메모리 재할당 실패\n");
        free(pt);
        return 1;
    }
    pt = temp;
    
    // 3단계: 추가 할당된 부분(인덱스 5~9)에 500, 600, 700, 800, 900 저장 (앞의 5개는 0으로 유지됨)
    for (i = 5; i < 10; i++) {
        pt[i] = 100 * i;
    }
    
    // 전체 출력
    for (i = 0; i < 10; i++) {
        printf("%d ", pt[i]);
    }
    printf("\n");
    
    // 메모리 해제
    free(pt);
    
    return 0;
}
