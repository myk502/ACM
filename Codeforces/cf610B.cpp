#include<string>
#include<sstream>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<limits.h>
#include<float.h>
#include<math.h>
#include<algorithm>
using namespace std;
int a[200000+10],n,minn,lianxu;
int main(void)
{
    int num=0;
    cin>>n;
    minn=INT_MAX;
    lianxu=INT_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        minn=min(minn,a[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]!=minn)
            num++;
        else
        {
            lianxu=max(num,lianxu);
            num=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]!=minn)
            num++;
        else
        {
            lianxu=max(num,lianxu);
            num=0;
        }
    }
    long long ans;
    ans=(long long)minn*(long long)n+(long long)lianxu;
    cout<<ans;
    return 0;
}
