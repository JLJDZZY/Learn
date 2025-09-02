#include <stdio.h>
#include <windows.h>

int main() {

    SetConsoleOutputCP(CP_UTF8);

    //数据的集成化
    int number[]={0,3,4,5,6,7,8,8,9,9,};//直接默认给定一个数组，最后一个数留下一个逗号（类似于一个传统
    int number1[13]={[1]=2,[3]=4};//只有我们定义的数有数值，其他数值都为0
    int number2[13];

    //数组的初始化
    for (int i=0;i<13;i++) {
        number2[i]=0;
    };

    //scanf("请输入一个数字：%d",&i);


    for(int i=0;sizeof(number2)/sizeof(number2[0]);i++) {
        printf("数组元素：%d\t",number2[i]);
    }

    /*while (x!=10) {
        if (x>0) {
            printf("您输入的数字是：");
        }
        number[x]=x;
        x++;
    }*/
}