#include <stdio.h>

int main() {          //循环判断位数
    int a=0;
    int n=0;

    printf("please input a number:");
     scanf("%d",&a);

    /*while (a>0) {           //判断a>0时，执行循环（判断这里和if一样），判断到a＜0后，循环结束，执行下面的printf
        n++;
        a/=10;
    }*///整个while循环里面的{}称为循环体，循环体内要有改变循环值的语句，要不然会一直循环，出不来

    /*n++;
    a/=10;
    while (a>0) {    //上面的while没有办法判断0，走上面的while，会直接不执行循环，进而位数显示为0
        n++;
        a/=1;
    }*/

    do {
        a/=10;
        n++;
    }while (a>0);


    printf("Your input is %d units",n);

}
