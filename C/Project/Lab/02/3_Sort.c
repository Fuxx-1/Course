#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(int argc, char const *argv[])
{
    int a[3], temp;
    scanf("%d%d%d", &a[0], &a[1], &a[2]);
    if (a[1] > a[0])
    {
        temp = a[1], a[1] = a[0], a[0] = temp;
    }
    if (a[2] > a[1])
    {
        temp = a[1], a[1] = a[2], a[2] = temp;
    }
    if (a[1] > a[0])
    {
        temp = a[1], a[1] = a[0], a[0] = temp;
    }
    printf("%d %d %d", a[0], a[1], a[2]);
    return 0;
}
