#include <stdio.h>

struct node {
    int Data;
    int Next;
};

int main()
{
    int head, N;
    scanf("%d %d", &head, &N);

    struct node readIn[100000];
    int list[N];
    int list_changed[N];

    int address;
    int data;
    int next;
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &address, &data, &next);
        readIn[address].Data = data;
        readIn[address].Next = next;
    }

    int k = 0;
    int len = 0;
    while (head != -1) {
        list[k] = head;
        head = readIn[head].Next;
        k++;
        len++;
    }

    k = 0;
    int ind = 0;
    int end = len / 2;
    while (1) {
        list_changed[k] = list[len - 1 - ind];
        k++;
        if (len % 2 != 0 && ind == end)
            break;
        list_changed[k] = list[ind];
        k++;
        ind++;
        if (len % 2 == 0 && ind == end)
            break;
    }

    for (int i = 0; i < len; i++) {
        if (i == len - 1)
            printf("%05d %d %d\n", list_changed[i], readIn[list_changed[i]].Data, -1);
        else
            printf("%05d %d %05d\n", list_changed[i], readIn[list_changed[i]].Data, list_changed[i + 1]);
    }

    return 0;
}