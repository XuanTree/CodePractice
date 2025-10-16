#include <stdio.h>
#include <string.h>
int main(){
    char number[100];
    printf("请输入一个数字(100位都没关系的):");
    while(scanf("%s",number) != EOF){
        int length = strlen(number);
        printf("这是一个%d位数",length);
        for (int i = 0;i < length;i++){
            printf("%c ",number[i]);
        }
        printf("\n逆序输出:");
        for(int i = length;i >= 0;i--){
            printf("%c",number[i]);
        }
        printf("\n请输入一个数字(100位都没关系的):");
    }
    return 0;
}