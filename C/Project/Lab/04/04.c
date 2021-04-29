#include <stdio.h>
int main(int argc, char const* argv[])
{
    int x, y, flaga = 0, flagb = 0;
    puts("请输入两个数组个数: ");
    scanf("%d%d", &x, &y);
    int a[x], b[y], c[x + y];
    for (int i = 0; i < x; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < y; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < x + y; i++) {
        if (a[flaga] < b[flagb]) {
            c[i] = a[flaga++];
        } else {
            c[i] = b[flagb++];
        }
    }
    for (int i = 0; i < x + y; i++) {
        printf("%d ", c[i]);
    }
    return 0;
}
