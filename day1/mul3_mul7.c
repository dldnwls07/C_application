/*
사용자로부터 숫자를 입력받아 0부터 임의의 수 사이의 자연수 중에서
3의 배수 이면서 7의 배수를 화면에 출력하고 몇개 해당된느지 결과 보이기
*/

#include <stdio.h>
int main() {
  int num1 = 0;
  int count = 0;
  printf("숫자 입력 : ");
  scanf("%d", &num1);

  if (num1 <= 0) {
    printf("0보다 큰 자연수를 입력하세요");
    return 1;
  }
  for (int i = 1; i <= num1; i++) {
    if (i % 3 == 0 && i % 7 == 0) {
      count++;
      printf("%d\n", i);
    }
  }
  double ratio = ((double)count / (num1 + 1) * 100);
  printf("%d개 비율은 %.2f%%\n", count, ratio);
  return 0;
}