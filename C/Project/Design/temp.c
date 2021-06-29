// Stu* Sort(Stu* FatherNode, int flag) //排序并输出
// {
//     int Monotonous = 1;
//     Stu *TailNode = FatherNode, *ActionNode = FatherNode;
//     while (1) {
//         if (flag ? ActionNode->next->Sum > ActionNode->Sum : ActionNode->next->Sum < ActionNode->Sum) {
//             Monotonous = 0;
//         }
//         if (TailNode->next == NULL || TailNode->next->next == NULL) {
//             //断链
//             if (ActionNode->prev != NULL) {
//                 ActionNode->prev->next = NULL;
//                 ActionNode->prev = NULL;
//             }
//             //递归调用
//             if (!Monotonous) {
//                 if (FatherNode == ActionNode) {
//                     return;
//                 }
//                 Sort(FatherNode, flag);
//                 Sort(ActionNode, flag);
//             }
//             //连接
//             FatherNode->prev = ActionNode;
//             if (TailNode->next == NULL) {
//                 TailNode->next = FatherNode;
//                 FatherNode->prev = TailNode;
//             } else {
//                 TailNode->next->next = FatherNode;
//                 FatherNode->prev = TailNode->next;
//             }
//         } else {
//             //移动指针
//             ActionNode = ActionNode->next;
//             TailNode = TailNode->next->next;
//         }
//     }
//     return FatherNode;
// }