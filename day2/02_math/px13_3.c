#include <stdio.h>
#include <math.h>

int main() {
    double a = 20.0;
    double diag, area;
    
    // 피타고라스 정리를 사용하여 대각선 길이 계산: diag = sqrt(a^2 + a^2)
    diag = sqrt(a * a + a * a);
    
    // 대각선 길이를 한 변으로 하는 정사각형의 넓이 계산: area = diag^2
    area = pow(diag, 2);
    
    printf("대각선의 길이 : %lf \n", diag);
    printf("넓이 : %lf \n", area);
    
    return 0;
}
