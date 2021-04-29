#include <stdio.h>
int main(int argc, char const* argv[])
{
    int x, y;
    puts("请输入长宽");
    scanf("%d%d", &x, &y);
    int a[x][y];
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }
    return 0;
}
