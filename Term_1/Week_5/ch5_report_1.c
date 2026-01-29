#include <stdio.h>
int main(){
    double result = 0;
    int count = 1;
    for(double i = 1;count <= 100;i++){
        if(count % 2 == 0){
            result -= 1/i;
        }
        else{
            result += 1/i;
        }
        count++;
    }
    printf("%lf",result);
    return 0;
}