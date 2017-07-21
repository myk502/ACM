#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int n,m;
int solve(int n,int m)//brute force
{
    int sum=0;
    for(int i=m;i>=0;i--)
    {
        int temp=(1<<i);
        if(n/temp>=1)
        {
            sum+=n/temp;
            n%=temp;
        }
    }
    return sum;
}
int solve(int n)//count 1s in n(binary representation)
{
    int cnt=0;
    while(n!=0)
    {
        cnt++;
        n=n&(n-1);
    }
    return cnt;
}
int main(void)
{
    int T,ans;
    cin>>T;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        if(m<=30)
            ans=solve(n,m);
        else
            ans=solve(n);
        printf("%d\n",ans);
    }
    return 0;
}
