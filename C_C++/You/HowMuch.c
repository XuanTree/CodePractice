#include <stdio.h>
int main(){
    for(double year = 1.0f;year <= 10;year++){
        double result = 12 * year * 30;
        double discount = 0.8f;
        double newResult = 558 + result * discount;
        if(newResult < result){
            printf("%.2lf:\n",year);
            printf("%.2lf is smaller than %.2lf\n",newResult,result);
            break;
        }
    }
    return 0;
}