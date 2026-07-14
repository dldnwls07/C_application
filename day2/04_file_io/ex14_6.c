// ex14_6.c - 이진 파일 입출력 (fread, fwrite)
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    int a[5] = {1, 2, 3, 4, 5};
    int i, b[5];

    // 1. 이진 쓰기 모드 ("wb")
    // Visual Studio: fopen_s(&fp, "test.dat", "wb") != 0
    fp = fopen("test.dat", "wb");
    if (fp == NULL) {
        puts("쓰기 위해 파일 열기 실패");
        exit(1);
    }
    
    if (fwrite(a, sizeof(int), 5, fp) != 5) {
        puts("파일에 기록 오류");
        exit(1);
    }
    fclose(fp);

    // 2. 이진 읽기 모드 ("rb")
    // Visual Studio: fopen_s(&fp, "test.dat", "rb") != 0
    fp = fopen("test.dat", "rb");
    if (fp == NULL) {
        puts("읽기 위해 파일 열기 실패");
        exit(1);
    }
    
    if (fread(b, sizeof(int), 5, fp) != 5) {
        puts("파일로부터 읽기 오류");
        exit(1);
    }
    fclose(fp);

    // 읽어온 배열 데이터 출력
    for (i = 0; i < 5; i++)
        printf("%d ", b[i]);
    printf("\n");
    
    return 0;
}
