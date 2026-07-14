// px14_1.c - 실습문제 14.1
// 키보드로부터 파일 이름을 입력 받아 그 파일의 내용을 모니터에 출력하는 프로그램
#include <stdio.h>

int main() {
    FILE *fp;
    char fname[20];
    int c; // fgetc()는 int를 반환하므로 int로 처리합니다.

    printf("읽을 파일의 이름을 입력 하시오 : ");
    // Visual Studio: scanf_s("%s", fname, 20);
    // 표준 C 에서는 buffer overflow 방지를 위해 폭(width) 지정자를 사용합니다.
    if (scanf("%19s", fname) != 1) {
        puts("입력 오류");
        return 1;
    }

    // Visual Studio: fopen_s(&fp, fname, "r") != 0
    fp = fopen(fname, "r");
    if (fp == NULL) {
        puts("파일 열기 실패");
        return 1;
    }
    
    while ((c = fgetc(fp)) != EOF) 
        putchar(c);
    putchar('\n');
    fclose(fp);
    
    return 0;
}
