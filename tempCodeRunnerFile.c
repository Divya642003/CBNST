#include<stdio.h>
int main()
{
    int n,i,j;
    printf("Enter the number of values : ");
    scanf("%d",&n);
    double p;
    printf("Enter the interpolation point : ");
    scanf("%lf",&p);
     double x[n],y[n];
     printf("Enter %d values of X and Y ::\n",n);
     for(i=0;i<n;i++)
     {
        scanf("%lf %lf",&x[i],&y[i]);
     }
    
    printf("  X        Y  \n");
    for(i=0;i<n;i++)
    {
        printf("%lf\t%lf\n",x[i],y[i]);
    }

    double result =0;
    for(i=0;i<n;i++)
    {
        double temp =1;
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
            temp = temp*(p-x[j])/(x[i]-x[j]);
            }
        }
        temp = temp*y[i];
        result = result + temp;
    }

    printf("The value of polynomial at %lf interpolation point  is %lf ",p,result);
}