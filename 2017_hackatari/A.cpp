#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+12;
int b[maxn];
long double c[maxn],sum[maxn];
int n,k;
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(int i=0;i<n;i++)
    {
       cin>>c[i];
    }
    for (int i=0;i<maxn;i++) sum[i] = 0.0;
    sum[0]=0.0;
    for (int i=0;i<n;i++)
        sum[b[i]]+=1.0000-c[i];
    for (int i=1;i<maxn;i++)
        sum[i]+=sum[i-1];
    long double ans = 0.00;
    for (int i=1,k1=0,k2=0;i<n;i++){
        /*while (k1+1<n&&a[k1+1].first > b[i]) k1++;

        if (a[k1].first-k>=b[i]) continue;

        while (k2+1<=k1 && a[k2].first-b[i]>=k) k2++;*/
        ans+=(long double)c[i]*
        (sum[min(b[i]+k-1,maxn-1)]-sum[b[i]]);
    }
    cout<<ans<<endl;
    return 0;
}
