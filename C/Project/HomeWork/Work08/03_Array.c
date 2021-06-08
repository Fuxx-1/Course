#include <stdio.h>
#include <string.h>
int main(int argc, char const* argv[])
{
    static int a[100000];
    int m, n, flag, data, Garbage;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &flag);
        if (!(flag - 1)) {
            scanf("%d", &data);
            if (data > 0 && data <= n) {
                for (int j = data - 1; j < n; j++) {
                    a[j] = a[j + 1];
                }
                n--;
            }
        } else if (!flag) {
            scanf("%d", &data);
            if (data >= 0 && data <= n) {
                for (int j = n + 1; j > data; j--) {
                    a[j] = a[j - 1];
                }
                n++;
                scanf("%d", &a[data]);
            } else {
                scanf("%d", &Garbage);
            }
        } else {
            printf("???????????");
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
