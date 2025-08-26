#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSIZE 20 //定义栈中的最大个数

//定义顺序栈
typedef struct {
    int data[MAXSIZE];//静态数组中存放栈中元素
    int top;//栈顶指针
}SqStack;

//定义共享栈
typedef struct {
    int data[MAXSIZE];//静态数组中存放栈中元素
    int top0;//0号栈顶指针
    int top1;//1号栈顶指针
}ShStack;

//初始化
void InitStack(SqStack *S) {
    S->top = -1;//初始化栈顶指针
    //0位置还没有存入元素，所以可以先指向-1
}

//新元素入栈
bool Push(SqStack *S, int x) {
    if (S->top == MAXSIZE - 1)//栈满报错
        return false;
    S->data[++S->top] = x;//指针先加一然后使用
    return true;

    /*S->top=S->top+1;//指针加一
    S->data[S->top] = x;//新元素入栈
    */
}

//出栈
bool Pop(SqStack *S, int *x) {
    if (S->top == -1)//栈空报错
        return false;
    *x = S->data[S->top--];//栈顶元素先出栈，指针减一
    return true;
}

//读栈顶元素
bool GetTop(SqStack *S, int *x) {
    if (S->top == -1)
        return false;
    *x = S->data[S->top];//栈顶元素赋给x
    return true;
    }

//栈的链式存储
typedef struct LinkNode {
    int data;
    struct LinkNode *next;
}LiStack;

//栈的入栈和出栈都在链表的表头进行
//参考单链表,插入和删除都是只能在表头的位置进行

// 在头结点之后插入一个元素e（入栈操作）
bool InsertPriorNode(LiStack *p, int e) {
    if (p == NULL) // 检查头结点是否有效
        return false;
    LiStack *s = (LiStack*)malloc(sizeof(LiStack)); // 创建新节点
    if (s == NULL) // 检查内存分配是否成功
        return false;
    s->data = e;         // 新节点存储元素e
    s->next = p->next;   // 新节点指向原头结点的下一个节点
    p->next = s;         // 头结点指向新节点
    return true;
}

//创建队列
typedef struct {
    int data[MAXSIZE];
    int front,rear;//队头指 针和队尾
    int size=0;//队列当前长度

}SqQueue;


//初始化队列
void InitQueue(SqQueue *Q) {
    Q->front =Q->rear;
}

//入队
bool EnQueue(SqQueue *Q, int x) {
    if ((Q->rear+1)%MAXSIZE == Q->front)//使用循环队列 解决“假溢出”的问题
        return false;//队满则报错
    Q->data[Q->rear]=x;//将x插入队尾
    Q->rear=(Q->rear+1)%MAXSIZE;//队尾指针加一取模，区域加入最后一个元素时，区域为0，返回队头


    return true;
}

//出队
bool DeQueue(SqQueue *Q, int *x) {
    if (Q->rear == Q->front)
        return false;//队空则直接报错
    *x=Q->data[Q->front];
    Q->front=(Q->front+1)%MAXSIZE;
    return true;
}

//获得对头元素的值，用x返回
bool GetFront(SqQueue *Q, int *x) {
    if (Q->front == Q->rear)
        return false;
    *x=Q->data[Q->front];
    return true;
}

//算队列元素
//(real+MAXSIZE-front)%MMAXSIZE