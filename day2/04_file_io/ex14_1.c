// ex14_1.c - 14.2 텍스트 파일 입출력 (문자 단위 쓰기 및 읽기)
// * macOS(Clang/GCC) 환경을 위해 표준 fopen을 사용해 구현되었습니다.
// * Visual Studio(MSVC) 전용인 fopen_s 버전에 대한 설명 및 주석이 포함되어
// 있습니다.

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *s = "나비, 제비야, 깝치지 마라.";
  int c; // fgetc()는 EOF(-1)를 반환하므로 int형으로 선언하는 것이 안전합니다.
  FILE *fp;

  // 1. 파일 쓰기 모드로 열기
  // Visual Studio (MSVC) 전용:
  // errno_t err;
  // err = fopen_s(&fp, "test.dat", "w");
  // if (err == 0) ...
  fp = fopen("test.dat", "w");
  if (fp != NULL)
    printf("파일 'test.dat'는 쓰기 위하여 열렸습니다.\n");
  else {
    printf("파일 'test.dat'는 쓰기 위하여 열리지 않았습니다.\n");
    exit(1);
  }

  // 문자 단위로 쓰기
  while (*s) {
    if (fputc(*s++, fp) == EOF) {
      printf(" 파일쓰기 오류\n");
      exit(1);
    }
  }
  fclose(fp); // 파일 닫기

  // 2. 파일 읽기 모드로 열기
  // Visual Studio (MSVC) 전용:
  // err = fopen_s(&fp, "test.dat", "r");
  // if (err == 0) ...
  fp = fopen("test.dat", "r");
  if (fp != NULL)
    printf("파일 'test.dat'는 읽기 위하여 열렸습니다.\n");
  else {
    printf("파일 'test.dat'는 읽기 위하여 열리지 않았습니다.\n");
    exit(1);
  }

  // 문자 단위로 읽어서 화면에 출력
  while ((c = fgetc(fp)) != EOF)
    putchar(c);
  printf("\n");
  fclose(fp);

  return 0;
}
