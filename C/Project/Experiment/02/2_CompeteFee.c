#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a;
    scanf("%d", &a);
    printf("%.2f", a > 50 ? 7.5 + (a - 50) * 0.1 : a * 0.15);
    return 0;
}
