#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
using namespace std;
#define zuida 500000
int a[zuida+10];
int n,i,j;
bool cmp(int a,int b)
{
    return(a>b);
}
int main(void)
{
    int k,temp=0,num=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n,cmp);
    if(n%2==1)
        j=n/2;
    else
        j=n/2;
    int j0=j;
    for(i=0;i<j0;i++)
    {
        while((j<n)&&(a[i]<a[j]*2))
        {
            if(j==n-1)
                temp=1;
            j++;
        }
        if(j<n)
            num++;
        j++;
    }
    //if(temp==1)
            //num++;


        printf("%d",n-num);


}
