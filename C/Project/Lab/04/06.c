#include <stdio.h>

typedef struct Student {
    int id;
    int achievement;
} Node;

int main(int argc, char const* argv[])
{
    int n, val = 1;
    Node a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].achievement);
        a[i].id = val++;
    }

    return 0;
}
