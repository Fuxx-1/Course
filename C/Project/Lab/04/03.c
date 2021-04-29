#include <stdio.h>
#include <string.h>

int main(int argc, char const* argv[])
{
    char a[7][100];
    for (int i = 0; i < 6; i++) {
        gets(a[i]);
    }
    for (int i = 0; i < 6 - 1; i++) {
        for (int j = 0; j < 6 - 1 - i; j++) {
            if (strcmp(a[i], a[i + 1]) > 0) {
                strcpy(a[6], a[i]);
                strcpy(a[i], a[i + 1]);
                strcpy(a[i + 1], a[6]);
            }
        }
    }
    printf("排序完毕\n");
    for (int i = 0; i < 6; i++) {
        puts(a[i]);
    }
    return 0;
}
