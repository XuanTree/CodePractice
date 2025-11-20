#include <stdio.h>

int main()
{
    char c1 = 'C';
    char c2 = 'h';
    char c3 = 'i';
    char c4 = 'n';  
    char c5 = 'a';

    c1 = putchar(c1) + 4;
    c2 = putchar(c2) + 4;
    c3 = putchar(c3) + 4;
    c4 = putchar(c4) + 4;
    c5 = putchar(c5) + 4;
    
    printf("\n%c%c%c%c%c",c1,c2,c3,c4,c5);

    return 0;
}