#include <stdio.h>
#include <math.h>

int main() {
    double x1 = 65.156, x2 = 65.876;
    double y, z;
    
    // ceil() : 올림
    printf("ceil(%lf) = %lf \n", x1, ceil(x1));
    printf("ceil(%lf) = %lf \n\n", x2, ceil(x2));
    
    // floor() : 내림
    printf("floor(%lf) = %lf \n", x1, floor(x1));
    printf("floor(%lf) = %lf \n\n", x2, floor(x2));
    
    // fmod() : 실수 나머지
    printf("fmod(%lf, %lf) = %lf \n", x1, y = 2.4, fmod(x1, y));
    
    // modf() : 실수를 소수부와 정수부로 분리 (정수부는 포인터 변수 y에 저장, 소수부는 반환)
    z = modf(x1, &y);
    printf("z = modf(%lf, &y) --> %lf(z) + %lf(y) \n", x1, z, y);
    
    return 0;
}
