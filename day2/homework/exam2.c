#include <stdio.h>
#include <stdlib.h>

struct grade {
  int Python_score, Java_score, C_score;
};

struct student {
  int student_id;
  char name[50];
  int age;
  struct grade scores;
};

struct student *list[20];
int student_count = 0; // 현재 등록된 학생 수

int main() {
  int choice;

  while (1) {
    printf("\n--- 학생 성적 관리 프로그램 ---\n");
    printf("1. 학생 정보 입력\n");
    printf("2. 개별 성적 입력\n");
    printf("3. 반별 성적 확인\n");
    printf("4. 과목별 최고 득점자 확인\n");
    printf("5. 정보 저장\n");
    printf("0. 프로그램 종료\n");
    printf("메뉴를 선택하세요: ");

    if (scanf("%d", &choice) != 1) {
      printf("올바른 숫자를 입력해주세요.\n");
      while (getchar() != '\n')
        ; // 잘못된 입력 버퍼 비우기 (무한루프 방지)
      continue;
    }

    switch (choice) {
    case 1:
      printf("\n[1. 학생 정보 입력]\n");
      if (student_count >= 20) {
        printf("더 이상 학생을 등록할 수 없습니다.\n");
        break;
      }
      list[student_count] = (struct student *)malloc(sizeof(struct student));
      if (list[student_count] == NULL) {
        printf("메모리 할당 실패\n");
        break;
      }
      printf("학번: ");
      scanf("%d", &list[student_count]->student_id);

      printf("이름: ");
      scanf("%s", list[student_count]->name);

      printf("나이: ");
      scanf("%d", &list[student_count]->age);

      list[student_count]->scores.Python_score = 0;
      list[student_count]->scores.Java_score = 0;
      list[student_count]->scores.C_score = 0;
      printf("%s 학생 정보가 등록 되었습니다.\n", list[student_count]->name);
      student_count++;
      break;
    case 2: {
      printf("\n[2. 개별 성적 입력]\n");
      int search_id;
      int found_index = -1;

      printf("성적을 입력할 학생의 학번을 입력하세요: ");
      if (scanf("%d", &search_id) != 1) {
        printf("올바른 학번 형식을 입력하세요.\n");
        while (getchar() != '\n')
          ; // 입력 버퍼 비우기
        break;
      }
      // 등록된 학생 목록(0 ~ student_count-1)에서 학번 검색
      for (int i = 0; i < student_count; i++) {
        if (list[i]->student_id == search_id) {
          found_index = i;
          break;
        }
      }

      // 검색 결과에 따른 처리
      if (found_index != -1) {
        printf("\n[%s] 학생의 성적을 입력합니다.\n", list[found_index]->name);

        printf("파이썬 점수: ");
        scanf("%d", &list[found_index]->scores.Python_score);

        printf("자바 점수: ");
        scanf("%d", &list[found_index]->scores.Java_score);

        printf("C언어 점수: ");
        scanf("%d", &list[found_index]->scores.C_score);

        printf("성적 입력이 완료되었습니다.\n");
      } else {
        printf("입력하신 학번(%d)의 학생 정보를 찾을 수 없습니다.\n",
               search_id);
        printf("먼저 1번 메뉴에서 학생 정보를 입력해 주세요.\n");
      }
      break;
    }
    case 3:
      printf("\n[3. 반별 성적 확인]\n");
      if (student_count == 0) {
        printf("등록된 학생이 없습니다.\n");
        break;
      }
      printf("학번\t이름\t나이\t파이썬\t자바\tC언어\t평균\n");
      for (int i = 0; i < student_count; i++) {
        double avg = (list[i]->scores.Python_score +
                      list[i]->scores.Java_score + list[i]->scores.C_score) /
                     3.0;
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%.2f\n", list[i]->student_id,
               list[i]->name, list[i]->age, list[i]->scores.Python_score,
               list[i]->scores.Java_score, list[i]->scores.C_score, avg);
      }
      break;
    case 4: {
      printf("\n[4. 과목별 최고 득점자 확인]\n");
      if (student_count == 0) {
        printf("등록된 학생이 없습니다.\n");
        break;
      }

      int max_py_idx = 0;
      int max_jv_idx = 0;
      int max_c_idx = 0;

      for (int i = 1; i < student_count; i++) {
        if (list[i]->scores.Python_score >
            list[max_py_idx]->scores.Python_score) {
          max_py_idx = i;
        }
        if (list[i]->scores.Java_score > list[max_jv_idx]->scores.Java_score) {
          max_jv_idx = i;
        }
        if (list[i]->scores.C_score > list[max_c_idx]->scores.C_score) {
          max_c_idx = i;
        }
      }

      printf("파이썬 최고 득점자: %d점 (학번: %d, 이름: %s)\n",
             list[max_py_idx]->scores.Python_score,
             list[max_py_idx]->student_id, list[max_py_idx]->name);
      printf("자바 최고 득점자: %d점 (학번: %d, 이름: %s)\n",
             list[max_jv_idx]->scores.Java_score, list[max_jv_idx]->student_id,
             list[max_jv_idx]->name);
      printf("C언어 최고 득점자: %d점 (학번: %d, 이름: %s)\n",
             list[max_c_idx]->scores.C_score, list[max_c_idx]->student_id,
             list[max_c_idx]->name);
      break;
    }
    case 5: {
      printf("\n[5. 정보 저장]\n");
      if (student_count == 0) {
        printf("저장할 학생 정보가 없습니다.\n");
        break;
      }

      FILE *file = fopen("student_grades.txt", "w");
      if (file == NULL) {
        printf("파일 저장에 실패했습니다.\n");
        break;
      }

      fprintf(file, "학번\t이름\t나이\t파이썬\t자바\tC언어\t평균\n");
      for (int i = 0; i < student_count; i++) {
        double avg = (list[i]->scores.Python_score +
                      list[i]->scores.Java_score + list[i]->scores.C_score) /
                     3.0;
        fprintf(file, "%d\t%s\t%d\t%d\t%d\t%d\t%.2f\n", list[i]->student_id,
                list[i]->name, list[i]->age, list[i]->scores.Python_score,
                list[i]->scores.Java_score, list[i]->scores.C_score, avg);
      }
      fclose(file);
      printf("학생 정보가 'student_grades.txt' 파일에 성공적으로 "
             "저장되었습니다.\n");
      break;
    }
    case 0:
      printf("프로그램을 종료합니다. 메모리를 정리합니다.\n");
      for (int i = 0; i < student_count; i++) {
        free(list[i]);
      }
      return 0;
    default:
      printf("잘못된 메뉴 선택입니다. 다시 입력해 주세요.\n");
      break;
    }
  }

  return 0;
}