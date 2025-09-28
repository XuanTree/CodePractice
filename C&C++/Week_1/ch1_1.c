#include <stdio.h>

int main()
{
     int a,b,c;

    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);

    int m = a;
    if(b >= m)
    {
        m = b;
    }
    if (c >= m) 
    {
        m = c;
    }
    printf("The max number is %d",m);
    return 0;
}