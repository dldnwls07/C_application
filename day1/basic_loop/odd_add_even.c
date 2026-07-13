#include <stdio.h>
/*
1부터 100사이의 자연수중에서 홀수의 합과 짝수의 합을 구하는 프로그램
홀수와 짝수 합 계산과 결과 출력은 process() 함수사용 반복문 필요하면 for 사용
*/
void process() {
  int sum_odd = 0;
  int sum_even = 0;

  for (int i = 1; i <= 100; i += 2) {
    sum_odd += i;
  }

  for (int i = 2; i <= 100; i += 2) {
    sum_even += i;
  }
  printf("홀수의 합 %d\n", sum_odd);
  printf("짝수의 합 %d\n", sum_even);
}
int main() {
  process();
  return 0;
}