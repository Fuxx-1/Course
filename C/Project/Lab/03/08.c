/*
北京市体育彩票采用整数1、2、3、……、36表示36种体育运动，一张彩票可选择7种活动。编写程序，选择一张彩票的号码，使得这张彩票的7个号码之和是105且相邻两个号码之差按顺序1、2、3、4、5、6。如果第一个号码是1，则后续号码应是2、4、7、11、16、22。
*/
#include <stdio.h>
int main(int argc, char const *argv[])
{
    /* 7x + 56*/
    int a =  (105 - 56) / 7, flag = 1;
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", a);
        a += flag++;
    }
    return 0;
}
