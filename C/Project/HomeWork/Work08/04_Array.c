#include <stdio.h>
int main(int argc, char const* argv[])
{
    int temp = 0, a[100], b[100], i = 0, n, m;
    while (temp != -1) {
        scanf("%d", &temp);
        a[i++] = temp;
    }
    i--;
    n = i - 1;
    //此时i为数据数量
    m = i / 2 * 2 - 2;
    for (int j = m; j >= 0; j -= 2) {
        printf("%d ", a[j]);
        b[n--] = a[j];
    }
    for (int j = 1; j <= i; j += 2) {
        if (j < i - 1) {
            printf("%d ", a[j]);
        } else {
            printf("%d", a[j]);
        }
        b[n--] = a[j];
    }
    printf("\n");
    for (int j = 0; j < i; j++) {
        if (j != i - 1) {
            printf("%d ", b[j]);
        } else {
            printf("%d\n", b[j]);
        }
    }
    return 0;
}
