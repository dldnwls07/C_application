// ex14_1_1.c - 예제 14.1의 프로그램을 fopen() 함수로 작성한 프로그램
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *s = "나비, 제비야, 깝치지 마라.";
    int c; // fgetc()는 EOF를 반환하므로 int로 선언하는 것이 안전합니다.
    FILE *fp;

    fp = fopen("test.dat", "w");
    if (fp == NULL) {
        printf("파일 'test.dat'는 쓰기 위하여 열리지 않았습니다.\n");
        exit(1);
    }
    else
        printf("파일 'test.dat'는 쓰기 위하여 열렸습니다.\n");

    while (*s){
        if (fputc(*s++, fp) == EOF) {
            printf(" 파일쓰기 오류\n");
            exit(1);
        }
    }
    fclose(fp);

    fp = fopen("test.dat", "r");
    if (fp == NULL) {
        printf("파일 'test.dat'는 읽기 위하여 열리지 않았습니다.\n");
        exit(1);
    }
    else
        printf("파일 'test.dat'는 읽기 위하여 열렸습니다.\n");

    while ((c = fgetc(fp)) != EOF)
        putchar(c);
    printf("\n");
    fclose(fp);

    return 0;
}
