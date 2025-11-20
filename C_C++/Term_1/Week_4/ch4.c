#include <stdio.h>
#include <math.h>

int main(){
    double num;
    printf("输入一个数字,计算它的算术平方根:");
    while(scanf("%lf",&num) != EOF){
        if (num >= 0 && num < 1000){
            if (floor(sqrt(num)) != sqrt(num)){
                int result = sqrt(num);
                printf("%d",result);
            }
            else{
                printf("%.2lf",sqrt(num));
            }
            break;
        }
        else{
            printf("请重新输入一个正数:\n");
            continue;
        }
    }
    return 0;
}