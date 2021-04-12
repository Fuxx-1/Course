/*
编程输出下面的菱形图案，要求菱形的最大宽度由键盘输入。
   *
  *+*
 *+++*
*+++++*
 *+++*
  *+*
   *
*/
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    puts("请输入奇数: ");
    scanf("%d", &n);
    if (n - 1)
    {
        for (int i = -1; i < n; i += 2)
        {
            for (int j = 0; j < (n - i - 2) / 2; j++)
            { //空格
                printf(" ");
            }
            printf("*"); //星号
            if (i + 1)
            {
                for (int j = 0; j < i; j++)
                { //加号
                    printf("+");
                }
                printf("*"); //星号
            }
            puts(""); //回车
        }
        for (int i = n - 4; i >= -1; i -= 2)
        {
            for (int j = 0; j < (n - i - 2) / 2; j++)
            { //空格
                printf(" ");
            }
            printf("*"); //星号
            if (i + 1)
            {
                for (int j = 0; j < i; j++)
                { //加号
                    printf("+");
                }
                printf("*"); //星号
            }
            puts(""); //回车
        }
    }
    else
    {
        printf("*\n");
    }
    return 0;
}