
//静态链表以next=-1作为结束的标志
//静态链表的插入，删除与动态链表相同
//静态链表没有单链表使用方便，但在不支持指针的语言中，适合用

#define MaxSize 10
typedef struct Node {
    int data;
    int next;  // 静态链表中next通常是数组下标
} SNode;

SNode SLinkList[MaxSize]; // 显式声明数组
