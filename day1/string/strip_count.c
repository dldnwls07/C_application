/*
키보드로부터 문자열을 입력받아 입력받은 문자열에서 숫자 (0~9), 공백, 그 외의
문자의 개수를 세어 화면에 결과를 출력하시오
*/

#include <stdio.h>
#include <string.h>

int main() {
  char str[256];
  int digits = 0; // 숫자 개수
  int spaces = 0; // 공백 개수
  int others = 0; // 그 외 문자 개수

  printf("문자열 입력하기 : ");
  fgets(str, sizeof(str), stdin);

  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    if (str[i] == '\n') {
      continue;
    }

    // 숫자
    if (str[i] >= '0' && str[i] <= '9') {
      digits++;
    }
    // 공백인
    else if (str[i] == ' ') {
      spaces++;
      // 그외 문자
    } else {
      others++;
    }
  }
  printf("숫자 개수 : %d\n", digits);
  printf("공백 개수 : %d\n", spaces);
  printf("그외 문자 개수 : %d\n", others);

  return 0;
}