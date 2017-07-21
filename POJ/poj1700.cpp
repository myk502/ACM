#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1010],ans;
void duhe(int x)
{
    int i,j,k,m,temp1,temp2;
    if(x==1)
    {
        ans+=a[1];
    }
    if(x==2)
    {
        ans+=max(a[1],a[2]);
    }
    if(x==3)
    {
        //sort(a,a+n);
        ans+=a[3];
        ans+=a[1];
        ans+=a[2];
    }
    if(x>3)
    {
        i=1;
        j=2;
        k=x-1;
        m=x;
        temp1=a[i]+2*a[j]+a[m];
        temp2=2*a[i]+a[m]+a[k];
        ans+=min(temp1,temp2);
        duhe(x-2);
    }
    return ;
}
int main(void)
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        ans=0;
        sort(a+1,a+n+1);
        duhe(n);
        cout<<ans<<endl;
    }
    return 0;
}
