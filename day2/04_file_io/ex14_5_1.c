// ex14_5_1.c - 예제 14.5의 프로그램을 fopen(), strerror() 함수로 작성한 프로그램
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
    char *s = "맨드라미 들마꽃에도 인사를 해야지.";
    int c;
    FILE *fp;

    fp = fopen("test.dat", "w");
    if (fp == NULL) {
        printf("파일 열기 오류\n");
        exit(1);
    }
    while (*s){
        if (fputc(*s++, fp) == EOF) {
            printf(" 파일 쓰기 오류\n");
            exit(1);
        }
    }
    fclose(fp);

    fp = fopen("test.dat", "r");
    if (fp == NULL) {
        printf("파일 열기 오류: %s\n", strerror(errno));
        exit(1);
    }

    // PDF 방식의 feof/ferror 루프 분석
    while (!feof(fp)) {
        c = fgetc(fp);
        // EOF 검사를 하지 않으면 파일의 끝을 지난 후 쓰레기 문자(혹은 -1 문자)가 한 번 출력될 수 있습니다.
        if (c != EOF) {
            putchar(c);
        }
        if (ferror(fp)) {
            printf("파일 오류\n");
            break;
        }
    }
    printf("\n");
    fclose(fp);
    
    return 0;
}
