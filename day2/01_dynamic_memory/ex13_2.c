#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MSVC가 아닐 경우 strcpy_s를 표준 strcpy로 대응시키는 호환 매크로
#ifndef _MSC_VER
#define strcpy_s(dest, size, src) strcpy(dest, src)
#endif

int main() {
  char *sptr;

  // 15바이트 크기의 char 배열 동적 할당
  sptr = (char *)malloc(15 * sizeof(char));
  if (sptr == NULL) {
    printf("Insufficient memory \n");
    return 1;
  }

  // 문자열 복사
  strcpy_s(sptr, 15, "Hello! World.");

  // 출력
  printf("%s \n", sptr);

  // 메모리 해제
  free(sptr);

  return 0;
}
