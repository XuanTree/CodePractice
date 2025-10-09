#include <stdio.h>

int main()
{
    int x;
    scanf("%d",&x);
    int isPrime = 2;

    for(int i = 2;i <= x-1;i++)
    {
        if(x % i != 0)
        {
            continue;
        }
        else
        {
            isPrime = 0;
            break;
        }
    }
    if(x && isPrime > 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}
