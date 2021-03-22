#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(int argc, char const *argv[])
{
    int a[3];
    scanf("%d%d%d", &a[0], &a[1], &a[2]);
    if (a[1] > a[0])
    {
        swap(&a[0], &a[1]);
    }
    if (a[2] > a[1])
    {
        swap(&a[2], &a[1]);
    }
    if (a[1] > a[0])
    {
        swap(&a[0], &a[1]);
    }
    printf("%d %d %d", a[0], a[1], a[2]);
    return 0;
}
