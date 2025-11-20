#include <stdio.h>
#include <string.h>
void mystrcat(char* s1,char* s2,char* new_s){
    int k = 0;
    int length_1 = strlen(s1);
    int length_2 = strlen(s2);
    for(int i = 0;i < 2 * length_1;i += 2){
        new_s[i] = s1[k];
        k++;
    }
    k = length_2 - 1;
    for(int i = 1;i < 2 * length_2;i += 2){
        new_s[i] = s2[k];
        k--;
    }
    printf("%s",new_s);
}
int main(){
    printf("Input two strings to connect:\n");
    char* string_1;
    char* string_2;
    char* newString;
    gets(string_1);
    gets(string_2);
    mystrcat(string_1,string_2,newString);
    return 0;
}