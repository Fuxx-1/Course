int SearchNode(Stu* FatherNode) //��ѯ�ڵ�
{
    system("cls");
    Stu* ActionNode = FatherNode;
    int temp, i = 0;
    //��ӡ�˵�����ȡ�û�����
    printf("===============================================\n");
    printf("  1��ʹ��������ѯ                               \n");
    printf("  2��ʹ��ѧ�Ų�ѯ                               \n");
    printf("  ��������Ҫ���ܵı�ţ�ֱ�ӹر�ϵͳ����������   \n");
    printf("===============================================\n");
    scanf("%d", &temp);
    char SearchVal[41];
    //�ж�
    if (temp == 1) {
        printf("����Ҫ��ѯ��ѧ��������");
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
        printf("����Ҫ��ѯ��ѧ��ѧ�ţ�");
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

void DeleteNode(int i) //�Խ�������жϲ�ɾ��
{
    char chose;
    int temp;
    if (i == 0) {
        printf("��ѯ���Ϊ�գ�");
        sleep(2);
    } else {
        do {
            system("cls");
            printf("��ѯ�����\n");
            printf("%2s%20s\t%20s\t%3s\t%s\t%s\t%s\t%s\t%s\n", "���", "ѧ��", "����", "�Ա�", "����", "����", "��ѧ", "C����", "��");
            for (int j = 0; j < i && j < 10; j++) {
                printf("%02d%20s\t%20s\t%3s\t%02d\t%02d\t%02d\t%02d\t%d\n", j + 1, ResultTemp[j]->id, ResultTemp[j]->name, ResultTemp[j]->isMale ? "��" : "Ů", ResultTemp[j]->age, ResultTemp[j]->Chinese, ResultTemp[j]->Math, ResultTemp[j]->C, ResultTemp[j]->Sum);
            }

            printf("������Ҫɾ���ı�ţ�\n");
            scanf("%d", &temp);
            //ɾ���ڵ�
            if (ResultTemp[temp - 1]->prev != NULL) {
                ResultTemp[temp - 1]->prev->next = ResultTemp[temp - 1]->next;
            }
            if (ResultTemp[temp - 1]->next != NULL) {
                ResultTemp[temp - 1]->next->prev = ResultTemp[temp - 1]->prev;
            }
            printf("�Ƿ����ɾ��(y/n)��\n");
            fflush(stdin);
            scanf("%c", &chose);
        } while (chose == 'Y' || chose == 'y');
    }
}

void ChangeInfo(int i) //�Խ�������޸�
{
    char chose;
    int temp, temp2, temp3;
    if (i == 0) {
        printf("��ѯ���Ϊ�գ�");
        sleep(2);
    } else {
        do {
            system("cls");
            printf("��ѯ�����\n");
            printf("%2s%20s\t%20s\t%3s\t%s\t%s\t%s\t%s\t%s\n", "���", "ѧ��", "����", "�Ա�", "����", "����", "��ѧ", "C����", "��");
            for (int j = 0; j < i && j < 10; j++) {
                printf("%02d%20s\t%20s\t%3s\t%02d\t%02d\t%02d\t%02d\t%d\n", j + 1, ResultTemp[j]->id, ResultTemp[j]->name, ResultTemp[j]->isMale ? "��" : "Ů", ResultTemp[j]->age, ResultTemp[j]->Chinese, ResultTemp[j]->Math, ResultTemp[j]->C, ResultTemp[j]->Sum);
            }
            printf("������Ҫ�޸ĵı�ţ�\n");
            scanf("%d", &temp);
            system("cls");
            printf("��ֵ��\nѧ�ţ�%s\n������%s\n%d���Ա�%s\n%d�����䣺%d\n%d�����ģ�%d\n%d����ѧ��%d\n%d��C���ԣ�%d\n", ResultTemp[temp - 1]->id, ResultTemp[temp - 1]->name, 1, ResultTemp[temp - 1]->isMale ? "��" : "Ů", 2, ResultTemp[temp - 1]->age, 3, ResultTemp[temp - 1]->Chinese, 4, ResultTemp[temp - 1]->Math, 5, ResultTemp[temp - 1]->C);
            printf("������Ҫ�޸ĵı�ţ�\n");
            scanf("%d", &temp2);
            printf("������Ҫ�޸ĵ�ֵ��\n");
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
            printf("�޸ĺ�\nѧ�ţ�%s\n������%s\n%d���Ա�%s\n%d�����䣺%d\n%d�����ģ�%d\n%d����ѧ��%d\n%d��C���ԣ�%d\n", ResultTemp[temp - 1]->id, ResultTemp[temp - 1]->name, 1, ResultTemp[temp - 1]->isMale ? "��" : "Ů", 2, ResultTemp[temp - 1]->age, 3, ResultTemp[temp - 1]->Chinese, 4, ResultTemp[temp - 1]->Math, 5, ResultTemp[temp - 1]->C);
            printf("�Ƿ�����޸�(y/n)��\n");
            fflush(stdin);
            scanf("%c", &chose);
        } while (chose == 'Y' || chose == 'y');
    }
}
