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
    fflush(stdin);
    printf("请输入学号（20个数字内）：\n");
    scanf("%s", &tempNode.id);
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
