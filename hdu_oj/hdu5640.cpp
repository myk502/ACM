#include<cstdio>
#include<cstring>
#include<iostream>
#include<climits>
#include<cmath>
#include<algorithm>
#include<ctype.h>
using namespace std;
int f(int a,int b)
{

    if(a<b)
        swap(a,b);
    if(a%b==0)
        return(a/b);
    else
        return(a/b+f(b,a%b));
}
int main(void)
{
    int t,m,n,ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(n==m)
            ans=1;
        else
        {
            ans=f(m,n);
        }
        cout<<ans<<endl;
    }
    return 0;
}
