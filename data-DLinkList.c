#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct DNode {
    int data;
    struct DNode *prior,*next;//相比单链表多了一个前向指针
}DNode,*DLinkList;

//初始化双链表
bool InitDLinkList(DLinkList *L) {
    *L=(DNode*)malloc(sizeof(DNode));
    if (*L==NULL)//判断内存是否分配正确
        return false;
    (*L)->prior = NULL;//头结点，prior永远指向NULL
    (*L)->next = NULL;

    return true;

}

//在p结点之后插入s结点
bool InsertNextDNode(DNode *p, DNode *s) {
    if (p==NULL || s==NULL)
        return false;
    //修改指针注意顺序
    s->next=p->next;//将s插入倒p之后
    if (p->next!=NULL)
        p->next->prior=s;//p结点后一个结点的前向指针指向s
    s->prior=p;
    p->next=s;

    return true;
}

//删除p结点的后继结点
bool DeleteNextDNode(DNode *p) {//删除p的后继结点q
    if (p==NULL)
        return false;
    DNode *q=p->next;
    if (q==NULL)
        return false;
    p->next=q->next;//p后指针指向q的后指针
    if (q->next!=NULL)
        q->next->prior=p;
    free(q);
    return true;
}

// 前向遍历
void ForwardTraversal(DLinkList L) {
    printf("前向遍历: ");
    DNode *p = L->next;  // 跳过头节点
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 后向遍历
void BackwardTraversal(DLinkList L) {
    printf("后向遍历: ");
    DNode *p = L->next;
    // 先找到最后一个节点
    while (p != NULL && p->next != NULL) {
        p = p->next;
    }
    // 从后向前遍历
    while (p != NULL && p->prior != NULL) {  // 直到头节点停止
        printf("%d ", p->data);
        p = p->prior;
    }
    printf("\n");
}

// 释放链表内存
void FreeDLinkList(DLinkList L) {
    DNode *p = L;
    while (p != NULL) {
        DNode *temp = p;
        p = p->next;
        free(temp);
    }
}

int main() {
    DLinkList L;

    // 初始化双链表
    if (!InitDLinkList(&L)) {
        printf("初始化失败!\n");
        return 1;
    }

    // 遍历演示
    ForwardTraversal(L);
    BackwardTraversal(L);

    // 释放内存
    FreeDLinkList(L);

    return 0;
}