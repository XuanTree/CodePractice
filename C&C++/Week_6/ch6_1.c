#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 400
void showArray(int array[],int n){
    for(int i = 0;i < n;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}
void findNumberLargerThanAverage(int array[],int n){
    int sum = 0;
    for(int i = 0;i < n;i++){
        sum += array[i];
    }
    double result = sum / n;
    printf("The average number is %.2lf\n",result);
    for(int i = 0;i < n;i++){
        if(array[i] >= result){
            printf("The number %d is larger than the average.\n",array[i]);
        }
    }
    printf("\n");
}
void reverseMaxAndMin(int array[],int n){
    int max = array[0];
    int min = array[0];
    int max_index = 0;
    int min_index = 0;
    int _array[n];
    for(int i = 0;i < n;i++){
        _array[i] = array[i];
    }
    for(int i = 0;i < n;i++){
        if(array[i] >= max){
            max = array[i];
            max_index = i;
        }
    }
    for(int i = 0;i < n;i++){
        if(array[i] <= min){
            min = array[i];
            min_index = i;
        }
    }
    array[min_index] = max;
    array[max_index] = min;
    printf("The array after reversing Max and Min:");
    showArray(array,n);
    for(int i = 0;i < n;i++){
        array[i] = _array[i];
    }
    printf("\n");
}
void reverseTheArray(int array[],int n){
    printf("The array after reversing:");
    for(int i = n - 1;i >= 0;i--){
        printf("%d ",array[i]);
    }
    printf("\n");
}
void bubbleSort(int array[],int n){
    for(int i = 0;i < n - 1;i++){
        for(int j = 0;j < n - 1- i;j++){
            if(array[j] >= array[j + 1]){
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    printf("The array after bubble sort:");
    showArray(array,n);
}
int findTheNumber(int array[],int n,int num){
    int num_index = 0;
    for(int i = 0;i < n;i++){
        if(array[i] == num){
            num_index = i;
            printf("Yes! The %d is equal to %d !\tIndex: %d times:%d\n",array[i],num,num_index,i + 1);
            return 1;
        }
        else{
            printf("No! The %d is not equal to %d !\n",array[i],num);
        }
    }
    printf("\n");
    return 0;
}
int betterFindTheNumber(int array[],int n,int num){
    int left = 0;
    int right = n - 1;
    int count = 0;
    while(left <= right){
        count++;
        int middle = left + (right - left) / 2;
        if(array[middle] == num){
            printf("Yes! The %d is equal to %d ! times:%d\n",array[middle],num,count);
            return 1;
        }
        if(array[middle] < num){
            printf("No! The %d is not equal to %d !\n",array[middle],num);
            left = middle + 1;
        }
        else{
            printf("No! The %d is not equal to %d !\n",array[middle],num);
            right = middle - 1;
        }
    }
    return 0;
}
void generateRandomNumbers(int array[],int n){
    srand(time(NULL));
    for(int i = 0;i < n;i++){
        array[i] = rand() % 100 + 1;
    }
    showArray(array,n);
}
int main(){
    int array[N];
    int n;
    printf("Input the real size of the array(n):");
    scanf("%d",&n);
    generateRandomNumbers(array,n);
    findNumberLargerThanAverage(array,n);
    reverseMaxAndMin(array,n);
    reverseTheArray(array,n);
    int number;
    printf("\n");
    printf("Input a number you want to find:");
    scanf("%d",&number);
    printf("\n");
    if(findTheNumber(array,n,number)){
        printf("Number Found.\n");
    }
    else{
        printf("No such number.\n");
    }
    bubbleSort(array,n);
    printf("\n");
    if(betterFindTheNumber(array,n,number)){
        printf("Number Found.\n");
    }
    else{
        printf("No such number.\n");
    }
    return 0;
}