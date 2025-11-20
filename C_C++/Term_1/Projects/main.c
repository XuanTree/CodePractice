#include <stdio.h>
#include <stdlib.h>
#include "printTest.h"
typedef struct Student{
    char name[20];
    int age;
}Student;
int main(){
    Student students[50];
    
    FILE *fp = NULL;
    int count = 0;
    fp = fopen("StudentsList.txt","r");
    if(fp == NULL){
        perror("Failed");
    }
    while(count < 50 && fscanf(fp,"%s %d",students[count].name,&students[count].age) == 2){
        count++;
    }
    fclose(fp);
    printf("%d messages have been included\n",count);
    for(int i = 0;i < count;i++){
        printf("name: %s age: %d\n",students[i].name,students[i].age);
    }
    //printTest();
    system("pause");
    return 0;
}