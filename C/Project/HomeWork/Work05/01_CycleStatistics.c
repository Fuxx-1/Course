#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n, ans = 0, flag = 1;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        ans += ((flag++) * (n - i));
    }
    printf("%d\n", ans);
    return 0;
}
