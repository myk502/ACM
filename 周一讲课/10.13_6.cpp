#include<stdio.h>
void copy_ptr(double (*source)[3],double (*target)[3],int num)
{
    int i,j;
    for(i=0;i<num;i++)
        for(j=0;j<3;j++)
            target[i][j]=source[i][j];
}
int main(void)
{
    double a[3][3]={1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};
    double b[3][3];
    copy_ptr(a,b,3);
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            printf("%.1f ",b[i][j]);
        printf("\n");
    }
    return 0;
}
