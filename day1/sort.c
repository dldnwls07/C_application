#include <stdint.h>
#include <stdio.h>
void Sort() {
  int arr[7];
  int num1 = 0;
  for (int i = 0; i < 7; i++) {
    printf("%d번째 원소값을 입력하세요 :", i + 1);
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < 7 - 1; i++) {
    for (int j = 0; j < 7 - 1 - i; j++) {

      // 핵심: 앞의 숫자가 뒤의 숫자보다 '작으면' 자리를 바꿉니다.
      if (arr[j] < arr[j + 1]) {

        // 두 변수의 값을 맞바꾸는(Swap) 공식
        int temp = arr[j];   // temp(임시 상자)에 앞의 값을 잠시 보관
        arr[j] = arr[j + 1]; // 뒤에 있던 더 큰 값을 앞으로 이동
        arr[j + 1] = temp;   // 보관해둔 작은 값을 뒤로 이동
      }
    }
  }

  // 3. 정렬된 최종 결과 출력
  printf("\n내림차순 정렬 결과: ");
  for (int i = 0; i < 7; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
int main() {
  Sort();
  return 0;
}