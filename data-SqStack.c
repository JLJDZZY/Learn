#include <stdio.h>
#include <stdbool.h>

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

