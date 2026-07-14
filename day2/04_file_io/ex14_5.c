// ex14_5.c - 오류 처리 함수 (feof, ferror, strerror)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
    char *s = "맨드라미 들마꽃에도 인사를 해야지.";
    int c;
    FILE *fp;

    // 1. 파일 쓰기
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

    // 2. 파일 읽기
    fp = fopen("test.dat", "r");
    if (fp == NULL) {
        // Visual Studio: strerror_s(errmsg, 80, err); printf("오류 : %s \n", errmsg);
        // 표준 C: strerror(errno) 사용
        printf("오류 : %s \n", strerror(errno));
        exit(1);
    }

    // feof()와 ferror()의 사용 시연
    // 안전한 읽기를 위해 먼저 첫 문자를 시도하거나 fgetc 반환값을 직접 체크합니다.
    while (1) {
        c = fgetc(fp);
        if (c == EOF) {
            if (ferror(fp)) {
                printf("\n파일 읽기 중 오류 발생\n");
            }
            if (feof(fp)) {
                // 정상적으로 끝에 도달한 경우
            }
            break;
        }
        putchar(c);
    }
    printf("\n");
    fclose(fp);
    
    return 0;
}
