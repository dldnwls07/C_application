#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double x, y;
    
    // exp()는 자연상수 e의 거듭제곱(e^x)을 구함
    // log()는 자연로그(ln)를 구함
    
    a = -1.0;
    x = exp(a);
    printf("exp(%lf) = %lf\n", a, x);
    b = log(x);
    printf("log(%lf) = %lf\n\n", x, b);
    
    a = 1.0;
    y = exp(a);
    printf("exp(%lf) = %lf\n", a, y);
    c = log(y);
    printf("log(%lf) = %lf\n", y, c);
    
    return 0;
}
