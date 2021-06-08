#include <stdio.h>
#include <stdlib.h>
typedef struct nodeList {
    struct nodeList* next;
    int data;
} * node, Node;

node createList()
{
    node head;
    node pthis, pbefore;
    node ptail = (node)malloc(sizeof(Node));
    int inputdata, numNode = 0;
    scanf("%d", &inputdata);
    numNode++;
    if (inputdata == -1) {
        return ptail;
    }
    while (inputdata != -1) {
        pthis = (node)malloc(sizeof(Node));
        pthis->data = inputdata;
        if (numNode == 1) {
            head = pthis;
            pbefore = pthis;
        } else {
            pbefore->next = pthis;
            pbefore = pthis;
        }
        scanf("%d", &inputdata);
        numNode++;
    }

    pbefore->next = ptail;
    ptail->data = -1;
    ptail->next = NULL;
    return head;
}

int main()
{
    node a = createList();
    node b = createList();
    node i, j;
    if (a->next == NULL && b->next == NULL) {
        printf("NULL");
        return 0;
    }
    for (i = a, j = b; i->next != NULL && j->next != NULL;) {
        if (i->data <= j->data) {
            printf("%d", i->data);
            i = i->next;
        } else {
            printf("%d", j->data);
            j = j->next;
        }
        printf(" ");
    }
    if (j->next != NULL) {
        while (j->next) {
            printf("%d", j->data);
            j = j->next;
            if (j->next != NULL) {
                printf(" ");
            }
        }
    } else {
        while (i->next) {
            printf("%d", i->data);
            i = i->next;
            if (i->next != NULL) {
                printf(" ");
            }
        }
    }
    return 0;
}