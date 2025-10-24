#include <stdio.h>
int main(){
    int num1;
    int num2;
    int num3;
    for(int i = 200;i <= 300;i++){
        int temp = i;
        num1 = temp % 10;
        num2 = (temp /= 10) % 10;
        num3 = (temp /= 10) % 10;
        if(num1 * num2 * num3 == 42 && num1 + num2 + num3 == 12){
            printf("%d\n",i);
        }
    }
    return 0;
}