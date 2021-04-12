/*
已知一张足够大的纸，厚度为0.2毫米，试编一程序求出对折多少次后，其厚度能够超过珠穆朗玛峰的高度（8848米）。
*/
#include <stdio.h>
int main(int argc, char const *argv[])
{
    double val = 0.0002;
    int ans = 0;
    while (val < 8848)
    {
        ans++, val *= 2;
    }
    printf("Frequency: %d, Height: %lf\n", ans, val);
    return 0;
}
