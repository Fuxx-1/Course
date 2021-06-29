// 防止graphics.h被重复引用
#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char id[21]; //学号(编号为1)
    char name[41]; //姓名(编号为2)
    bool isMale; //性别，true为男，false为女(编号为3)
    int age; //年龄(编号为4)
    int Chinese; //语文成绩(编号为5)
    int Math; //数学成绩(编号为6)
    int C; //C语言成绩(编号为7)
    int Sum; //总分(编号为8)
    struct Student* prev; //前一个节点
    struct Student* next; //后一个节点
} Stu;

//定义全局临时变量
Stu* ResultTemp[10];
Stu tempNode = { "", "", 0, 0, 0, 0, 0, 0 };

#endif