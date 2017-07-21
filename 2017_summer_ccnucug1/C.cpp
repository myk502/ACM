#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
long long n;
long long FastMod(long long x,long long y)
{
    if(y==0)
        return x%10;
    if(y%2==0)
        return (FastMod(x,y/2)*FastMod(x,y/2))%10;
    return (x*FastMod(x,y-1))%10;
}
int main(void)
{
    cin>>n;
    long long ans=FastMod(n,n);
    cout<<ans<<endl;
    return 0;
}
