#include <stdio.h>

int main() {
  int num1 = 0;
  printf("숫자를 입력하세요: ");
  if (scanf("%d", &num1) != 1) {
    return 1;
  }

  if (num1 <= 1) {
    printf("소수가 아니다\n");
    return 0;
  }

  int is_prime = 1;
  for (int i = 2; i * i <= num1; i++) {
    if (num1 % i == 0) {
      is_prime = 0;
      break;
    }
  }

  if (is_prime) {
    printf("소수다\n");
  } else {
    printf("소수가 아니다\n");
  }

  return 0;
}