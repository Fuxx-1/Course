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
            printf("是否继续删除(y/n)：\n");
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
