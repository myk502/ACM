#include<stdio.h>
int find_index(double *ptr,int SIZE)
{
    double temp=*ptr;
    int i,max_index=0;
    for(i=1;i<SIZE;i++)
    {
        if(*(ptr+i)>temp)
        {
            temp=*(ptr+i);
            max_index=i;
        }
    }
    return max_index;
}
int main(void)
{
    double arr[5]={1.1,2.2,3.3,4.4,5.5};
    int ans=find_index(arr,5);
    printf("%d\n",ans);
    return 0;
}
