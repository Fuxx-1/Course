#include <stdio.h>
#include <stdlib.h>
typedef struct stu {
    int id;
    double Source;
} Node;

int cmpfunc(const void* a, const void* b)
{
    if (((*(Node*)a).Source != (*(Node*)b).Source)) {
        return ((*(Node*)b).Source > (*(Node*)a).Source) ? 1 : -1;
    } else {
        return ((*(Node*)a).id - (*(Node*)b).id);
    }
}

int main(int argc, char const* argv[])
{
    Node a[110];
    int x;
    scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        scanf("%d", &a[i].id);
        scanf("%lf", &a[i].Source);
    }
    qsort(a, x, sizeof(Node), cmpfunc);
    int count = 0;
    double source = 0.01;
    for (int i = 0; i < x; i++) {
        if (!(source - a[i].Source)) {
            printf("%d %d %.2lf", count, a[i].id, a[i].Source);
        } else {
            printf("%d %d %.2lf", i + 1, a[i].id, a[i].Source);
            source = a[i].Source;
            count = i + 1;
        }
        if (i != x - 1) {
            printf("\n");
        }
    }
    return 0;
}
