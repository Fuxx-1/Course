#include <stdio.h>
int main(int argc, char const *argv[])
{
    int val = 11, flag, N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        flag = val;
        for (int j = 0; j < N; j++)
        {
            printf("%4d", flag++);
        }
        val += 10;
        printf("\n");
    }
    return 0;
}
