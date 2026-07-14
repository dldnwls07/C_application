#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    
    // 1단계: 'A' 평가 (알파벳 및 대소문자 확인)
    c = 'A';
    if (isalpha(c)) {
        if (isupper(c))
            printf("%c is alphabetic and upper case.\n", c);
        else
            printf("%c is alphabetic and lower case.\n", c);
    } else {
        printf("%c is not alphabetic.\n", c);
    }
    
    // 2단계: '5' 평가 (숫자 확인)
    c = '5';
    if (isdigit(c)) {
        printf("%c is digit.\n", c);
    } else {
        printf("%c is not digit.\n", c);
    }
    
    return 0;
}
