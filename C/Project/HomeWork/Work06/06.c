#include <stdio.h>
int main(int argc, char const *argv[])
{
    long long a, b;
    scanf("%lld%lld", &a, &b);
    printf("a=%lld,b=%lld\na=%lld,b=%lld\n", a, b, b, a);
    return 0;
}
