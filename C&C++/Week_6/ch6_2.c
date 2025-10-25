#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
void showArray(int array[][N],int n){
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void generateRandomNumbers(int array[][N],int n){
    srand(time(NULL));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            array[i][j] = rand() % 100 + 1;
        }
    }
    showArray(array,n);
}
void sumOnDiagnol(int array[][N],int n){
    int sum = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(i == j){
                sum += array[i][j];
            }
        }
    }
    printf("The sum is %d\n",sum);
}
void isEven(int array[][N],int n){
    int result = 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(i == j){
                if(i % 2 == 0 && j % 2 == 0){
                    result *= array[i][j];
                }
            }
        }
    }
    printf("The result is %d\n",result);
}
void findTheMax(int array[N][N],int n){
    int max = array[0][0];
    int max_index[2];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(i == j){
                if(array[i][j] >= max){
                    max = array[i][j];
                    max_index[0] = i;
                    max_index[1] = j;
                }
            }
        }
    }
    printf("The max is %d.Its index is (%d,%d)\n",max,max_index[0],max_index[1]);
}
int main(){
    int array[N][N];
    generateRandomNumbers(array,4);
    sumOnDiagnol(array,4);
    isEven(array,4);
    findTheMax(array,4);
    return 0;
}