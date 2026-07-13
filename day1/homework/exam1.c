#include <stdio.h>

struct student {
  char student_id[10];
  char name[10];
  int C_score;
  int Java_score;
  int Python_score;
  int total;
  double average;
};

// 학생 정보를 입력받고 총점, 평균을 계산하는 함수
int get_valid_score(const char *subject_name) {
  int score;
  do {
    printf("%s : ", subject_name);
    scanf("%d", &score);
  } while (score < 0 || score > 100); // 범위를 벗어나면 무한 반복
  return score;
}

void info(struct student *s) {
  printf("학번 : ");
  scanf("%9s", s->student_id);
  printf("이름 : ");
  scanf("%9s", s->name);

  // 함수를 재사용하여 코드 길이 최소화
  s->C_score = get_valid_score("C_score");
  s->Java_score = get_valid_score("Java_score");
  s->Python_score = get_valid_score("Python_score");
}
void process(struct student *score) {
  score->total = score->C_score + score->Java_score + score->Python_score;
  score->average = (int)((score->total / 3.0) * 10 + 0.5) / 10.0;
}
void showinfo(struct student *s) {
  // 표의 한 줄에 해당하는 데이터만 간격 맞춰 출력
  printf("%-10s %-8s %-8d %-8d %-8d %-8d %.1f\n", s->student_id, s->name,
         s->C_score, s->Python_score, s->Java_score, s->total, s->average);
}

int main() {
  struct student students[5];

  // 1. 5명 정보 입력 및 처리
  for (int i = 0; i < 5; i++) {
    printf("\n[%d번째 학생 정보 입력]\n", i + 1);
    info(&students[i]);
    process(&students[i]);
  }

  printf("\n<출력형태>\n");
  printf("=============================================================\n");
  printf(" No.\t  이름\t    C언어  파이썬   자바     총점      평균\n");
  printf("=============================================================\n");

  for (int i = 0; i < 5; i++) {
    showinfo(&students[i]);
  }
  printf("=============================================================\n");

  int max_idx = 0;
  int min_idx = 0;
  for (int i = 1; i < 5; i++) {
    if (students[i].total > students[max_idx].total) {
      max_idx = i;
    }
    if (students[i].total < students[min_idx].total) {
      min_idx = i;
    }
  }

  // 5. 최종 결과 문장 출력
  printf("최고점을 받은 학생은 %s 학생으로 총점 %d점, 평균 %.1f입니다.\n",
         students[max_idx].name, students[max_idx].total,
         students[max_idx].average);
  printf("최저점을 받은 학생은 %s 학생으로 총점 %d점, 평균 %.1f입니다.\n",
         students[min_idx].name, students[min_idx].total,
         students[min_idx].average);

  return 0;
}
