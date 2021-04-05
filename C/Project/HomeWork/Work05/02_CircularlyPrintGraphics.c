#include <stdio.h>
int main(int argc, char const *argv[])
{
    int flag, n;
    scanf("%d%d", &flag, &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i); j++)
        {
            printf("%d", flag);
        }
        printf("\n");
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%d", flag);
        }
        printf("\n");
    }
    return 0;
}
