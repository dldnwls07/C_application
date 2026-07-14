// ex14_7.c - 이진 파일 복사 프로그램 (블록 단위 복사)
#include <stdio.h>

int main() {
    FILE *sfp, *dfp;
    char sfile[20] = {"ex14_7.c"};
    char dfile[20] = {"temp.c"};
    char buf[256];
    size_t rcnt, wcnt; // fread와 fwrite는 size_t를 반환합니다.

    // Visual Studio: fopen_s(&sfp, sfile, "rb"); fopen_s(&dfp, dfile, "wb");
    sfp = fopen(sfile, "rb");
    dfp = fopen(dfile, "wb");
    
    if (sfp == NULL || dfp == NULL) {
        fprintf(stderr, "파일 열기 실패...\n");
        return 1;
    }
    
    // 블록 단위로 읽고 쓰기
    while ((rcnt = fread(buf, 1, sizeof(buf), sfp)) > 0) {
        wcnt = fwrite(buf, 1, rcnt, dfp);
        if (wcnt < rcnt) { // 또는 wcnt < 0 검사 (표준에서는 쓴 개수가 읽은 개수보다 작으면 에러)
            fprintf(stderr, "파일 쓰기 오류...\n");
            fclose(sfp);
            fclose(dfp);
            return 1;
        }
    }
    
    printf("%s에서 %s로 복사 되었습니다\n", sfile, dfile);
    fclose(sfp);
    fclose(dfp);
    
    return 0;
}
