#include <stdio.h>

int main()
{
    int max(int a,int b);

    int a,b,c;
    printf("Please input two numbers:");
    scanf("%d,%d",&a,&b);
    c = max(a,b);
    printf("max = %d\n",c);
    return 0;
}

int max(int a,int b)
{
    int z;

    if(a > b)
    {
        z = a;
    }
    else
    {
        z = b;
    }
    return z;
}