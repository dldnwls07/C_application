/*
키보드로부터 문자열을 입력받아 입력받은 문자열에서 숫자 (0~9), 공백, 그 외의
문자의 개수를 세어 화면에 결과를 출력하시오
*/

#include <stdio.h>

int main() {
  char str[256];
  int others = 0;
  int i = 0;

  printf("문자열 입력하기 : ");
  fgets(str, sizeof(str), stdin);

  while (str[i] != '\0') {
    if (str[i] != '\n' && str[i] != ' ' && !(str[i] >= '0' && str[i] <= '9')) {
      others++;
    }
    i++;
  }

  printf("그외 문자 개수 : %d\n", others);

  return 0;
}