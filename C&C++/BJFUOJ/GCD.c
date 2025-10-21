#include <stdio.h>
int gcd(int num1,int num2){
    while(num2 != 0){
        int temp = num1 % num2;
        num1 = num2;
        num2 = temp;
    }
    return num1;
}
int main(){
    int a,b;
    printf("Please input two numbers:");
    scanf("%d %d",&a,&b);
    printf("The GCD is %d",gcd(a,b));
    return 0;
}