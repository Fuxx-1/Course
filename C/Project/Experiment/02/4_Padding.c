#include <stdio.h>
int main(int argc, char const *argv[])
{
    char a;
    a = getchar();
    a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z' ? puts("是字母！") : (a >= '0' && a <= '9' ? puts("是数字！") : puts("什么都不是？"));
    return 0;
}
