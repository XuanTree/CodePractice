#include <stdio.h>
int main(){
    int maleChicken,femaleChicken,chick;
    for(int i = 1;i <= 100;i++){
        maleChicken  = i;
        for(int j = 1;j <= 100 - maleChicken;j++){
            femaleChicken = j;
            chick = 100 - maleChicken - femaleChicken;
            if(chick % 3 == 0){
                if(maleChicken * 5 + femaleChicken * 3 + chick/3 == 100){
                    printf("MaleChicken: %d\tFemaleChicken: %d\tChick: %d\n",maleChicken,femaleChicken,chick);
                    continue;
                }
            }
            else{
                continue;
            }
        }
    }
    return 0;
}