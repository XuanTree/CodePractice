#include <stdio.h>
#include <string.h>
#define N 100
char* connectTwoStrings(char* s1, char* s2){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for(int i = len1 - 1;i < len1 + len2;i++){
        s1[i + 1] = s2[i - len1 + 1];
    }
    return s1;
}
int main(){
    char s1[N], s2[N];
    printf("Enter the first string:");
    scanf("%s", s1);
    printf("Enter the second string:");
    scanf("%s", s2);
    char* result = connectTwoStrings(s1, s2);
    printf("The connected string is: %s", result);
    return 0;
}