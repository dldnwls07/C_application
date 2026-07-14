#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MSVC가 아닐 경우 문자열 안전 함수를 표준 함수로 대응시키는 호환 매크로
#ifndef _MSC_VER
#define strcpy_s(dest, size, src) strcpy(dest, src)
#define strcat_s(dest, size, src) strcat(dest, src)
#endif

int main() {
    char *str;
    
    // 처음에 5바이트 크기로 동적 할당
    str = (char *)malloc(5 * sizeof(char));
    if (str == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }
    
    strcpy_s(str, 5, "Good");
    puts(str);
    
    // realloc()을 사용하여 15바이트 크기로 재할당
    // realloc 실패 시 메모리 누수를 방지하기 위해 임시 포인터(temp)를 사용하는 것이 안전합니다.
    char *temp = (char *)realloc(str, 15);
    if (temp == NULL) {
        printf("메모리 재할당 실패\n");
        free(str); // 기존 할당된 메모리 해제
        return 1;
    }
    str = temp;
    
    // 문자열 추가 연결
    strcat_s(str, 15, " morning");
    puts(str);
    
    // 최종 메모리 해제
    free(str);
    
    return 0;
}
