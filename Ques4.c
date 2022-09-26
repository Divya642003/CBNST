#include <stdio.h>
#include<math.h>
double f(double x)
{
    return 3*x-cos(x)-1;
}
double f1(double x)
{
    return 3+sin(x);
}
double turncate(double x)
{
    int y= (int)(x*1000);
			double z= (double)y/1000;
			return z;
}
int isEqual(double arr[3])
{ 
    if(turncate(arr[0])==turncate(arr[1])&&turncate(arr[1])==turncate(arr[2])&&turncate(arr[0])==turncate(arr[2])){return 1;}
    else
    {return 0;}
}
int main()
{
    double temp =0;
    while(1)
    {
        double arr[3];
        printf("Enter value of x0 :\n");
        scanf("%lf",&arr[1]);
        int itr=1;
        while(!isEqual(arr))
        {
          //  printf("f%lf=%lf \t f1 %lf=%lf \t %lf=%lf %lf\n",arr[0],f(arr[0]),arr[0],f1(arr[0]),arr[1],f(arr[1]),arr[2]);
            arr[2]=arr[1]-(f(arr[1])/f1(arr[1]));
                 arr[0]=arr[1];
                arr[1]=arr[2];
           
            printf("\nITERATION NUMBER :%d",itr);
             printf("\n%lf\n%lf\n%lf",arr[0],arr[1],arr[2]);
             itr++;    
        }
       
        printf("\nNumber of iterations:%d\nResult=%lf",itr,turncate(arr[0]));
        break;
        
    }
