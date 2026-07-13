#include <stdio.h>

// 열거자들의 기본값 지정 예시
enum colors { 
    black,      // 0
    brown,      // 1
    red,        // 2
    orange,     // 3
    yellow,     // 4
    green,      // 5
    blue = 16,  // 16으로 명시
    violet,     // 17 (이전 값인 16에서 1 증가)
    gray,       // 18
    white       // 19
};

typedef enum colors color_band;

int main() {
    color_band code;
    int value;

    code = orange;
    printf("code = orange --> %d \n", code);

    code = gray;
    printf("code = gray --> %d \n", code);

    // 열거형 값은 정수형이므로 덧셈 등 수식 계산이 가능함
    value = red + yellow; // 2 + 4 = 6
    printf("value = red + yellow --> %d \n", value);

    return 0;
}
