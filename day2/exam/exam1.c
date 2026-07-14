#include <stdio.h>
#include <stdlib.h>

void Sort(int *arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] < arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  int n;
  int *ptr;

  printf("정수의 개수를 입력하세요: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("유효하지 않은 입력입니다.\n");
    return 1;
  }

  // 입력받은 크기 n만큼 동적 할당
  ptr = (int *)malloc(n * sizeof(int));
  if (ptr == NULL) {
    printf("메모리 할당 실패\n");
    return 1;
  }

  printf("%d개의 정수를 입력하세요:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &ptr[i]);
  }

  // 정렬 수행
  Sort(ptr, n);

  printf("내림차순 정렬 결과:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", ptr[i]);
  }
  printf("\n");

  // 동적 할당 해제
  free(ptr);

  return 0;
}