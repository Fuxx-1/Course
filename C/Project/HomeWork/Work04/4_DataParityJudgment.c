#include <stdio.h>
int main(void)
{
    int Fir, Sec;
    scanf("%d,%d", &Fir, &Sec);
    if (!Fir || !Sec)
    {
    }
    else if (Fir % 2)
    { //Fir为奇数
        printf("%d%c%d=%d\n", Fir, Sec % 2 ? '-' : '*', Sec, Sec % 2 ? Fir - Sec : Fir * Sec);
    }
    else
    { //Fir为偶数
        printf("%d%c%d=%d\n", Fir, Sec % 2 ? '/' : '+', Sec, Sec % 2 ? Fir / Sec : Fir + Sec);
    }
    return 0;
}