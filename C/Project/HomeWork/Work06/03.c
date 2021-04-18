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