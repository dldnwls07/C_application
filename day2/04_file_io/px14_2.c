// px14_2.c - 실습문제 14.2
// 예제 14.8의 프로그램을 원하는 레코드 번호를 입력 받아 그 레코드의 내용을 읽어 출력하는 형태로 바꾼 프로그램
#include <stdio.h>
#include <stdlib.h>

typedef struct Nobel_Literature {
    char title[41];
    char author[41];
    unsigned int year;
} NOBEL;

#define RECLEN 86
#define FORMAT "%-40s%-40s%6d"
FILE *fp;

void datawrite(int recno, char *title, char *author, int year);
void dataread(int recno, NOBEL *nbook);

int main() {
    int rno; 
    NOBEL nbook;

    // 1. 샘플 데이터 쓰기
    // Visual Studio: fopen_s(&fp, "booklist.dat", "wb")
    fp = fopen("booklist.dat", "wb");
    if (fp == NULL) {
        puts("파일 쓰기 에러");
        exit(1);
    }
    datawrite(0, "염소의 축제", "마리오 바르가스 요사", 2010);
    datawrite(1, "기억이 나를 본다", "토마스 트란스트뢰메르", 2011);
    datawrite(2, "사부님은 갈수록 유머러스해진다", "모옌", 2012);
    fclose(fp);

    // 2. 원하는 레코드 읽기
    // Visual Studio: fopen_s(&fp, "booklist.dat", "rb")
    fp = fopen("booklist.dat", "rb");
    if (fp == NULL) {
        puts("파일 읽기 에러");
        exit(1);
    }
    
    printf("출력할 레코드 번호를 입력 하세요 (0~2): ");
    // Visual Studio: scanf_s("%d", &rno);
    if (scanf("%d", &rno) != 1) {
        puts("입력 오류");
        fclose(fp);
        return 1;
    }
    
    if (rno < 0 || rno > 2) {
        printf("잘못된 레코드 번호입니다. (0 ~ 2 범위 입력 가능)\n");
    } else {
        dataread(rno, &nbook);
    }
    
    fclose(fp);
    return 0;
}

void datawrite(int recno, char *title, char *author, int year)
{
    fseek(fp, RECLEN * recno, SEEK_SET);
    fprintf(fp, FORMAT, title, author, year);
}

void dataread(int recno, NOBEL *nbook)
{
    // 원하는 레코드로 이동
    fseek(fp, recno * RECLEN, SEEK_SET);
    
    fgets(nbook->title, 41, fp);
    fgets(nbook->author, 41, fp);
    // Visual Studio: fscanf_s(fp, "%d", &nbook->year);
    if (fscanf(fp, "%d", &nbook->year) != 1) {
        // fscanf parsing check
    }
    
    printf("%d\t제목 : %s\n\t작가 : %s\n\t수상년도 : %d \n\n", 
        recno, nbook->title, nbook->author, nbook->year);
}
