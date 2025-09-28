# include <stdio.h>

int max(int a,int b,int c);

int main()
{
    int a,b,c;

    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);

    int result = max(a,b,c);
    printf("%d\n",result);

    return 0;
}

int max(int a,int b,int c)
{
    int m = a;
    
    if (b >= m)
    {
        m = b;
    }
    if (c >= m) 
    {
        m = c;
    }
    return m;
}
