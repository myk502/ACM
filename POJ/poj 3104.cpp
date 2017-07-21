#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<cctype>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
int a[100000+10],n,k,maxn;
bool f(int x)
{
    if(k==1)
    {
        return(maxn<=x);
    }
    long long ans=0;
    int position=(lower_bound(a+1,a+n+1,x)-a);
    for(int i=position;i<=n;i++)
    {
        if(a[i]<=x)
            continue;
        else
        {
            if((a[i]-x)%(k-1)==0)
                ans+=(a[i]-x)/(k-1);
            else
                ans+=(a[i]-x)/(k-1)+1;
        }
    }
    if(ans<=(long long)x)
    {
        return true;
    }
    else
        return false;

}
int main(void)
{
    int left,right,mid;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    maxn=-1;
    for(int j=1;j<=n;j++)
        maxn=max(maxn,a[j]);
    sort(a+1,a+1+n);
    for(int i=1;i<=2;i++)
        continue;
    cin>>k;
    if(k==1)
    {
        printf("%d",maxn);
        return 0;
    }
    left=0;
    right=maxn;
    while(right-left>1)
    {
        mid=(left+right)/2;
        if(f(mid))
        {
            right=mid;
        }
        else
            left=mid;
    }
    cout<<right;
    return 0;
}
