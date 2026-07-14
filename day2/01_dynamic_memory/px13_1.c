#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int *pt;
    
    // 1단계: 크기 5의 int형 배열 malloc으로 동적 생성
    pt = (int *)malloc(5 * sizeof(int));
    if (pt == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }
    
    // 0, 10, 20, 30, 40 저장
    for (i = 0; i < 5; i++) {
        pt[i] = 10 * i;
    }
    
    // 출력
    for (i = 0; i < 5; i++) {
        printf("%d ", pt[i]);
    }
    printf("\n");
    
    // 2단계: 크기 10의 int형 배열로 realloc 재할당
    int *temp = (int *)realloc(pt, 10 * sizeof(int));
    if (temp == NULL) {
        printf("메모리 재할당 실패\n");
        free(pt);
        return 1;
    }
    pt = temp;
    
    // 추가 할당된 원소(인덱스 5~9)에 500, 600, 700, 800, 900 저장
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
