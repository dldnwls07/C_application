// ex14_8.c - 파일 임의 접근 방법 (레코드 기반 임의 쓰기 및 순차 읽기)
#include <stdio.h>
#include <stdlib.h>

typedef struct Nobel_Literature {
    char title[41];
    char author[41];
    unsigned int year;
} NOBEL;

// 각 레코드 크기를 86바이트로 강제 지정 (title 40 + author 40 + year 6)
#define RECLEN 86
#define FORMAT "%-40s%-40s%6d"
FILE *fp;

void datawrite(int recno, char *title, char *author, int year);
void dataread(NOBEL *nbook);

int main()
{
    int i;
    NOBEL nbook;

    // 1. 임의 쓰기 테스트
    // Visual Studio: fopen_s(&fp, "booklist.dat", "wb")
    fp = fopen("booklist.dat", "wb");
    if (fp == NULL) {
        puts("파일 쓰기 모드 열기 에러");
        exit(1);
    }
    datawrite(0, "염소의 축제", "마리오 바르가스 요사", 2010);
    datawrite(1, "기억이 나를 본다", "토마스 트란스트뢰메르", 2011);
    datawrite(2, "사부님은 갈수록 유머러스해진다", "모옌", 2012);
    fclose(fp);

    // 2. 순차 읽기 테스트
    // Visual Studio: fopen_s(&fp, "booklist.dat", "rb")
    fp = fopen("booklist.dat", "rb");
    if (fp == NULL) {
        puts("파일 읽기 모드 열기 에러");
        exit(1);
    }
    for (i = 0; i < 3; i++) {
        dataread(&nbook);
        printf("%d\t제목 : %s\n\t작가 : %s\n\t수상년도 : %d \n\n", 
            i, nbook.title, nbook.author, nbook.year);
    }
    fclose(fp);
    
    return 0;
}

void datawrite(int recno, char *title, char *author, int year)
{
    fseek(fp, RECLEN * recno, SEEK_SET);
    fprintf(fp, FORMAT, title, author, year);
}

void dataread(NOBEL *nbook)
{
    // fgets는 41바이트(버퍼 크기 - 1 = 40글자) 읽고 NULL 문자를 붙여 41바이트를 채웁니다.
    fgets(nbook->title, 41, fp);
    fgets(nbook->author, 41, fp);
    // Visual Studio: fscanf_s(fp, "%d", &nbook->year);
    if (fscanf(fp, "%d", &nbook->year) != 1) {
        // fscanf 후 개행 등을 스킵해주거나 임의 접근에 맞춰 처리합니다.
    }
}
