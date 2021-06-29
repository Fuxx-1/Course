#include "Default.h"

int Menu(); //打印菜单并或取函数调用信息
int SearchNode(Stu* FatherNode); //查询节点
void DeleteNode(int i); //对结果进行判断并删除
void ChangeInfo(int i); //对结果进行修改
Stu* SortInfo(Stu* FatherNode); //排序
int CompareTo(Stu* Node1, Stu* Node2, int flag1, int flag2); //节点比较
Stu* InsertNode(Stu* FatherNode, Stu* NewNode); //插入节点
Stu* CreateNode(); //创建节点
Stu* ReadInfoFromFile(); //从文件中读取信息
void AddNewInfo(Stu* FatherNode); //从屏幕获取数据
void WriteFile(Stu* FatherNode); //写文件
void Print(Stu* FatherNode); //输出数据
void PrintResult(int i); //打印结果

int main(int argc, char const* argv[])
{
    //从文件中读取信息
    Stu* FatherNode = ReadInfoFromFile();
    //该变量用于函数调用信息
    int CallInformation = 0;
    while (CallInformation = Menu()) {
        system("cls"); //清屏，仅windows
        switch (CallInformation) {
        case 0:
            printf("关闭系统中\n");
            sleep(1);
            break;
        case 1:
            //增加学生信息
            AddNewInfo(FatherNode);
            break;
        case 2:
            //查询学生信息（允许使用姓名或学号查询）
            PrintResult(SearchNode(FatherNode));
            break;
        case 3:
            //修改学生信息（除姓名和学号）
            ChangeInfo(SearchNode(FatherNode));
            break;
        case 4:
            //删除学生信息
            DeleteNode(SearchNode(FatherNode));
            break;
        case 5:
            //排序输出学生信息
            FatherNode = SortInfo(FatherNode);
            break;
        case 6:
            //输出学生信息
            Print(FatherNode);
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

int Menu() //打印菜单并或取函数调用信息
{
    int temp = 8;
    system("cls");
    system("color 0A");
    printf("\n欢迎来到学生成绩管理系统！\n\n");
    printf("===============================================\n");
    printf("  0、退出                                      \n");
    printf("  1、增加学生信息                               \n");
    printf("  2、查询学生信息（允许使用姓名或学号查询）        \n");
    printf("  3、修改学生信息（除姓名和学号）                \n");
    printf("  4、删除学生信息（先查询）                      \n");
    printf("  5、排序输出学生信息                           \n");
    printf("  6、输出学生信息                              \n");
    printf("  请输入需要功能的编号，直接关闭系统可能损坏数据  \n");
    printf("===============================================\n");
    // setbuf(stdin, NULL);
    fflush(stdin);
    scanf("%d", &temp);
    system("color 0E");
    return temp;
}

int SearchNode(Stu* FatherNode) //查询节点
{
    system("cls");
    Stu* ActionNode = FatherNode;
    int temp, i = 0;
    //打印菜单并获取用户输入
    printf("===============================================\n");
    printf("  1、使用姓名查询                               \n");
    printf("  2、使用学号查询                               \n");
    printf("  请输入需要功能的编号，直接关闭系统可能损坏数据   \n");
    printf("===============================================\n");
    scanf("%d", &temp);
    char SearchVal[41];
    //判断
    if (temp == 1) {
        printf("输入要查询的学生姓名：");
        scanf("%s", SearchVal);
        while (1) {
            if (!strcmp(ActionNode->name, SearchVal)) {
                ResultTemp[i++] = ActionNode;
            }
            if (ActionNode->next != NULL) {
                ActionNode = ActionNode->next;
            } else {
                break;
            }
        }
    } else if (temp == 2) {
        printf("输入要查询的学生学号：");
        scanf("%s", SearchVal);
        while (1) {
            if (!strcmp(ActionNode->id, SearchVal)) {
                ResultTemp[i++] = ActionNode;
            }
            if (ActionNode->next != NULL) {
                ActionNode = ActionNode->next;
            } else {
                break;
            }
        }
    }
    system("cls");
    return i;
}

void DeleteNode(int i) //对结果进行判断并删除
{
    char chose;
    int temp;
    if (i == 0) {
        printf("查询结果为空！");
        sleep(2);
    } else {
        do {
            system("cls");
            printf("查询结果：\n");
            printf("%2s%20s\t%20s\t%3s\t%s\t%s\t%s\t%s\t%s\n", "编号", "学号", "姓名", "性别", "年龄", "语文", "数学", "C语言", "总");
            for (int j = 0; j < i && j < 10; j++) {
                printf("%02d%20s\t%20s\t%3s\t%02d\t%02d\t%02d\t%02d\t%d\n", j + 1, ResultTemp[j]->id, ResultTemp[j]->name, ResultTemp[j]->isMale ? "男" : "女", ResultTemp[j]->age, ResultTemp[j]->Chinese, ResultTemp[j]->Math, ResultTemp[j]->C, ResultTemp[j]->Sum);
            }

            printf("请输入要删除的编号：\n");
            scanf("%d", &temp);
            //删除节点
            if (ResultTemp[temp - 1]->prev != NULL) {
                ResultTemp[temp - 1]->prev->next = ResultTemp[temp - 1]->next;
            }
            if (ResultTemp[temp - 1]->next != NULL) {
                ResultTemp[temp - 1]->next->prev = ResultTemp[temp - 1]->prev;
            }
            //释放空间
            free(ResultTemp[temp - 1]);
            //循环调用
            printf("是否继续删除(y/n)：\n");
            //清除StdIn
            fflush(stdin);
            scanf("%c", &chose);
        } while (chose == 'Y' || chose == 'y');
    }
}

void ChangeInfo(int i) //对结果进行修改
{
    char chose;
    int temp, temp2, temp3;
    if (i == 0) {
        printf("查询结果为空！");
        sleep(2);
    } else {
        do {
            system("cls");
            printf("查询结果：\n");
            printf("%2s%20s\t%20s\t%3s\t%s\t%s\t%s\t%s\t%s\n", "编号", "学号", "姓名", "性别", "年龄", "语文", "数学", "C语言", "总");
            for (int j = 0; j < i && j < 10; j++) {
                printf("%02d%20s\t%20s\t%3s\t%02d\t%02d\t%02d\t%02d\t%d\n", j + 1, ResultTemp[j]->id, ResultTemp[j]->name, ResultTemp[j]->isMale ? "男" : "女", ResultTemp[j]->age, ResultTemp[j]->Chinese, ResultTemp[j]->Math, ResultTemp[j]->C, ResultTemp[j]->Sum);
            }
            printf("请输入要修改的编号：\n");
            scanf("%d", &temp);
            system("cls");
            printf("现值：\n学号：%s\n姓名：%s\n%d、性别：%s\n%d、年龄：%d\n%d、语文：%d\n%d、数学：%d\n%d、C语言：%d\n", ResultTemp[temp - 1]->id, ResultTemp[temp - 1]->name, 1, ResultTemp[temp - 1]->isMale ? "男" : "女", 2, ResultTemp[temp - 1]->age, 3, ResultTemp[temp - 1]->Chinese, 4, ResultTemp[temp - 1]->Math, 5, ResultTemp[temp - 1]->C);
            printf("请输入要修改的编号：\n");
            scanf("%d", &temp2);
            printf("请输入要修改的值：\n");
            scanf("%d", &temp3);
            switch (temp2) {
            case 1:
                if (temp3 != 0 && temp3 != 1) {
                    break;
                }
                ResultTemp[temp - 1]->isMale = temp3;
                break;
            case 2:
                if (temp3 >= 100 || temp3 <= 0) {
                    break;
                }
                ResultTemp[temp - 1]->age = temp3;
                break;
            case 3:
                if (temp3 >= 100 || temp3 <= 0) {
                    break;
                }
                ResultTemp[temp - 1]->Chinese = temp3;
                break;
            case 4:
                if (temp3 >= 100 || temp3 <= 0) {
                    break;
                }
                ResultTemp[temp - 1]->Math = temp3;
                break;
            case 5:
                if (temp3 >= 100 || temp3 <= 0) {
                    break;
                }
                ResultTemp[temp - 1]->C = temp3;
                break;

            default:
                break;
            }
            ResultTemp[temp - 1]->Sum = ResultTemp[temp - 1]->C + ResultTemp[temp - 1]->Chinese + ResultTemp[temp - 1]->Math;
            printf("修改后：\n学号：%s\n姓名：%s\n%d、性别：%s\n%d、年龄：%d\n%d、语文：%d\n%d、数学：%d\n%d、C语言：%d\n", ResultTemp[temp - 1]->id, ResultTemp[temp - 1]->name, 1, ResultTemp[temp - 1]->isMale ? "男" : "女", 2, ResultTemp[temp - 1]->age, 3, ResultTemp[temp - 1]->Chinese, 4, ResultTemp[temp - 1]->Math, 5, ResultTemp[temp - 1]->C);
            printf("是否继续修改(y/n)：\n");
            fflush(stdin);
            scanf("%c", &chose);
        } while (chose == 'Y' || chose == 'y');
    }
}

Stu* SortInfo(Stu* FatherNode) //排序
{
    int temp, n = 1, flag, temp1, temp2;
    Stu *TempNode = FatherNode, *TempNode2 = FatherNode, *ActionNode = FatherNode, *MoveNode;
    while (TempNode->next != NULL) {
        TempNode = TempNode->next;
        n++;
    }
    printf("===============================================\n");
    printf(" 请输入要排序的数据选项                          \n");
    printf("  1、学号                                      \n");
    printf("  2、语文                                       \n");
    printf("  3、数学                                       \n");
    printf("  4、C语言                                      \n");
    printf("  5、总成绩                                     \n");
    printf("  请输入需要功能的编号，直接关闭系统可能损坏数据   \n");
    printf("===============================================\n");
    scanf("%d", &temp1);
    printf("===============================================\n");
    printf("  0、升序                                       \n");
    printf("  1、降序                                       \n");
    printf("  请输入需要功能的编号，直接关闭系统可能损坏数据   \n");
    printf("===============================================\n");
    scanf("%d", &temp2);
    /* 找到极值 */
    TempNode = FatherNode;
    TempNode2 = FatherNode;
    while (TempNode2->next != NULL) {
        if (CompareTo(TempNode, TempNode2->next, temp1, temp2) < 0) {
            TempNode = TempNode2->next;
        }
        TempNode2 = TempNode2->next;
    }
    /* 极值断裂 */
    if (TempNode->next != NULL) {
        TempNode2 = TempNode->next;
    } else {
        TempNode2 = TempNode->prev;
    }
    if (TempNode->next != NULL) {
        TempNode->next->prev = TempNode->prev;
    }
    if (TempNode->prev != NULL) {
        TempNode->prev->next = TempNode->next;
    }
    TempNode->next = NULL;
    TempNode->prev = NULL;
    while (TempNode2->prev != NULL) {
        TempNode2 = TempNode2->prev;
    }
    /* 更改顺序 */
    while (TempNode2->next != NULL) {
        ActionNode = TempNode2;
        TempNode2 = TempNode2->next;
        MoveNode = TempNode;
        while (1) {
            if (CompareTo(MoveNode, ActionNode, temp1, temp2) > 0) {
                if (MoveNode->next == NULL || CompareTo(MoveNode->next, ActionNode, temp1, temp2) < 0) {
                    break;
                } else {
                    MoveNode = MoveNode->next;
                }
            } else {
                break;
            }
        }
        InsertNode(MoveNode, ActionNode);
    }
    system("cls");
    Print(TempNode);
    return TempNode;
}

int CompareTo(Stu* Node1, Stu* Node2, int flag1, int flag2) //节点比较
{
    if (Node1 == NULL) {
        return flag2 ? -1 : 1;
    } else if (Node2 == NULL) {
        return flag2 ? 1 : -1;
    }
    switch (flag1) {
    case 1:
        if (strlen(Node1->id) != strlen(Node2->id)) {
            return flag2 ? strlen(Node1->id) - strlen(Node2->id) : strlen(Node2->id) - strlen(Node1->id);
        } else {
            return flag2 ? strcmp(Node1->id, Node2->id) : strcmp(Node2->id, Node1->id);
        }
        break;
    case 2:
        return flag2 ? Node1->Chinese - Node2->Chinese : Node2->Chinese - Node1->Chinese;
        break;
    case 3:
        return flag2 ? Node1->Math - Node2->Math : Node2->Math - Node1->Math;
        break;
    case 4:
        return flag2 ? Node1->C - Node2->C : Node2->C - Node1->C;
        break;
    case 5:
        return flag2 ? Node1->Sum - Node2->Sum : Node2->Sum - Node1->Sum;
        break;

    default:
        system("color F4");
        printf("\n\n\t请输入正确的序号\n");
        sleep(2);
        system("color 0E");
        break;
    }
}

Stu* InsertNode(Stu* FatherNode, Stu* NewNode) //插入节点
{
    if (FatherNode->next != NULL) {
        FatherNode->next->prev = NewNode;
    }

    NewNode->prev = FatherNode;
    if (FatherNode != NULL) {
        NewNode->next = FatherNode->next;
        FatherNode->next = NewNode;
    }
}

Stu* CreateNode() //创建节点
{
    tempNode.Sum = tempNode.Chinese + tempNode.Math + tempNode.C;
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

Stu* ReadInfoFromFile() //从文件中读取信息
{
    //定义
    char ABS[1001];
    FILE* File = NULL;
    //打开文件
    getcwd(ABS, 1000);
    File = fopen(strcat(ABS, "\\Information"), "r");
    fscanf(File, "%s%s%d%d%d%d%d%d", &tempNode.id, &tempNode.name, &tempNode.isMale, &tempNode.age, &tempNode.Chinese, &tempNode.Math, &tempNode.C, &tempNode.Sum);
    //定义父节点
    Stu* FatherNode = CreateNode();
    while (fscanf(File, "%s%s%d%d%d%d%d%d", &tempNode.id, &tempNode.name, &tempNode.isMale, &tempNode.age, &tempNode.Chinese, &tempNode.Math, &tempNode.C, &tempNode.Sum) != EOF) {
        InsertNode(FatherNode, CreateNode());
    }
    return FatherNode;
}

void AddNewInfo(Stu* FatherNode) //从屏幕获取数据
{
    Stu* ActionNode = FatherNode;
    fflush(stdin);
    printf("请输入学号（20个数字内）：\n");
    scanf("%s", &tempNode.id);
    while (ActionNode->next != NULL) {
        if (ActionNode->id == tempNode.id) {
            system("color F4");
            printf("\n\n\t请输入不重复的学号\n");
            sleep(2);
            system("color 0E");
            return;
        } else {
            ActionNode = ActionNode->next;
        }
    }
    printf("请输入姓名（20字内）：\n");
    scanf("%s", &tempNode.name);
    printf("请输入性别（男为1，女为0）：\n");
    scanf("%d", &tempNode.isMale);
    printf("请输入年龄：\n");
    scanf("%d", &tempNode.age);
    printf("请输入语文成绩（<100）：\n");
    scanf("%d", &tempNode.Chinese);
    printf("请输入数学成绩（<100）：\n");
    scanf("%d", &tempNode.Math);
    printf("请输入C语言成绩（<100）：\n");
    scanf("%d", &tempNode.C);
    if (tempNode.age >= 0 && tempNode.C <= 100 && tempNode.C >= 100 && tempNode.Chinese <= 100 && tempNode.Chinese >= 100 && tempNode.Math <= 100 && tempNode.Math >= 100 && (tempNode.isMale == 0 || tempNode.isMale == 1) && strlen(tempNode.name) > 0 && strlen(tempNode.id) > 0) {
        printf("输入有误，请重新输入");
    } else {
        InsertNode(FatherNode, CreateNode());
    }
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

void Print(Stu* FatherNode) //输出数据
{
    Stu* ActionNode = FatherNode;
    printf("%20s\t%20s\t%3s\t%s\t%s\t%s\t%s\t%s\n", "学号", "姓名", "性别", "年龄", "语文", "数学", "C语言", "总");
    while (ActionNode != NULL) {
        printf("%20s\t%20s\t%3s\t%02d\t%02d\t%02d\t%02d\t%d\n", ActionNode->id, ActionNode->name, ActionNode->isMale ? "男" : "女", ActionNode->age, ActionNode->Chinese, ActionNode->Math, ActionNode->C, ActionNode->Sum);
        ActionNode = ActionNode->next;
    }
    fflush(stdin);
    int a = getchar();
}

void PrintResult(int i) //打印结果
{
    if (i == 0) {
        printf("查询结果为空！");
        sleep(2);
    } else {
        printf("查询结果：\n");
        printf("%20s\t%20s\t%3s\t%s\t%s\t%s\t%s\t%s\n", "学号", "姓名", "性别", "年龄", "语文", "数学", "C语言", "总");
        for (int j = 0; j < i; j++) {
            printf("%20s\t%20s\t%3s\t%02d\t%02d\t%02d\t%02d\t%d\n", ResultTemp[j]->id, ResultTemp[j]->name, ResultTemp[j]->isMale ? "男" : "女", ResultTemp[j]->age, ResultTemp[j]->Chinese, ResultTemp[j]->Math, ResultTemp[j]->C, ResultTemp[j]->Sum);
        }
        fflush(stdin);
        int a = getchar();
    }
}