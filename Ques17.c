#include<stdio.h>
#include<math.h>

double f(double x,double y)
{
    return x+y;
}

int main()
{
    double x0,y0,h;
     printf("Enter value of x0:");
    scanf("%lf",&x0);
    printf("Enter value of y0:");
    scanf("%lf",&y0);

    double x;
     printf("Enter x:");
    scanf("%lf",&x);
    printf("Enter value of h:");
    scanf("%lf",&h);

    int n=(x-x0)/h;

     double k1,k2,k3,k4;
    int i=0;
    printf("\n\nx      \ty      ");
    for(i=0;i<n;i++)
    {
         k1=h*f(x0,y0);
        k2=h*f(x0+h/2,y0+k1/2);
        k3=h*f(x0+h/2,y0+k2/2);
        k4=h*f(x0,y0+k3);
        printf("\nIn %d iteration, x0= %f y0= %f, k1= %f, k2= %f, k3= %f, k4= %f",i,x0,y0,k1,k2,k3,k4);
        y0= y0+(k1+2*k2+2*k3+k4)/6;
        x0=x0+h;
    }

     printf("\n\ny at %7lf: %7lf",x,y0);
    return 0;
}