#include <stdio.h>
#include <math.h>

int main()
{
    float r = 0.09;
    
    float result = pow((1 + r), 10);
    
    printf("p = %.2f\n",result);

    return 0;
}