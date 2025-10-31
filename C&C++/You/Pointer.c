#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct TwoNumbers{
    double a;
    double b;
}TwoNumbers;
TwoNumbers DealTwoNumbers(double a,double b){
    TwoNumbers tw;
    tw.a = a * 2;
    tw.b = b * 3.5f;
    return tw;
}
int* generateArray(int *array){
    srand(time(NULL));
    int size = sizeof(array);
    for(int i = 0;i < size;i++){
        array[i] = rand() % 10 + 1;
    }
    return array;
}
void showArray(int *array){
    int size = sizeof(array);
    for(int i = 0;i < size;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}
int main(){
    int a = 10;
    //p获取a的地址
    int* p = &a;
    printf("%d\t%p\n",a,p);
    //修改a的值
    *p = 20;
    printf("%d\t%p\n",a,p);
    printf("\n");
    int array[100];
    generateArray(array);
    showArray(array);
    printf("\n");
    //使用指针获取结构体的函数
    TwoNumbers(*p_twonums)(double,double);
    p_twonums = &DealTwoNumbers;
    TwoNumbers tw = p_twonums(10.0,1000.0);
    printf("%.2lf\t%.2lf\n",tw.a,tw.b);
    return 0;
}