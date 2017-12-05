#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100],n,ans;
int main(void)
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    ans=0;
    if(n==1)
    {
        if(a[0]==0)
            ans=1;
        if(a[0]==15)
            ans=-1;
    }
    else
    {
        if((a[n-2]==14)&&(a[n-1]==15))
            ans=-1;
        else if((a[n-2]==1)&&(a[n-1]==0))
            ans=1;
            else
            {
                if(a[n-2]<a[n-1])
                    ans=1;
                else
                    ans=-1;
            }
    }
    if(ans==0)
        printf("-1");
    if(ans==-1)
        printf("DOWN");
    if(ans==1)
        printf("UP");
    return 0;
}
