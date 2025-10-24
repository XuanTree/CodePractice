#include <stdio.h>
int main(){
    int chicken,bunny;
    int heads = 35,feet = 94;
    for(int i = 0;i <= heads;i++){
        chicken = i;
        bunny = heads - i;
        if(2 * chicken + 4 * bunny == feet){
            break;
        }
    }
    printf("chicken: %d\tbunny: %d",chicken,bunny);
    return 0;
}