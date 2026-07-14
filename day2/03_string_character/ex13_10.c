#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1;
    long int n2;
    double f1;
    char *str1 = "1234.56";
    
    // atoi() : 문자열을 int형 정수로 변환 ("1234.56" -> 소수점 뒤는 변환 중단되어 1234)
    n1 = atoi(str1);
    printf("string = %s, integer = %d\n", str1, n1);
    
    // atol() : 문자열을 long형 정수로 변환 ("1234.56" -> 1234)
    n2 = atol(str1);
    printf("string = %s, long integer = %ld\n", str1, n2);
    
    // atof() : 문자열을 double형 부동소수점 수로 변환 ("1234.56" -> 1234.560000)
    f1 = atof(str1);
    printf("string = %s, double = %lf\n", str1, f1);
    
    return 0;
}
