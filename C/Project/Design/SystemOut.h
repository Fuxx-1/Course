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