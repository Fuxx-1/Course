Stu* InsertNode(Stu* FatherNode, Stu* NewNode) //����ڵ�
{
    Stu* ActionNode = FatherNode;
    while (ActionNode->next != NULL) {
        ActionNode = ActionNode->next;
    }
    ActionNode->next = NewNode;
    NewNode->prev = ActionNode;
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
    fflush(stdin);
    printf("������ѧ�ţ�20�������ڣ���\n");
    scanf("%s", &tempNode.id);
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
