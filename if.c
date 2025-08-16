#include <stdio.h>

/*int main() {           //找零钱
    int price=0;//初始化
    int bill=0;
    int change=0;


    printf("please input price \n");
    scanf("%d",&price);

    printf("please input bill \n");
    scanf("%d",&bill);

    if (bill>=price) {          //判断金额和单价的关系，关系运算符优先级比算数运算符低符高，关系运算符==（等于），和！=（不相等）优先级比其他关系运算符低
        change=bill-price;
        printf("change=%d\n",change);
    }
    else{
        printf("bill is't enough\n");
    }
    return 0;

}*/

int main() {
    int a=0;
    int b=0;
    int c=20;

    printf("please input a \n");
    scanf("%d",&a);

    printf("please input b \n");
    scanf("%d",&b);

    /*if (a==c) {   //if嵌套的嵌套，前面的if条件成立，则执行后面的if判断
        if (b<20) {
            printf("internal 1 success\n");

        }
        else {           //if嵌套内部的else
            printf("internal 2 success\n");
        }

    }else {             //if嵌套的外部else
        if (b<20) {
            printf("out range 1 success\n");

        }else {
            printf("out range 2 success\n");
        }
    }
}*/

if (a==c) {   //由上面的嵌套转化成级联的if-else if
    if (b<20)
        printf("internal 1 success\n");
    else if (b==20)           //if嵌套内部的else
        printf("internal 2 success\n");
    else if (b==30)    //这里就是级联的if else-if，主要结果是能够批量化的对齐else-if
        printf("out range 1 success\n");
    else if (b>40)
        printf("out range 2 success\n");
    }
}

