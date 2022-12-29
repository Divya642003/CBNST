#include<stdio.h>
#include<math.h>

double f(double x)
{
    return log(x);
}
int main()
{
   int x0,y0,xn,i;
   printf("Enter value of x0:");
    scanf("%lf",&x0);
    printf("Enter value of xn:");
    scanf("%lf",&xn);

  double h;
   printf("Enter value of h:");
    scanf("%lf",&h);

    int n =(xn-x0)/h;

    double sum =0;
     printf("\n\nx       \ty");
     for(i=0;i<=n;i++)
     {
         printf("\n%7lf\t%7lf",x0+h*i,fun(x0+h*i));
         if(i==0||i==n)
         {
            sum+=f(x0+h*i);
         }
         else if(i%3==0)
        {
            sum+=2*fun(x0+h*i);
        }
        else
        {
            sum+=3*fun(x0+h*i);
        }
     }
     sum=sum*(3*h/8);
     printf("\n\nResult: %7lf",sum);
    return 0;
}