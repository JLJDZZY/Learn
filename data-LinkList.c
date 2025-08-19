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

//带头结点的插入
bool ListInsert(LinkList *L, int i, int e) { //在位序i插入元素e
    if (i<1)
        return false;

    LNode *p;//将指针p指向当前扫描到的结点
        int j=0;//用来显示当前p指向的结点
        p=*L;//L指向头结点，头结点是0结点

        while(p!=NULL && j<i-1) { //循环找到i-1个结点
            p=p->next;// p等于原来p所指向的结点
            j++;
        }

        if(p==NULL) //判断i值
            return false;

        LNode *s=(LNode*)malloc(sizeof(LNode));//申请一个新的结点空间

        s->data=e;//让s值等于e

        //注意下面两个指针不能颠倒，否则会指向自己，
        s->next=p->next;//让s的结点指向原来p结点指向的位置
        p->next=s;//p结点指向新插入的s

        return true;
}

//不带头结点的插入
bool ListInsertNULL(LinkList *L, int i, int e) { //在位序i插入元素e
    if (i<1)
        return false;

    if (i==1) {//插入1个结点位置需要单独处理
        LNode *s=(LNode*)malloc(sizeof(LNode));
        s->data=e;
        s->next=*L;
        *L=s;//头指针指向新结点
        return true;
    }

    LNode *p;//将指针p指向当前扫描到的结点
    int j=1;//用来显示当前p指向的结点
    p=*L;//L指向头结点，头结点是0结点

    while(p!=NULL && j<i-1) { //循环找到i-1个结点
        p=p->next;// p等于原来p所指向的结点
        j++;
    }

    if(p==NULL) //判断i值
        return false;

    LNode *s=(LNode*)malloc(sizeof(LNode));//申请一个新的结点空间

    s->data=e;//让s的值等于e

    //注意下面两个指针不能颠倒，否则会指向自己，
    s->next=p->next;//让s的结点指向原来p结点指向的位置
    p->next=s;//p结点指向新插入的s

    return true;
}

//不带头结点的插入
bool InsertNEXTNode(LNode *p,int e) { //p结点之后插入e
    if(p==NULL) //判断p值
        return false;

    LNode *s=(LNode*)malloc(sizeof(LNode));//申请一个新的结点空间

    if (s==NULL)//判断内存是否分配失败，分配失败会返回NULL
        return false;

    s->data=e;//让s的值等于e

    //注意下面两个指针不能颠倒，否则会指向自己，
    s->next=p->next;//让s的结点指向原来p结点指向的位置
    p->next=s;//p结点指向新插入的s

    return true;
}

 //通过调用上面这个函数来达成在位置i插入e
/*
bool ListInsert(LinkList *L, int i, int e) { //在位序i插入元素e
    if (i<1)
        return false;

    LNode *p;//将指针p指向当前扫描到的结点
    int j=0;//用来显示当前p指向的结点
    p=*L;//L指向头结点，头结点是0结点

    while(p!=NULL && j<i-1) { //循环找到i-1个结点
        p=p->next;// p等于原来p所指向的结点
        j++;
    }
    return  InsertNEXTNode(p,e);
}*/

//在位置i之前插入一个元素e
bool InsertPriorNode(LNode *p,int e) {
    if(p==NULL)
            return false;
    LNode *s=(LNode*)malloc(sizeof(LNode));

    if (s==NULL)
        return false;
    s->data=p->data;
    s->next=p->next;//新节点s指向原来p结点的指向
    p->next=s;//p结点指向新的s
    p->data=e;//让p等于我们要插入的元素e

    return true;
}

//带头结点的删除
bool ListDelete(LinkList *L, int i,int *e) {
    if (i<1)
        return false;
    LNode *p;
    int j=0;
    p=*L;
    while(p!=NULL && j<i-1) {//循环找到第i-1个结点
        p=p->next;
        j++;
    }

    if(p==NULL)
        return false;
    if (p->next==NULL)//第i-1个结点之后没有结点
        return false;

    LNode *s=p->next;//用s指向被删除的结点
    *e=s->data;//用e返回元素值
    p->next=s->next;//将*q从结点链中“断开”
    free(s);//释放s
    return true;

}

//删除指定的结点p
bool DeleteNode(LNode *p) {
    if(p==NULL)
        return false;
    LNode *s=p->next;//s指向*p的后继结点
    p->data=p->next->data;//(p->next->data)把后继结点数据复制给p
    p->next=s->next;//将*q结点从链中“断开”
    free(p);
    return true;
}




