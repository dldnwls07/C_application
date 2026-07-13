#include <stdio.h>

// 열거형 선언: 값을 별도로 지정하지 않으면 0부터 1씩 증가하는 정수가 할당됨
enum seasons { spring, summer, autumn, winter };
// spring=0, summer=1, autumn=2, winter=3

// 열거자 정수를 텍스트로 보여주기 위한 맵핑 배열
char *s_name[] = {"spring", "summer", "autumn", "winter"};

int main() {
    enum seasons s;

    s = spring;
    printf("s : %d --> season : %s \n", s, s_name[s]);

    s = winter;
    printf("s : %d --> season : %s \n", s, s_name[s]);

    return 0;
}
