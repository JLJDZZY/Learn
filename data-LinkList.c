/*
#include <windows.h>
#include <stdlib.h>

struct LNode {
    int data;//定义单链表节点类型
    struct LNode *next;//指针指向下一个节点
};

//数据类型重命名
typedef struct LNode LNode;//重命名为LNode

//增加一个新的结点
//在内存里面申请一个结点需要的空间，并用指针p指向这个结点
LNode *p = (LNode *)malloc(sizeof(LNode));
*/

#include <stdbool.h>
#include <windows.h>


//将上面更加简洁化
typedef struct LNode {
    int data;
    struct LNode *next;
}LNode,*LinkList;//强调单链表用LinkList，强调用是一个结点用LNode*

//初始化一个空单链表（不带头结点）
bool InitListNULL(LinkList *L) {//这里指针同下
    *L=NULL;//这里注意c++引用是&，但是c语言应该用指针
    return true;
}

//初始化一个带头结点的单链表
bool InitList(LinkList *L) {
    *L=(LNode*)malloc(sizeof(LNode));//创建头结点
    if(*L==NULL)//如果malloc内存分配失败会返回NULL，
        return false;//内存不足，返回失败
    //头结点之后暂时还没有结点
    (*L)->next = NULL;//*的优先级不如->,所以要带()
    return true;
}

//判断一个带头结点的单链表是否为空
bool empty(LinkList *L) {
    if(*L==NULL)
        return true;
    return false;
}
