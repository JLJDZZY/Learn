#include <stdio.h>
#include <stdlib.h>
#include <windows.h>



int main() {
    SetConsoleOutputCP(CP_UTF8);
    int n=0;

    printf(" 请输入一个数\n");
    scanf(" %d ",&n);

    int fact=1;
    int i=1;

    for (i=1;i<=n;i++) {//  i=1为初始条件；i<=n为判断条件，i++为循环要执行的动作
        fact *= i;
        break;//遇到break会跳出循环
    }

printf("%d!= %d",n,fact);
}
