#include <stdio.h>
typedef struct Stu {
    int uid;
    char uname[10];
    int Achieve_Chinese;
    int Achieve_Math;
    int Achieve_Computer;
    int Ave;
} Node;
int cmp(const void* Node1, const void* Node2)
{
    Node* Stu1 = (Node*)Node1;
    Node* Stu2 = (Node*)Node2;
    return Stu2->Ave - Stu1->Ave;
}
int main(int argc, char const* argv[])
{
    //定义
    char ABS[1001];
    FILE *File = NULL, *File_Sort = NULL;
    //打开文件
    getcwd(ABS, 1000);
    File = fopen(strcat(ABS, "\\stu.txt"), "a+");
    getcwd(ABS, 1000);
    File_Sort = fopen(strcat(ABS, "\\stu_sort.txt"), "w+");
    Node Info[30];
    for (int i = 0; i < 30; i++) {
        fscanf(File, "%d%s%d%d%d", &Info[i].uid, &Info[i].uname, &Info[i].Achieve_Chinese, &Info[i].Achieve_Math, &Info[i].Achieve_Computer);
        Info[i].Ave = (Info[i].Achieve_Chinese + Info[i].Achieve_Math + Info[i].Achieve_Computer) / 3;
    }
    qsort(Info, 30, sizeof(Node), cmp);
    fprintf(File_Sort, "%8s\t\t%s\t\t%2s\t\t%2s\t\t%2s\t\t%2s\n", "ID", "姓名", "语文", "数学", "电脑", "平均");

    for (int i = 0; i < 30; i++) {
        fprintf(File_Sort, "%08d\t\t%s\t\t%2d\t\t%2d\t\t%2d\t\t%2d\n", Info[i].uid, Info[i].uname, Info[i].Achieve_Chinese, Info[i].Achieve_Math, Info[i].Achieve_Computer, Info[i].Ave);
    }
    return 0;
}