#include <stdio.h>
int main(void)
{
    int H, M;
    scanf("%d:%d", &H, &M);
    if (H > 12 || H == 12 && M > 0)
    {
        printf("%02d:%02d PM\n", H != 12 ? H - 12 : H, M);
    }
    else
    {
        printf("%02d:%02d AM\n", H, M);
    }
    return 0;
}