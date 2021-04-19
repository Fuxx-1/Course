// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int num, flag;
//     scanf("%d", &num);
//     int val[10];
//     for (int i = 0; i < num; i++)
//     {
//         scanf("%d", &val[i]);
//     }
//     scanf("%d", &flag);
//     for (int j = num-1; j >= 0; j--)
//     {
//         if (flag >= val[j])
//         {
//             val[j + 1] = flag;
//             break;
//         }
//         else
//         {
//             val[j + 1] = val[j];
//         }
//     }
//     // for (int i = 0; i < num; i++)
//     // {
//     //     if (flag > val[i])
//     //     {
//     //         int temp;
//     //         temp = flag;
//     //         flag = val[i + 1];
//     //         val[i + 1] = temp;
//     //     }
//     // }
//     for (int i = 0; i < num + 1; i++)
//     {
//         printf("%d ", val[i]);
//     }
//     return 0;
// }
#include <stdio.h>
#include <math.h>
int com(int *a, int *b)
{
    return (*(int *)a - *(int *)b);
}
int main(int argc, char const *argv[])
{
    int n, i;
    scanf("%d", &n);
    int a[n + 1];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &a[i]);
    qsort(a, n + 1, sizeof(int), com);
    for (i = 0; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
