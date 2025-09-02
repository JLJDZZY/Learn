#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>


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
//(real+MAXSIZE-front)%MAXSIZE

//通过栈来实现中缀表达式转后缀表达式

#define  MAX_SIZE 20
// 栈结构
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// 初始化栈
void initStack(Stack *s) {
    s->top = -1;
}

// 判断栈是否为空
int isEmpty(Stack *s) {
    return s->top == -1;
}

// 判断栈是否已满
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// 入栈
void push(Stack *s, char c) {
    if (isFull(s)) {
        printf("栈已满，无法入栈\n");
        return;
    }
    s->data[++s->top] = c;
}

// 出栈
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("栈为空，无法出栈\n");
        return '\0';
    }
    return s->data[s->top--];
}

// 获取栈顶元素
char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->data[s->top];
}

// 判断字符是否为运算符
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// 获取运算符优先级
int getPriority(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// 中缀表达式转后缀表达式
void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    initStack(&s);
    int i,j = 0;
    char c;

    for (i=0;infix[i]!='\0';i++) {
        c = infix[i];

        // 如果是操作数，直接添加到后缀表达式
        if (isalnum(c)) {
            postfix[j++] = c;
        }
        // 如果是左括号，压入栈
        else if (c == '(') {
            push(&s, c);
        }
        // 如果是右括号，弹出栈顶元素直到遇到左括号
        else if (c == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            if (!isEmpty(&s) && peek(&s) != '(') {
                printf("表达式错误：括号不匹配\n");
                return;
            } else {
                pop(&s); // 弹出左括号
            }
        }
        // 如果是运算符
        else if (isOperator(c)) {
            // 处理负号（一元运算符）
            if (c == '-' && (i == 0 || infix[i-1] == '(' || isOperator(infix[i-1]))) {
                // 这里可以特殊处理负号，但为了简单起见，我们假设所有操作数都是正数
                postfix[j++] = '0'; // 用0代替负数的操作数
                continue;
            }

            while (!isEmpty(&s) && getPriority(peek(&s)) >= getPriority(c)) {
                postfix[j++] = pop(&s);
            }
            push(&s, c);
        }
        // 忽略空格
        else if (c == ' ') {
            continue;
        }
        // 其他字符视为错误
        else {
            printf("错误：无效字符 '%c'\n", c);
            return;
        }
    }

    // 弹出栈中所有剩余运算符
    while (!isEmpty(&s)) {
        if (peek(&s) == '(') {
            printf("表达式错误：括号不匹配\n");
            return;
        }
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0'; // 添加字符串结束符
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("请输入中缀表达式：\n");
    fgets(infix, MAX_SIZE, stdin);

    // 移除换行符
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);

    printf("中缀表达式: %s\n", infix);
    printf("后缀表达式(先出栈为右操作数): %s\n", postfix);

    return 0;
}