#include <stdio.h>

//Lagrange interpolation

//main function
int main()
{
    float x[5], y[5], xp, yp = 0, p;
    
    int i = 0, j = 0;
    
    x[0] = 5;
    y[0] = 150;
    x[1] = 7;
    y[1] = 392;
    x[2] = 11;
    y[2] = 1452;
    x[3] = 13;
    y[3] = 2366;
    x[4] = 17;
    y[4] = 5202;
    
    xp = 9;
    
    for(i = 0; i < 5; i++)
    {
        p = 1;
        
        for (j=0; j < 5; j++)
        {
            //compute interpolation
            if (i != j)
            {
                p *= (xp - x[j])/(x[i] - x[j]);
            }
        }
        
        yp += p * y[i];
    }
    
    
    printf("Interpolated value for %.3f = %.3f ", xp, yp);
    return 0;
}
