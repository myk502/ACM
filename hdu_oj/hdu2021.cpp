#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[110],n;
int gongzi(int x)
{
    int ans=0;
    ans+=x/100;
    x%=100;
    ans+=x/50;
    x%=50;
    ans+=x/10;
    x%=10;
    ans+=x/5;
    x%=5;
    ans+=x/2;
    x%=2;
    ans+=x;
    return ans;
}
int main(void)
{
    int ans=0;
    while(cin>>n)
    {
        ans=0;
        if(n==0)
            break;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            ans+=gongzi(a[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
