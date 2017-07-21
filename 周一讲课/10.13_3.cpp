#include<stdio.h>
#include<limits.h>
int zuida(int *ptr,int SIZE)
{
    int i,temp=INT_MIN;
    for(i=0;i<SIZE;i++)
    {
        if(*(ptr+i)>temp)
            temp=*(ptr+i);

    }
    return temp;

}

int main(void)
{
    int arr[5]={1,2,3,24,5};
    int ans=zuida(arr,5);
    printf("%d\n",ans);
    return 0;
}
