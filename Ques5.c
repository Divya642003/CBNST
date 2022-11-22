#include <stdio.h>
#include<math.h>
double new(double x)
{
    return cbrt(2*x*x+4);
}
double turncate(double x)
{
    int y= (int)(x*1000);
			double z= (double)y/1000;
			return z;
}
int isEqual(double arr[3])
{ 
    if(turncate(arr[0])==turncate(arr[1])&&turncate(arr[1])==turncate(arr[2])){return 1;}
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
        scanf("%lf",&arr[0]);
        printf("\nx0 = %lf",turncate(arr[0]));
        arr[1]=new(arr[0]);
        printf("\nx1 = %lf",turncate(arr[0]));
        arr[2]=new(arr[1]);
         printf("\nx2 = %lf",turncate(arr[0]));
        int itr=2;

        while(!isEqual(arr))
        {
             itr++; 
          // printf("f%lf=%lf \t f1 %lf=%lf \t %lf=%lf %lf\n",arr[0],f(arr[0]),arr[0],y(arr[0]),arr[1],f(arr[1]),arr[2]);
         arr[itr%3]=new(arr[(itr+2)%3]);
         printf("\nx%d=%lf",itr,turncate(arr[itr%3]));
               
        }
       
        printf("\nNumber of iterations:%d\nResult=%lf",itr,turncate(arr[0]));
        break;
        
    }
}
