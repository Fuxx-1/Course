#include <stdio.h>
typedef struct Node_Val {
    int val;
    struct Node_Val* next;
    struct Node_Val* prev;
} Node;
//定义结构体

typedef struct Node_Head {
    int n;
    Node* HeadNode;
} HeadNode;
//定义头节点结构体

Node* PrintList(Node* HeadNode, int flag); //输出List，1为正序，0为倒序
void InsertNodeByPosNum(HeadNode* HeadNode, int PosData, int PosNum); //插入节点
void DeleteNodeByPosNum(HeadNode* HeadNode, int PosNum); //删除节点

int main(int argc, char const* argv[])
{
    HeadNode HeadNode1 = { 0, NULL };
    int temp = 0, n = 0;
    while (1) {
        scanf("%d", &temp);
        if (temp == -1) {
            break;
        }
        if ((n++) % 2) {
            InsertNodeByPosNum(&HeadNode1, temp, HeadNode1.n);
        } else {
            InsertNodeByPosNum(&HeadNode1, temp, 0);
        }
    }
    if (HeadNode1.n > 0) {
        PrintList(HeadNode1.HeadNode, 1);
        printf("\n");
        PrintList(HeadNode1.HeadNode, 0);
    }

    return 0;
}

Node* PrintList(Node* HeadNode, int flag)
{ //输出List
    //识别flag
    if (flag) {
        //正序
        printf("%d", HeadNode->val);
        if (HeadNode->next != NULL) {
            printf(" ");
            PrintList(HeadNode->next, 1);
        }
    } else {
        if (HeadNode->next != NULL) {
            PrintList(HeadNode->next, 0);
            printf(" ");
        }
        printf("%d", HeadNode->val);
    }
}

void InsertNodeByPosNum(HeadNode* HeadNode, int PosData, int PosNum)
{
    if (PosNum > HeadNode->n || PosNum < 0) { //处理违例
        return;
    }
    //创建节点
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->val = PosData;
    NewNode->prev = NULL;
    NewNode->next = NULL;
    //处理HeadNode为空状况或PosNum为0的情况
    if (HeadNode->HeadNode == NULL) {
        HeadNode->HeadNode = NewNode;
        HeadNode->n++;
        return;
    }
    if (PosNum == 0) {
        NewNode->next = HeadNode->HeadNode;
        HeadNode->HeadNode->prev = NewNode;
        HeadNode->HeadNode = NewNode;
        HeadNode->n++;
        return;
    }
    //找到操作位置
    Node* PosNode = HeadNode->HeadNode;
    while (PosNum != 1) {
        PosNode = PosNode->next;
        PosNum--;
    }
    //插入节点
    NewNode->next = PosNode->next;
    NewNode->prev = PosNode;
    if (PosNode->next != NULL) {
        PosNode->next->prev = NewNode;
    }
    PosNode->next = NewNode;
    HeadNode->n++;
}

void DeleteNodeByPosNum(HeadNode* HeadNode, int PosNum)
{
    if (PosNum > HeadNode->n || PosNum <= 0) { //处理违例
        return;
    }
    //找到操作位置
    Node* PosNode = HeadNode->HeadNode;
    while (PosNum != 1) {
        PosNode = PosNode->next;
        PosNum--;
    }
    //删除节点
    if (PosNode->next != NULL) {
        PosNode->next->prev = PosNode->prev;
    }
    if (PosNode->prev != NULL) {
        PosNode->prev->next = PosNode->next;
    }
    free(PosNode);
    HeadNode->n--;
    return;
}