#include <stdint.h>
#include <math.h>
int isPrimeNumber(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    int A, B, ans = 0;
    scanf("%d%d", &A, &B);
    for (int i = A + 1; i < B; i++)
    {
        if (isPrimeNumber(i))
        {
            ans++;
        }
    }
    if (A < 0 || B < 0)
    {
    }
    else
    {
        printf("%d\n", ans);
    }

    return 0;
}
