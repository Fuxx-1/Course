#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void* a, const void* b)
{
    return (*(char*)a - *(char*)b);
}
int main(int argc, char const* argv[])
{
    //定义
    char ABS[1001], a[1001], b[1001], c[2001];
    FILE *FileForString = NULL, *NewFileForString = NULL;
    //打开文件
    getcwd(ABS, 1000);
    FileForString = fopen(strcat(ABS, "\\FileForString.txt"), "a+");
    getcwd(ABS, 1000);
    NewFileForString = fopen(strcat(ABS, "\\NewFileForString.txt"), "w+");
    //输入
    fscanf(FileForString, "%s%s", &a, &b);
    //拼接
    c[0] = 0;
    strcat(c, a), strcat(c, b);
    //排序
    qsort(c, strlen(c), sizeof(char), cmp);
    //输出
    fprintf(NewFileForString, "%s\n", c);
    return 0;
}
