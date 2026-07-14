// ex14_9.c - 파일 크기를 구하고 전체를 동적으로 읽기
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char *buf;
    long fsize; // ftell()은 long형을 반환하므로 long으로 정의합니다.

    // Visual Studio: fopen_s(&fp, "ex14_9.c", "rb") != 0
    // 본 소스코드를 읽도록 하거나 다른 파일을 읽을 수 있도록 구현
    fp = fopen("ex14_9.c", "rb");
    if (fp == NULL) {
        fprintf(stderr, "파일 열기 실패...\n");
        return 1;
    }
    
    // 파일의 끝으로 이동
    fseek(fp, 0, SEEK_END);
    
    // 현재 위치(즉, 파일의 크기) 구하기
    fsize = ftell(fp);
    
    // 메모리 동적 할당 (+1 바이트는 마지막 '\0'을 위한 공간)
    buf = (char *)malloc(fsize * sizeof(char) + 1);
    if (buf == NULL) {
        fprintf(stderr, "메모리 할당 실패...\n");
        fclose(fp);
        return 1;
    }
    
    // 파일 포인터를 다시 파일의 처음으로 되돌리기
    rewind(fp);
    
    // 파일 전체 읽기
    if (fread(buf, 1, fsize, fp) < 1) {
        fprintf(stderr, "파일 읽기 오류...\n");
        free(buf);
        fclose(fp);
        return 1;
    }
    
    buf[fsize] = '\0'; // 문자열 끝에 NULL 문자 추가
    fclose(fp);
    
    puts("다음은 읽은 파일의 내용입니다.");
    puts(buf);
    
    free(buf); // 동적 할당 해제
    return 0;
}
