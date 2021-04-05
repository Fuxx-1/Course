#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n / 2; i++)
    {
        printf("%d+%d=%d\n", i, n - i, n);
    }
    return 0;
}
