#include <stdio.h>
#include <math.h>

const double pi = 3.14159;

int main() {
    int deg1 = 30, deg2 = 45;
    double rad1, rad2;
    
    // 호도법(Radian) 변환
    rad1 = deg1 * pi / 180.0;
    rad2 = deg2 * pi / 180.0;
    
    // 30도 출력
    printf("sin(%d) = %lf \n", deg1, sin(rad1));
    printf("cos(%d) = %lf \n", deg1, cos(rad1));
    printf("tan(%d) = %lf \n", deg1, tan(rad1));
    printf("\n");
    
    // 45도 출력
    printf("sin(%d) = %lf \n", deg2, sin(rad2));
    printf("cos(%d) = %lf \n", deg2, cos(rad2));
    printf("tan(%d) = %lf \n", deg2, tan(rad2));
    
    return 0;
}
