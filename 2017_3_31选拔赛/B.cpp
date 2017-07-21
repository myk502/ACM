#include<bits/stdc++.h>
using namespace std;
long long a[30];
int n;
set<long long> s;
bool cmp(long long x,long long y)
{
    return (x>y);
}
int main(void)
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,cmp);
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        while((a[i]>0)&&(s.count(a[i])!=0))
            a[i]--;
        if(a[i]!=0)
        {
            ans+=a[i];
            s.insert(a[i]);
        }
    }
    cout<<ans;
    return 0;
}
