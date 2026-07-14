// ex14_2.c - 텍스트 파일 복사하기
#include <stdio.h>

int main()
{
    FILE *fp1, *fp2;
    int c; // fgetc()는 int를 반환하므로 int로 쓰는 것이 이식성이 높습니다.

    // Visual Studio: fopen_s(&fp1, "ex14_2.c", "r"); fopen_s(&fp2, "temp.c", "w");
    fp1 = fopen("ex14_2.c", "r");
    fp2 = fopen("temp.c", "w");

    if (fp1 == NULL || fp2 == NULL) {
        puts("파일 열기 실패");
        return 1;
    }

    while ((c = fgetc(fp1)) != EOF) 
        fputc(c, fp2);

    fclose(fp1);
    fclose(fp2);

    printf("ex14_2.c 파일을 temp.c 파일로 복사 하였습니다.\n");
    return 0;
}
