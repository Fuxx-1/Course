#include <stdio.h>

typedef struct Info {
    int id;
    char name[20];
    char Occupation;
    char Title[20];
} Node;

int main(int argc, char const* argv[])
{
    int x = 0, t = 0;
    Node a[100];
    scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        scanf("%d%s %c%[^\n]", &a[i].id, &a[i].name, &a[i].Occupation, &a[i].Title);
        if (a[i].Occupation == 't') {
            t++;
        }
        printf("%d %s %c%s\n", a[i].id, a[i].name, a[i].Occupation, a[i].Title);
    }
    printf("tcount = %d, wcount = %d", t, x - t);
    return 0;
}
