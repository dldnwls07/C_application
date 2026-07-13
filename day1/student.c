/*
학생 1명의 정보를 입력받아 총점과 평균을 구하는 프로그램 작성
학생 1명에 대한 정보느 main()에서 입력받으며, Get() 함수에서 총점과 평균을
계산한 후 main() 에서 그 결과 출력 학생 1명에 대한 정보는 학번, 국어, 영어,
수학, 총점, 평균을 저장할 수 있는 Student 구조체 활용한다. 함수의 전달 방법은
값에 의한 형태로 구현 하세요.

*/
#include <stdio.h>

struct Student {
  int student_id;
  int korean;
  int english;
  int math;
  int total;
  double avg;
};

struct Student Get(struct Student s) {
  s.total = s.korean + s.english + s.math;
  s.avg = s.total / 3.0;
  return s;
}

int main() {
  struct Student s;

  printf("학번 : ");
  scanf("%d", &s.student_id);
  printf("국어 : ");
  scanf("%d", &s.korean);
  printf("영어 : ");
  scanf("%d", &s.english);
  printf("수학 : ");
  scanf("%d", &s.math);

  s = Get(s);

  printf("\n학번 : %d\n", s.student_id);
  printf("국어 : %d\n", s.korean);
  printf("영어 : %d\n", s.english);
  printf("수학 : %d\n", s.math);
  printf("총점 : %d\n", s.total);
  printf("평균 : %.2f\n", s.avg);

  return 0;
}