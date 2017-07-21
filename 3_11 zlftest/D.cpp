#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int dp(int m,int n)
{
    if(m==0)
        return 1;
    if(n==1)
        return 1;
    if(m-n>=0)
        return dp(m,n-1)+dp(m-n,n);
    else
        return dp(m,n-1);
}
int main(void)
{
    int t,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        cout<<dp(x,y)<<endl;
    }

    return 0;
}
