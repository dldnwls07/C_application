#include <stdio.h>
#include <ctype.h>

int main() {
    int ascii, cap, low;
    char ch;
    
    printf("문자를 입력하세요 : ");
    
    // MSVC와 GCC/Clang 호환을 고려한 문자 입력 처리
#ifdef _MSC_VER
    scanf_s("%c", &ch, 1);
#else
    scanf("%c", &ch);
#endif

    // toascii() : 문자를 아스키 코드로 변환 (하위 7비트만 취함)
    ascii = toascii(ch);
    printf("ascii = %d \n", ascii);
    
    // toupper() : 소문자를 대문자로 변환 (대문자나 숫자는 그대로 유지)
    cap = toupper(ch);
    printf("capital = %c \n", cap);
    
    // tolower() : 대문자를 소문자로 변환
    low = tolower(ch);
    printf("lower = %c \n", low);
    
    return 0;
}
