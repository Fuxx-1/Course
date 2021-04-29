#include <stdio.h>
int main(int argc, char const* argv[])
{
    int a[10], max_val = -1, max_id, Sum;
    puts("请输入成绩: ");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 10; i++) {
        if (a[i] > max_val) {
            max_val = a[i];
            max_id = i + 1;
        }
        Sum += a[i];
    }
    printf("MaxVal: %d  Maxid: %d\nAve: %.2lf", max_val, max_id, Sum / 10.0);
    return 0;
}
