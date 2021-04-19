#include <stdio.h>
#include <string.h>
int main(void)
{
    char a[81], b[41];
    gets(a);
    gets(b);
    int n = strlen(a);
    strcpy(a + n, b);
    puts(a);
    return 0;
}