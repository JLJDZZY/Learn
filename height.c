#include <stdio.h>
int main() {
    //int foot;//
    //int inch;//int 类型只能表达整数
     float foot;//double类型是双精度浮点，float是单精度浮点
     float inch;

    printf("请输入您的身高foot  inch");
    scanf("%f %f",&foot,&inch);//如果变量用的是float类型，则用%f。如果用的double类型，则用%lf

    printf("nindeshengaoshi%f",((foot +inch/12)*0.3048));//无论用double还是float，输出都只用%f就可

    return 0;
}