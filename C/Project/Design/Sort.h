Stu* SortInfo(Stu* FatherNode) //排序并输出
{
    int temp, n = 1;
    Stu *TempNode = FatherNode, *ActionNode = FatherNode, *PrevNode = FatherNode, *TailNode = FatherNode;
    while (TempNode->next != NULL) {
        TempNode = TempNode->next;
        n++;
    }
    while (TailNode->next != NULL) {
        TailNode = TailNode->next;
    }
    printf("===============================================\n");
    printf("  1、升序                                       \n");
    printf("  2、降序                                       \n");
    printf("  请输入需要功能的编号，直接关闭系统可能损坏数据   \n");
    printf("===============================================\n");
    scanf("%d", &temp);
    for (int i = 0; i < n; i++) {
        ActionNode = PrevNode;
        for (;;) {
            if (temp == 1 ? ActionNode->Sum > ActionNode->next->Sum : ActionNode->Sum < ActionNode->next->Sum) {
                SwapNode(ActionNode, ActionNode->next);
                if (PrevNode->prev != NULL) {
                    PrevNode = PrevNode->prev;
                }
                if (TailNode->next != NULL) {
                    TailNode = TailNode->next;
                }
            }
            if (ActionNode != TailNode) {
                ActionNode = ActionNode->next;
            }
            if (ActionNode->next == NULL) {
                break;
            }
        }
    }
    return PrevNode;
}

void SwapNode(Stu* Node1, Stu* Node2) //交换节点
{
    Stu* temp;
    if (Node1->prev != NULL) {
        Node1->prev->next = Node2;
    }
    if (Node2->prev != NULL) {
        Node2->prev->next = Node1;
    }
    temp = Node1->prev;
    Node1->prev = Node2->prev;
    Node2->prev = temp;
    temp = Node1->next;
    Node1->next = Node2->next;
    Node2->next = temp;
    if (Node1->next != NULL) {
        Node1->next->prev = Node1;
    }
    if (Node2->next != NULL) {
        Node2->next->prev = Node2;
    }
}