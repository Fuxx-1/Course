#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int a, b;
    char Op_1, Op_2;
    scanf("%d%d %c%c", &a, &b, &Op_1, &Op_2);
    Op_1 == '+' ? printf("%d + %d = %d", a, b, a + b) : "";
    Op_1 == '-' ? printf("%d - %d = %d", a, b, a - b) : "";
    Op_1 == '*' ? printf("%d * %d = %d", a, b, a * b) : "";
    Op_1 == '/' ? printf("%d / %d = %d", a, b, a / b) : "";
    Op_1 == 't' ? printf("%f %f", tan(a), tan(b)) : "";
    Op_1 == 'c' ? printf("%f %f", cos(a), cos(b)) : "";
    Op_1 == 'e' ? printf("%f %f", exp(a), exp(b)) : "";
    Op_1 == 's' && Op_2 == 'i' ? printf("%f %f", sin(a), sin(b)) : "";
    Op_1 == 's' && Op_2 == 'q' ? printf("%f %f", sqrt(a), sqrt(b)) : "";
    return 0;
}
