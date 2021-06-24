#include <stdio.h>
int main(int argc, char const* argv[])
{
    //定义
    char ABS[1001], b;
    FILE* File = NULL;
    //打开文件
    getcwd(ABS, 1000);
    File = fopen(strcat(ABS, "\\File.txt"), "w+");
    //输入输出
    b = getchar();
    while (b != '#') {
        fprintf(File, "%c", b);
        b = getchar();
    }
    return 0;
}
