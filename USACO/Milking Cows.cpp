/*
ID: myk5021
PROG: milk2
LANG: C++11
*/
#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<climits>
using namespace std;
const int maxn=1000000+10;
int n,a[maxn],sum_a[maxn];
int main(void)
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    int ans1=0,ans2=0,left,right,continue_0,continue_1,lmin=maxn,rmax=0;
    memset(a,0,sizeof(a));
    memset(sum_a,0,sizeof(sum_a));
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>left>>right;
        a[left]+=1;
        a[right]-=1;
        rmax=max(rmax,right);
        lmin=min(lmin,left);
    }
    sum_a[0]=a[0];
    for(int i=1;i<=rmax;i++)
        sum_a[i]=sum_a[i-1]+a[i];
    continue_1=continue_0=0;
    for(int i=lmin;i<=rmax;i++)
    {
        if(sum_a[i]==0)
        {
            continue_0++;
            continue_1=0;
        }
        else
        {
            continue_1++;
            continue_0=0;
        }
        ans1=max(ans1,continue_1);
        ans2=max(ans2,continue_0);
    }
    if(rmax-lmin==ans1)
    {
        ans2--;
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}

