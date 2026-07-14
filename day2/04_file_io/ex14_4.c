// ex14_4.c - 형식화된 입출력 (fprintf, fscanf)
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int k1 = 20000, k2;
    double f1 = 625.78, f2;
    char st1[20] = "Welcome!", st2[20];
    FILE *fp;

    printf("원래의 데이터: %s, %d, %lf\n", st1, k1, f1);
    
    // 1. 파일 쓰기
    // Visual Studio: fopen_s(&fp, "test.dat", "w") != 0
    fp = fopen("test.dat", "w");
    if (fp == NULL)
    {
        printf("파일 열기 오류\n");
        exit(1);
    }
    // Visual Studio: fprintf_s(fp, "%20s %10d %10lf\n", st1, k1, f1);
    fprintf(fp, "%20s %10d %10lf\n", st1, k1, f1);
    fclose(fp);

    // 2. 파일 읽기
    // Visual Studio: fopen_s(&fp, "test.dat", "r") != 0
    fp = fopen("test.dat", "r");
    if (fp == NULL)
    {
        printf("파일 열기 오류\n");
        exit(1);
    }
    // Visual Studio: fscanf_s(fp, "%20s %10d %10lf", st2, 20, &k2, &f2);
    // 표준 C 에서는 버퍼 크기 인자(20)를 받지 않으므로 아래와 같이 호출합니다.
    if (fscanf(fp, "%19s %d %lf", st2, &k2, &f2) != 3) {
        printf("파일 읽기 오류\n");
        fclose(fp);
        exit(1);
    }
    printf("파일의 데이터: %s, %d, %lf\n", st2, k2, f2);
    fclose(fp);
    
    return 0;
}
