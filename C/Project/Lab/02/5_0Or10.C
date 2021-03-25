#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    int X, Y;
    scanf("%d%d", &X, &Y);
    pow(((X > 0 ? X : -X) - 2), 2) + pow(((Y > 0 ? Y : -Y) - 2), 2) <= 1 ? puts("10") : puts("0");
    return 0;
}
