#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a, b;
    char Op;
    scanf("%d%d %c", &a, &b, &Op);
    Op == '+' ? printf("%d + %d = %d", a, b, a + b) : "", Op == '-' ? printf("%d - %d = %d", a, b, a - b) : "", Op == '*' ? printf("%d * %d = %d", a, b, a * b) : "", Op == '/' ? printf("%d / %d = %d", a, b, a / b) : "";
    return 0;
}
