#include <stdio.h>

int main(void) {
    //int price =0;//定义了一个int类型叫price变量
    //const int A=100;//const表示一个固定的属性，一旦初始化就不能修改
    //printf("请输入金额：");
    //scanf("%d",&price );
    //int change=A-price;
    //printf("找您：%d",change);
    //return 0;
    int price2=0;
    int amount=100;//因为前面不再是const，所以变量名不在强调不能修改的属性

    printf("qingshuru：&d");
    scanf("%d",&price2);

    printf("piaomian：");
    scanf("%d",&amount);

    int change2=amount-price2;

    printf("zhaonin:%d",change2);

    return 0;
}

int Fuckconst(void){
    //int price2=0;
    //int amount=100;//因为前面不再是const，所以变量名不在强调不能修改的属性
    //printf("请输入：&d");
    //scanf("%d",&price2);
    //printf("票面：");
    //scanf("%d",&amount);
    //int change2=amount-price2;
    //printf("zhaonin:",change2);
    //return 0;

}