// ex14_3.c - 문자열 단위 입출력 (fgets, fputs)
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    char line[20] = "Hello! World.";

    // 1. 파일 쓰기
    // Visual Studio: fopen_s(&fp, "test.dat", "w") != 0
    fp = fopen("test.dat", "w");
    if (fp == NULL)
    {
        puts("File open error!");
        exit(1);
    }
    
    if (fputs(line, fp) == EOF)
        puts("fputs() error");
    else
        fputc('\n', fp); // 줄바꿈 문자 기록
        
    puts("파일이 정상적으로 생성되었습니다.");
    fclose(fp);

    // 2. 파일 읽기
    // Visual Studio: fopen_s(&fp, "test.dat", "r") != 0
    fp = fopen("test.dat", "r");
    if (fp == NULL)
    {
        puts("File open error!");
        exit(1);
    }
    
    if (fgets(line, 20, fp) == NULL)
        puts("fgets() error");
    else {
        puts("읽은 파일의 내용은 : ");
        printf("%s", line);
    }
    fclose(fp);

    return 0;
}
