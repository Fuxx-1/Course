#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char id[21]; //学号(编号为1)
    char name[41]; //姓名(编号为2)
    bool isMale; //性别，true为男，false为女(编号为3)
    int age; //年龄(编号为4)
    int Chinese; //语文成绩(编号为5)
    int Math; //数学成绩(编号为6)
    int C; //C语言成绩(编号为7)
    int Sum; //总分(编号为8)
    struct Student* prev;
    struct Student* next;
} Stu;

//定义全局临时变量
Stu tempNode = { "", "", 0, 0, 0, 0, 0, 0 };

void AddNewInfo(Stu* FatherNode); //从屏幕获取数据
int CompareTo(Stu* First, Stu* Second, int flag); //节点比较函数
Stu* SearchNode(); //查询节点
Stu* InsertNode(Stu* FatherNode, Stu* NewNode); //插入节点
Stu* CreateNode(); //创建节点
Stu* ReadInfoFromFile(); //从文件中读取信息
int Menu(); //打印菜单并或取函数调用信息
void WriteFile(Stu* FatherNode); //写文件

int main(int argc, char const* argv[])
{
    //调整编码格式并清屏，仅windows
    system("chcp 65001");
    system("cls");
    //从文件中读取信息
    Stu* FatherNode = ReadInfoFromFile();
    //该变量用于函数调用信息
    int CallInformation = 0;
    while (CallInformation = Menu()) {
        system("cls"); //清屏，仅windows
        switch (CallInformation) {
        case 0:
            printf("关闭系统\n");
            sleep(1);
            break;
        case 1:
            //增加学生信息
            AddNewInfo();
            break;
        case 2:
            //查询学生信息（允许使用姓名或学号查询）
            /* code */
            break;
        case 3:
            //修改学生信息（除姓名和学号）
            /* code */
            break;
        case 4:
            //删除学生信息
            /* code */
            break;
        case 5:
            //排序输出学生信息
            /* code */
            break;
        case 6:
            //输出学生信息
            /* code */
            break;
        default:
            system("color F4");
            printf("\n\n\t请输入正确的序号\n");
            sleep(2);
            system("color 0E");
            break;
        }
    }
    WriteFile(FatherNode);
    return 0;
}

Stu* ReadInfoFromFile() //从文件中读取信息
{
    //定义
    char ABS[1001];
    FILE* File = NULL;
    //打开文件
    getcwd(ABS, 1000);
    File = fopen(strcat(ABS, "\\Information"), "a+");
    fscanf(File, "%s%s%d%d%d%d%d%d", &tempNode.id, &tempNode.name, &tempNode.isMale, &tempNode.age, &tempNode.Chinese, &tempNode.Math, &tempNode.C, &tempNode.Sum);
    //定义父节点
    Stu* FatherNode = CreateNode();
    while (fscanf(File, "%s%s%d%d%d%d%d%d", &tempNode.id, &tempNode.name, &tempNode.isMale, &tempNode.age, &tempNode.Chinese, &tempNode.Math, &tempNode.C, &tempNode.Sum) != EOF) {
        InsertNode(FatherNode, CreateNode());
    }
    return FatherNode;
}

int Menu() //打印菜单并或取函数调用信息
{
    int temp = 8;
    system("cls");
    system("color 0E");
    printf("\n欢迎来到学生成绩管理系统！\n\n");
    printf("===============================================\n");
    printf("  0、退出                                      \n");
    printf("  1、增加学生信息                               \n");
    printf("  2、查询学生信息（允许使用姓名或学号查询）        \n");
    printf("  3、修改学生信息（除姓名和学号）                \n");
    printf("  4、删除学生信息                               \n");
    printf("  5、排序输出学生信息                           \n");
    printf("  6、输出学生信息                              \n");
    printf("  请输入需要功能的编号，直接关闭系统可能损坏数据  \n");
    printf("===============================================\n");
    // setbuf(stdin, NULL);
    fflush(stdin);
    scanf("%d", &temp);
    return temp;
}

int CompareTo(Stu* First, Stu* Second, int flag) //节点比较函数
{
}

Stu* SearchNode() //查询节点
{
}

void AddNewInfo(Stu* FatherNode) //从屏幕获取数据
{
    printf("请输入姓名（20字内）：\n");
    scanf("%s", &tempNode.name);
    printf("请输入学号（20个数字内）：\n");
    scanf("%s", &tempNode.id);
    printf("请输入性别（男为1，女为0）：\n");
    scanf("%s", &tempNode.isMale);
    printf("请输入年龄（20字内）：\n");
    scanf("%s", &tempNode.age);
    printf("请输入语文成绩（20字内）：\n");
    scanf("%s", &tempNode.Chinese);
    printf("请输入数学成绩（20字内）：\n");
    scanf("%s", &tempNode.Math);
    printf("请输入C语言成绩（20字内）：\n");
    scanf("%s", &tempNode.C);
    if (tempNode.age >= 0 && tempNode.C <= 100 && tempNode.C >= 100 && tempNode.Chinese <= 100 && tempNode.Chinese >= 100 && tempNode.Math <= 100 && tempNode.Math >= 100 && (tempNode.isMale == 0 || tempNode.isMale == 1) && strlen(tempNode.name) > 0 && strlen(tempNode.id) > 0) {
        printf("输入有误，请重新输入");
    } else {
        InsertNode(FatherNode, CreateNode());
    }
}

Stu* InsertNode(Stu* FatherNode, Stu* NewNode) //插入节点
{
    Stu* ActionNode = FatherNode;
    while (ActionNode->next != NULL) {
        ActionNode = ActionNode->next;
    }
    ActionNode->next = NewNode;
    NewNode->prev = ActionNode;
}

Stu* CreateNode() //创建节点
{
    Stu* NewNode = (Stu*)malloc(sizeof(Stu));
    strcpy(NewNode->id, tempNode.id);
    strcpy(NewNode->name, tempNode.name);
    NewNode->isMale = tempNode.isMale;
    NewNode->age = tempNode.age;
    NewNode->Chinese = tempNode.Chinese;
    NewNode->Math = tempNode.Math;
    NewNode->C = tempNode.C;
    NewNode->Sum = tempNode.Sum;
    NewNode->prev = NULL;
    NewNode->next = NULL;
    return NewNode;
}

void WriteFile(Stu* FatherNode) //写文件
{
    Stu* ActionNode = FatherNode;
    //定义
    char ABS[1001];
    FILE* File = NULL;
    //打开文件
    getcwd(ABS, 1000);
    File = fopen(strcat(ABS, "\\Information"), "w+");
    while (fprintf(File, "%s %s %d %d %d %d %d %d\n", ActionNode->id, ActionNode->name, ActionNode->isMale, ActionNode->age, ActionNode->Chinese, ActionNode->Math, ActionNode->C, ActionNode->Sum)) {
        if (ActionNode->next != NULL) {
            ActionNode = ActionNode->next;
        } else {
            break;
        }
    }
}