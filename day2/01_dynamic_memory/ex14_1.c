#include <stdio.h>
#include <stdlib.h>

int main() {
  int N, *ptr;
  printf("정수 입략받으세요");
  scanf("%d", &N);
  ptr = (int *)malloc(N * sizeof(int));
  if (ptr == NULL) {
    return 1;
  }
  for (int i = 0; i < N; i++) {
    ptr[i] = (i + 1) * 10;
  }
  printf("malloc\n");
  for (int i = 0; i < N; i++) {
    printf("%d ", ptr[i]);
  }
  ptr = (int *)realloc(ptr, sizeof(int) * (N + 2));
  ptr[N] = 100;
  ptr[N + 1] = 200;

  // 전체 출력
  printf("realloc 결과\n");
  for (int i = 0; i < N + 2; i++) {
    printf("%d ", ptr[i]);
  }

  printf("\n");

  // 메모리 해제
  free(ptr);
  return 0;
}