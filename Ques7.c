#include<stdio.h>
int main()
{
    int n;
    printf("ENTER THE NUMBER OF UNKNOWNS :: ");
    scanf("%d",&n);
    double eq[n][n+1];
    double values[n];
    int i,j,k;
    for(i=0;i<n;i++)
    {
    printf("ENTER THE %d CONSTANTS OF EQUATION %d ::", n+1,i+1);
    for(j=0;j<n+1;j++)
    scanf("%d",&eq[i][j]);
    }

    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            
            if(i!=k)
            {
                int temp = eq[i][k]/eq[k][k];
                 for(j=0;j<n+1;j++)
                 {
                    eq[i][j]=eq[i][j]-temp*eq[k][j];
                 }
            }
        }
    }
     for(k=0;k<n;k++)
     {
          values[k]=eq[k][n]/eq[k][k];
     }
    printf("\n\nUnknowns are:");
 for(i=0;i<n;i++)
 {
 printf("\nx%d=%f\n",i,values[i]);
 }
}