void WriteFile(Stu* FatherNode) //д�ļ�
{
    Stu* ActionNode = FatherNode;
    //����
    char ABS[1001];
    FILE* File = NULL;
    //���ļ�
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

void Print(Stu* FatherNode) //�������
{
    Stu* ActionNode = FatherNode;
    printf("%20s\t%20s\t%3s\t%s\t%s\t%s\t%s\t%s\n", "ѧ��", "����", "�Ա�", "����", "����", "��ѧ", "C����", "��");
    while (ActionNode != NULL) {
        printf("%20s\t%20s\t%3s\t%02d\t%02d\t%02d\t%02d\t%d\n", ActionNode->id, ActionNode->name, ActionNode->isMale ? "��" : "Ů", ActionNode->age, ActionNode->Chinese, ActionNode->Math, ActionNode->C, ActionNode->Sum);
        ActionNode = ActionNode->next;
    }
    fflush(stdin);
    int a = getchar();
}

void PrintResult(int i) //��ӡ���
{
    if (i == 0) {
        printf("��ѯ���Ϊ�գ�");
        sleep(2);
    } else {
        printf("��ѯ�����\n");
        printf("%20s\t%20s\t%3s\t%s\t%s\t%s\t%s\t%s\n", "ѧ��", "����", "�Ա�", "����", "����", "��ѧ", "C����", "��");
        for (int j = 0; j < i; j++) {
            printf("%20s\t%20s\t%3s\t%02d\t%02d\t%02d\t%02d\t%d\n", ResultTemp[j]->id, ResultTemp[j]->name, ResultTemp[j]->isMale ? "��" : "Ů", ResultTemp[j]->age, ResultTemp[j]->Chinese, ResultTemp[j]->Math, ResultTemp[j]->C, ResultTemp[j]->Sum);
        }
        fflush(stdin);
        int a = getchar();
    }
}