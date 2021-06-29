#include "Default.h"

int Menu(); //��ӡ�˵�����ȡ����������Ϣ
int SearchNode(Stu* FatherNode); //��ѯ�ڵ�
void DeleteNode(int i); //�Խ�������жϲ�ɾ��
void ChangeInfo(int i); //�Խ�������޸�
Stu* SortInfo(Stu* FatherNode); //����
int CompareTo(Stu* Node1, Stu* Node2, int flag1, int flag2); //�ڵ�Ƚ�
Stu* InsertNode(Stu* FatherNode, Stu* NewNode); //����ڵ�
Stu* CreateNode(); //�����ڵ�
Stu* ReadInfoFromFile(); //���ļ��ж�ȡ��Ϣ
void AddNewInfo(Stu* FatherNode); //����Ļ��ȡ����
void WriteFile(Stu* FatherNode); //д�ļ�
void Print(Stu* FatherNode); //�������
void PrintResult(int i); //��ӡ���

int main(int argc, char const* argv[])
{
    //���ļ��ж�ȡ��Ϣ
    Stu* FatherNode = ReadInfoFromFile();
    //�ñ������ں���������Ϣ
    int CallInformation = 0;
    while (CallInformation = Menu()) {
        system("cls"); //��������windows
        switch (CallInformation) {
        case 0:
            printf("�ر�ϵͳ��\n");
            sleep(1);
            break;
        case 1:
            //����ѧ����Ϣ
            AddNewInfo(FatherNode);
            break;
        case 2:
            //��ѯѧ����Ϣ������ʹ��������ѧ�Ų�ѯ��
            PrintResult(SearchNode(FatherNode));
            break;
        case 3:
            //�޸�ѧ����Ϣ����������ѧ�ţ�
            ChangeInfo(SearchNode(FatherNode));
            break;
        case 4:
            //ɾ��ѧ����Ϣ
            DeleteNode(SearchNode(FatherNode));
            break;
        case 5:
            //�������ѧ����Ϣ
            FatherNode = SortInfo(FatherNode);
            break;
        case 6:
            //���ѧ����Ϣ
            Print(FatherNode);
            break;
        default:
            system("color F4");
            printf("\n\n\t��������ȷ�����\n");
            sleep(2);
            system("color 0E");
            break;
        }
    }
    WriteFile(FatherNode);
    return 0;
}

int Menu() //��ӡ�˵�����ȡ����������Ϣ
{
    int temp = 8;
    system("cls");
    system("color 0A");
    printf("\n��ӭ����ѧ���ɼ�����ϵͳ��\n\n");
    printf("===============================================\n");
    printf("  0���˳�                                      \n");
    printf("  1������ѧ����Ϣ                               \n");
    printf("  2����ѯѧ����Ϣ������ʹ��������ѧ�Ų�ѯ��        \n");
    printf("  3���޸�ѧ����Ϣ����������ѧ�ţ�                \n");
    printf("  4��ɾ��ѧ����Ϣ���Ȳ�ѯ��                      \n");
    printf("  5���������ѧ����Ϣ                           \n");
    printf("  6�����ѧ����Ϣ                              \n");
    printf("  ��������Ҫ���ܵı�ţ�ֱ�ӹر�ϵͳ����������  \n");
    printf("===============================================\n");
    // setbuf(stdin, NULL);
    fflush(stdin);
    scanf("%d", &temp);
    system("color 0E");
    return temp;
}

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
            //�ͷſռ�
            free(ResultTemp[temp - 1]);
            //ѭ������
            printf("�Ƿ����ɾ��(y/n)��\n");
            //���StdIn
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

Stu* SortInfo(Stu* FatherNode) //����
{
    int temp, n = 1, flag, temp1, temp2;
    Stu *TempNode = FatherNode, *TempNode2 = FatherNode, *ActionNode = FatherNode, *MoveNode;
    while (TempNode->next != NULL) {
        TempNode = TempNode->next;
        n++;
    }
    printf("===============================================\n");
    printf(" ������Ҫ���������ѡ��                          \n");
    printf("  1��ѧ��                                      \n");
    printf("  2������                                       \n");
    printf("  3����ѧ                                       \n");
    printf("  4��C����                                      \n");
    printf("  5���ܳɼ�                                     \n");
    printf("  ��������Ҫ���ܵı�ţ�ֱ�ӹر�ϵͳ����������   \n");
    printf("===============================================\n");
    scanf("%d", &temp1);
    printf("===============================================\n");
    printf("  0������                                       \n");
    printf("  1������                                       \n");
    printf("  ��������Ҫ���ܵı�ţ�ֱ�ӹر�ϵͳ����������   \n");
    printf("===============================================\n");
    scanf("%d", &temp2);
    /* �ҵ���ֵ */
    TempNode = FatherNode;
    TempNode2 = FatherNode;
    while (TempNode2->next != NULL) {
        if (CompareTo(TempNode, TempNode2->next, temp1, temp2) < 0) {
            TempNode = TempNode2->next;
        }
        TempNode2 = TempNode2->next;
    }
    /* ��ֵ���� */
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
    /* ����˳�� */
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

int CompareTo(Stu* Node1, Stu* Node2, int flag1, int flag2) //�ڵ�Ƚ�
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
        printf("\n\n\t��������ȷ�����\n");
        sleep(2);
        system("color 0E");
        break;
    }
}

Stu* InsertNode(Stu* FatherNode, Stu* NewNode) //����ڵ�
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

Stu* CreateNode() //�����ڵ�
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

Stu* ReadInfoFromFile() //���ļ��ж�ȡ��Ϣ
{
    //����
    char ABS[1001];
    FILE* File = NULL;
    //���ļ�
    getcwd(ABS, 1000);
    File = fopen(strcat(ABS, "\\Information"), "r");
    fscanf(File, "%s%s%d%d%d%d%d%d", &tempNode.id, &tempNode.name, &tempNode.isMale, &tempNode.age, &tempNode.Chinese, &tempNode.Math, &tempNode.C, &tempNode.Sum);
    //���常�ڵ�
    Stu* FatherNode = CreateNode();
    while (fscanf(File, "%s%s%d%d%d%d%d%d", &tempNode.id, &tempNode.name, &tempNode.isMale, &tempNode.age, &tempNode.Chinese, &tempNode.Math, &tempNode.C, &tempNode.Sum) != EOF) {
        InsertNode(FatherNode, CreateNode());
    }
    return FatherNode;
}

void AddNewInfo(Stu* FatherNode) //����Ļ��ȡ����
{
    Stu* ActionNode = FatherNode;
    fflush(stdin);
    printf("������ѧ�ţ�20�������ڣ���\n");
    scanf("%s", &tempNode.id);
    while (ActionNode->next != NULL) {
        if (ActionNode->id == tempNode.id) {
            system("color F4");
            printf("\n\n\t�����벻�ظ���ѧ��\n");
            sleep(2);
            system("color 0E");
            return;
        } else {
            ActionNode = ActionNode->next;
        }
    }
    printf("������������20���ڣ���\n");
    scanf("%s", &tempNode.name);
    printf("�������Ա���Ϊ1��ŮΪ0����\n");
    scanf("%d", &tempNode.isMale);
    printf("���������䣺\n");
    scanf("%d", &tempNode.age);
    printf("���������ĳɼ���<100����\n");
    scanf("%d", &tempNode.Chinese);
    printf("��������ѧ�ɼ���<100����\n");
    scanf("%d", &tempNode.Math);
    printf("������C���Գɼ���<100����\n");
    scanf("%d", &tempNode.C);
    if (tempNode.age >= 0 && tempNode.C <= 100 && tempNode.C >= 100 && tempNode.Chinese <= 100 && tempNode.Chinese >= 100 && tempNode.Math <= 100 && tempNode.Math >= 100 && (tempNode.isMale == 0 || tempNode.isMale == 1) && strlen(tempNode.name) > 0 && strlen(tempNode.id) > 0) {
        printf("������������������");
    } else {
        InsertNode(FatherNode, CreateNode());
    }
}

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