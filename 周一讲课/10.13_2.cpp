#include<stdio.h>
void copy_arr(double source[],double arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
        arr[i]=source[i];
}
void copy_ptr(double *source,double *ptr,int num)
{
    int i;
    for(i=0;i<num;i++)
        *(ptr+i)=*(source+i);
}
int main(void)
{
    int i;
    double source[5]={1.1,2.2,3.3,4.4,5.5};
    double target1[5],target2[5];
    copy_arr(source,target1,5);
    copy_ptr(source,target2,5);
    for(i=0;i<5;i++)
        printf("%.1f ",target1[i]);
    printf("\n");
    for(i=0;i<5;i++)
        printf("%.1f ",target2[i]);
    printf("\n");
    return 0;
}
