#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;
    int *pa;
    long long *pb;
    
    // calloc()을 통해 크기 5의 int 배열 할당
    pa = (int *)calloc(5, sizeof(int));
    if (pa == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }
    
    for (i = 0; i < 5; i++) {
        pa[i] = i;
    }
    
    for (i = 0; i < 5; i++) {
        printf("%6d ", pa[i]);
    }
    printf("\n");
    
    // realloc()을 사용해 pa가 할당된 영역의 크기를 long long형 5개 크기(40바이트)로 재조정
    pb = (long long *)realloc(pa, 5 * sizeof(long long));
    if (pb == NULL) {
        printf("메모리 재할당 실패\n");
        free(pa); // 재할당 실패 시 기존 메모리(pa) 해제 필수
        return 1;
    }
    
    // long long 형 배열로써 값 저장 및 출력
    for (i = 0; i < 5; i++) {
        pb[i] = (long long)i * 1000;
    }
    
    for (i = 0; i < 5; i++) {
        printf("%6lld ", pb[i]);
    }
    printf("\n");
    
    // 최종 메모리 해제 (pa는 이미 pb에 통합되었거나 해제되었으므로 pb만 free)
    free(pb);
    
    return 0;
}
