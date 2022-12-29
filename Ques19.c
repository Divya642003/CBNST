#include <stdio.h>

void gauss_elimination(float eq[3][4],int n,float unknowns[3])
{
    int i,j;
    int k;
    for(k=0;k<n-1;k++)
    {
        for(i=k+1;i<n;i++)
        {
            float temp=eq[i][k]/eq[k][k];
            for(j=0;j<n+1;j++)
            {
                eq[i][j]=eq[i][j]-temp*eq[k][j];
            }
        }
    }
    for(k=n-1;k>=0;k--)
    {
        unknowns[k]=eq[k][n];
        for(j=0;j<n;j++)
        {
            if(k!=j)
            {
                unknowns[k]=unknowns[k]-unknowns[j]*eq[k][j];
            }
        }
        unknowns[k]/=eq[k][k];
    }
    printf("\nExcuted");
}

int main()
{
    printf("Enter number of provided x,y values:");
    int n;
    scanf("%d",&n);
    int i,j;
    float x[n],y[n],xy[n],x2[n],x3[n],x4[n],x2y[n];
    printf("Enter values of x and y for %d times:\n",n);
    for(i=0;i<n;i++)
    {
        printf("Enter x:");
        scanf("%f",&x[i]);
        printf("Enter y:");
        scanf("%f",&y[i]);
        xy[i]=x[i]*y[i];
        x2[i]=x[i]*x[i];
        x3[i]=x2[i]*x[i];
        x4[i]=x3[i]*x[i];
        x2y[i]=x2[i]*y[i];
    }
    float sum_x=0,sum_y=0,sum_xy=0,sum_x2=0,sum_x3=0,sum_x4=0,sum_x2y=0;
    printf("\nTable is:\n");
    printf("\nx        \ty        \txy        \tx^2      \tx^3      \tx^4      \tx^2*y      ");
    for(i=0;i<n;i++)
    {
        printf("\n%9f\t%9f\t%9f\t%9f\t%9f\t%9f\t%9f",x[i],y[i],xy[i],x2[i],x3[i],x4[i],x2y[i]);
        sum_x+=x[i];
        sum_y+=y[i];
        sum_xy+=xy[i];
        sum_x2+=x2[i];
        sum_x3+=x3[i];
        sum_x4+=x4[i];
        sum_x2y+=x2y[i];
    }
    printf("\n\nSigma x : %f",sum_x);
    printf("\nSigma y: %f",sum_y);
    printf("\nSigma x*y: %f",sum_xy);
    printf("\nSigma x square: %f",sum_x2);
    printf("\nSigma x cube: %f",sum_x3);
    printf("\nSigma x to the power 4: %f",sum_x4);
    printf("\nSigma x square * y: %f",sum_x2y);
    printf("\nNormal equations are:");
    printf("\n%f * a + %f * b + %d * c = %f",sum_x2,sum_x,n,sum_y);
    printf("\n%f * a + %f * b + %f * c = %f",sum_x3,sum_x2,sum_x,sum_xy);
    printf("\n%f * a + %f * b + %f * c = %f",sum_x4,sum_x3,sum_x2,sum_x2y);
    float eq[3][4];
    eq[2][0]=sum_x2;eq[2][1]=sum_x;eq[2][2]=n;eq[2][3]=sum_y;
    eq[1][0]=sum_x3;eq[1][1]=sum_x2;eq[1][2]=sum_x;eq[1][3]=sum_xy;
    eq[0][0]=sum_x4;eq[0][1]=sum_x3;eq[0][2]=sum_x2;eq[0][3]=sum_x2y;
    float unknowns[3];
    gauss_elimination(eq,3,unknowns);
    printf("\nCofficients are: a=%f b=%f c=%f",unknowns[0],unknowns[1],unknowns[2]);
    printf("\nEquation of parabola: y = %f * x^2 + %f * x + %f",unknowns[0],unknowns[1],unknowns[2]);
    return 0;
}