#include <stdio.h>
int main(){
    int num,_num;
    while (scanf("%d",&num) != EOF){
        _num = num;
        if(num < 0 || num > 99999){
            printf("请重新输入一个数字(0-99999):");
        }
        else{
            int count = 0;
            while(num > 0){
                num /= 10;
                count++;
            }
            num = _num;
            printf("\n你输入了一个%d位数",count);
            switch (count)
            {
            case 1:
                printf("\n个位:%d",num);
                printf("\n按逆序输出结果:%d\n",num);
                break;
            case 2:
                int num1 = num % 10;
                int num2 = num /= 10;
                printf("\n个位:%d 十位:%d",num1,num2);
                printf("\n按逆序输出结果:%d%d\n",num1,num2);
                break;
            case 3:
                num1 = num % 10;
                num2 = (num /= 10) % 10;
                int num3 = (num /= 10) % 10;
                printf("\n个位:%d 十位:%d 百位:%d",num1,num2,num3);
                printf("\n按逆序输出结果:%d%d%d\n",num1,num2,num3);
                break;
            case 4:
                num1 = num % 10;
                num2 = (num /= 10) % 10;
                num3 = (num /= 10) % 10;
                int num4 = (num /= 10) % 10;
                printf("\n个位:%d 十位:%d 百位:%d 千位:%d",num1,num2,num3,num4);
                printf("\n按逆序输出结果:%d%d%d%d\n",num1,num2,num3,num4);
                break;
            case 5:
                num1 = num % 10;             //获取个位数num1
                num2 = (num /= 10) % 10;     //获取十位数num2
                num3 = (num /= 10) % 10;     //获取百位数num3
                num4 = (num /= 10) % 10;     //获取千位数num4
                int num5 = (num /= 10) % 10; //获取万位数num5
                printf("\n个位:%d 十位:%d 百位:%d 千位:%d 万位:%d",num1,num2,num3,num4,num5);
                printf("\n按逆序输出结果:%d%d%d%d%d\n",num1,num2,num3,num4,num5);
                break;
            default:
                printf("这要是运行了就很诡异知道吗");
                break;
            }
            break;
        }
    }
    return 0;
}