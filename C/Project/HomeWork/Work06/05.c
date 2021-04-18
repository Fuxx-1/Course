#include <stdio.h>
#include <math.h>
int com(int *a, int *b)
{
    return (*(int *)a - *(int *)b);
}
int main(int argc, char const *argv[])
{
    int n, i;
    scanf("%d", &n);
    int a[n + 1];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &a[i]);
    qsort(a, n + 1, sizeof(int), com);
    for (i = 0; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
