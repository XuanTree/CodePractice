#include <stdio.h>
#include <math.h>

int main()
{
    double a,p,q;
    scanf("%lf  %lf  %lf",&a,&p,&q);

    double delta = pow(p/3,3) + pow(q/2,2);
    
    if(a != 0 || p!= 0)
    {   if (a == 0 && p == 0 && q == 0)
        {
            printf("Infinite solutions");
        }
        else
        {
            if(delta < 0)
            {
                printf("3\n");
            }
            else
            {
                if(delta == 0)
                {
                    printf("2\n");
                }
                else
                {
                    printf("1\n");
                }
            }
        }
    }
    else
    {
        printf("No Real Root");
    }
    return 0;
}