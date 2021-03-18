#include <stdio.h>
int main(void)
{
    char a;
    while (scanf("%c", &a) != EOF)
    {
        if (a == '#')
        {
            break;
        }
        if (a <= 'Z' && a >= 'A')
        {
            a = a + 'a' - 'A';
        }
        else if (a <= 'z' && a >= 'a')
        {
            a = a + 'A' - 'a';
        }
        printf("%c", a);
    }
    return 0;
}