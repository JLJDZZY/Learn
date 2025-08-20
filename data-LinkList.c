/*
#include <windows.h>
#include <stdlib.h>

struct LNode {
    int data;//定义单链表节点类型
    struct LNode *next;//指针指向下一个节点
};

//数据类型重命名
typedef structLNode  LNode;//重命名为LNode

//增加一个新的结点
//在内存里面申请一个结点需要的空间，并用指针p指向这个结点
LNode *p = (LNode *)malloc(sizeof(LNode));
*/

#include <stdbool.h>
#include <stdio.h>
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

    LNode *p=*L;//将指针p指向头结点
        int j=0;//用来显示当前p指向的结点

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

    LNode *p=*L;//将指针p指向头结点
    int j=1;//用来显示当前p指向的结点

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


//按位查找(带头结点)
LNode * GetElem(LinkList *L,int i) {
    if (i<1)//先判断i是否为0，为0直接指向头结点
        return NULL;
    LNode *p=*L;//p指针指向头结点
    int j=0;
    while(p!=NULL && j<i) {
        p=p->next;
        j++;
    }
  return p;
}

//在位置i之前插入一个元素e（带头结点）
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

    /*LNode *p;
    int j=0;
    p=*L;
    while(p!=NULL && j<i-1) {//循环找到第i-1个结点
        p=p->next;
        j++;
    }*/

    //通过调用实现找到第i-1个结点
    LNode *p=GetElem(L,i-1);

    if(p==NULL)
        return false;
    if (p->next==NULL)//第i-1个结点之后没有结点
        return false;

    LNode *s=p->next;//用s指向被删除的结点
    *e=s->data;//用e返回元素值
    p->next=s->next;//将*s从结点链中“断开”，并使p指向s后面的结点
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

//按值查找
LNode * LocateElem(LinkList *L,int e) {
    LNode *p=GetElem(L,1);//从第一个结点开始查找数据域为e的结点
    while(p!=NULL && p->data!=e)//！=表示不等于
        p=p->next;
        return p;//找到后返回该结点指针，否则返回NULL
}

//尾插法建立单链表
LinkList create1() {

    SetConsoleOutputCP(CP_UTF8);
    int x;
    LinkList L=(LinkList)malloc(sizeof(LNode));//创建头结点
    L->next=NULL;//初始化为空链表
    LNode *s,*r=L;

    printf("输入一个元素:\n");
    scanf("%d",&x);

    while(x!=200) {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        printf("请输入下一个元素：");
        scanf("%d",&x);
    }
    r->next=NULL;
    return L;
}

//头插法建立单链表
LinkList create2() {
    //头插法可以用来实现链表的逆置
    SetConsoleCP(CP_UTF8);
    LNode *s;
    int x;
    LinkList L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;

    printf("请输入一个元素：");
    scanf("%d",&x);

    while(x!=200) {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        printf("请输入下一个元素：");
        scanf("%d",&x);
    }
    return L;
}

// 输出链表内容(带头结点)
void printList(LinkList L) {
    LNode* p = L->next; // 跳过头结点
    if (p == NULL) {
        printf("链表为空！\n");
        return;
    }
    printf("链表内容: ");
    while (p != NULL) {
        printf("%d", p->data);
        if (p->next != NULL) {
            printf(" -> ");
        }
        p = p->next;
    }
    printf("\n");
}

// 释放链表内存
void freeList(LinkList L) {
    LNode* p = L;
    LNode* temp;
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
}

int main() {

    SetConsoleOutputCP(CP_UTF8);

    printf("========== 链表创建与输出程序 ==========\n");

    LinkList L = create1(); // 创建链表
    printList(L); // 输出链表内容
    freeList(L);// 释放链表内存
    printf("程序结束，按任意键退出...\n");
    getchar(); // 清除输入缓冲区
    getchar(); // 等待用户按键
    return 0;
}






