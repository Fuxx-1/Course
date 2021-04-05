#include <stdio.h>
int main(int argc, char const *argv[])
{
    int A, B, ans = 0;
    scanf("%d,%d", &A, &B);
    for (int i = A; i < B; i++)
    {
        if (i % 7 == 2)
        {
            ans += i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
