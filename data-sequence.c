/*#define MaxSize 10 //定义最大长度

typedef struct {
    int data[MaxSize];//用静态的“数 组”存放数据元素
    //顺序表的表长确定后，就无法更改（存储空间是静态的）
        int Length;//顺序  表的当前长度

}Sqlist;//顺序表的类型定义

void Initlist(SqList &L){
    for(int i=0;i<MaxSize;i++)
        L.data[i]=0;//所有元素设置为默认初始值
    //如果不设置默认值，可能会有各种“”脏数据”
    L.Length=0;//顺序表初始长度为0
    //C语言编译器有一部分会设置初始值，但是换个编译器就可能不会设置

}
int main() {
    Sqlist L;//
    Initlist(L);//

    return 0;

}*/


//上面是静态分配，下面初始化使用动态分配

#define InitSize 10
#include <stdlib.h>//mallo和free包含在这个里面
#include <stdbool.h>//使用布尔型
#include <stdio.h>
#include <windows.h>

typedef struct {
    int *data;//指示动态分配数组的指针
    int Maxsize;//顺序表的最大容量
    int length;//顺序表的当前长度
}SeqList;

void initList(SeqList *L) {
    //函数申请一片连续的内存空间
    L->data = (int *)malloc(InitSize*sizeof(int));
    L->Maxsize = InitSize;//
    L->length = 0;//
}

//增加动态空间的长度
void increaseList(SeqList *L,int len) {
    int *p = L->data;//p指针和data指向同一个位置
    L->data=(int *)malloc((L->Maxsize+len)*sizeof(int));//data指针指向新申请的内存空间
    for(int i=0;i<L->length;i++) { //数据复制到新区域
        L->data[i] = p[i];
    }
    L->Maxsize=L->Maxsize+len;//顺序表最大长度增加len
    free(p);//p指针已经指向了原来的data指针的位置，新data也已经重新指向了一个新申请的空间，所以free(p)会释放原来data占用的内存空间
}

//顺序表插入一个元素
bool ListInsert(SeqList *L,int i,int e) {//在L的 位序i处插入元素e
    //先判断i是否“合法”
    if (L->length>=L->Maxsize)
        return false;
    if (i<1||i>L->length+1)
        return false;

    //循环先获取最后length的长度，判断j和插入位序i的关系，符合条件
    //执行最后的位置往后挪一位，并把j—1循环，直到不满足条件，提出循环
        for (int j = L->length; j > i; j--)
            L->data[j] = L->data[j - 1];

    L->data[i - 1] = e;//实际的位置是从0开始的，插入到3的位置，则应插入实际位置的2
    L->length++;
    return true;
}

//顺序表删除一个元素
bool ListDelete(SeqList *L,int i,int *e) {//删除L在位序i的元素e
    //注意这里要用指针*来引用e,如果不用*来进行传递,下面main函数使用e,会输出-1的默认值,而不是我们要的值

    //先判断i是否“合法
    if (i<1||i>L->length)
        return false;

    *e=L->data[i - 1];//通过指针*来使e指向顺序表删除对应值的数

    //循环先获取最后length的长度，令j等于插入位序i的，符合条件
    //执行最后的位置往前挪一位，并把j+1循环，直到不满足条件，提出循环
    for (int j =i; j<L->length;j++)
        L->data[j-1] = L->data[j];

    L->length--;
    return true;
}

//顺序表按位查找
int GetElem(SeqList L, int i) { //注意前面查找的元素类型为int，则每四个一个单位
        return L.data[i-1];//使用动态分配，所以输入i为1时，查找动态存储中的第0段
    }

//顺序表L中查找第一个元素值等于e的元素，并返回位序
int LocateElem(SeqList L, int e) {
    for(int i=0;i<L.length;i++)
        if (L.data[i] == e)//依次判断该元素的值是否和我们给的元素是否相等
            return i+1;//在存储中，因为从0开始，所以返回的位序应+1
    return 0;//没有查找到，退出循环

}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SeqList L;//声明一个顺序表
    initList(&L);//初始化顺序表

    //动态增加顺序表长度
    //increaseList(&L,5);

    //顺序表插入一个元素
    ListInsert(&L,1,1);
    ListInsert(&L,2,2);
    ListInsert(&L,3,3);
    ListInsert(&L,4,4);
    ListInsert(&L,5,5);
    ListInsert(&L,6,6);
    ListInsert(&L,7,7);
    ListInsert(&L,8,8);


    /*//顺序表删除一个元素
    int e=-1;
    if (ListDelete(&L,3,&e))//前面调用Listdelite成功会返回一个true,进而执行if
        //main函数这里通过&传递前面的*e指向的值
        printf("%d\n",e);
    else
        printf("位序i不合法删除失败\n");
        */

    printf("顺序表位序i的值为%d\n",GetElem(L,2));

    printf("顺序表按值查找的位序为%d\n",LocateElem(L,5));

    return 0;
}