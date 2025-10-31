#include <stdio.h>
int main(){
    printf("Please input numbers(-100~100 ,-1 = end)\n");
    int numbers[100];
    int frequency[205] = {0};
    int index = 0;
    while(scanf("%d",&numbers[index]) != EOF){
        if(numbers[index] == -1){
            break;
        }
        index++;
    }
    for(int i = 0;i < index;i++){
        int frequency_index = numbers[i] + 100;
        frequency[frequency_index]++;
    }
    printf("Numbers\tFrequency\n");
    for(int i = 0;i < 200;i++){
        if(frequency[i] > 0){
            int num = i - 100;
            printf("%d\t%d\n",num,frequency[i]);
        }
    }
    printf("After sorting:\n");
    printf("\n");
    printf("Numbers\tFrequency\n");
    for(int i = 0;i < 201;i++){
        int max = i;
        for (int j = i; j < 201; j++){
			if (frequency[j] > frequency[max] || (frequency[j] == frequency[max] && j > max)){
				max = j;
            }
		}
		if(frequency[max]!=0){
			printf("%d\t%d\n", max - 100, frequency[max]);
        }
        frequency[max] = 0;
	}    
    return 0;
}