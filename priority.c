#include <stdio.h>

/* int main() {   //计算平均数
    int a,b;
scanf("%d %d", &a,&b);
    double i=(a+b)/2.0;//算出小数

    printf("%f",i);
}*/


/* int main() {    //计算每年3.3%的利率存三年
  int x;
  scanf("%d",&x);
  double i=x*(1+0.033);
  double j=i*(1+0.033);
  double k=j*(1+0.033);

  printf("%f",k);
}*/

int main() {   //交换两个变量
    int a=5;
    int b=6;
    int c;
  /*  c=a;//调试在这一行显示红色，代码会在这里停止，可以通过调试查看函数值的变化
      a=b;
      b=c;
    printf("a=%d b=%d",a,b);
    */
    c=a++;//执行这条指令，在此时，a并没有加一，此时a=5，执行完这条指令之后，a+1
    printf("a=%d\n",c);
    c=++a;//执行这条指令，在此时，a在上一条指令加一的基础上再加一，此时a=7.执行完这条指令之后，a=7
    printf("a=%d\n",c);

    return 0;

}
