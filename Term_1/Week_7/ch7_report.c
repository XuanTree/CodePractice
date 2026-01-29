#include <stdio.h>
#include <string.h>
void charJudge(char *str){
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if(str[i] < 65){
            printf("%c is not a character!\n",str[i]);
        }
        else{
            if(str[i] <= 90){
                printf("%c's position is %d\n",str[i],str[i]-64);
            }
            else{
                printf("%c's position is %d\n",str[i],str[i]-96);
            }
        }
    }
}
int main(){
    char str[1000];
    while(gets_s(str,1000) != NULL){
        charJudge(str);
    }
    return 0;
}