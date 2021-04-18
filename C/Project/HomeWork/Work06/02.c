#include <stdio.h>
int main(int argc, char const *argv[])
{
    int val[4][5];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &val[i][j]);
        }
    }
    for (int k = 0; k < 5; k++)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3 - i; j++)
            {
                if (val[j][k] > val[j + 1][k])
                {
                    int temp;
                    temp = val[j][k];
                    val[j][k] = val[j + 1][k];
                    val[j + 1][k] = temp;
                }
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%4d", val[i][j]);
        }
        printf("\n");
    }
    return 0;
}
