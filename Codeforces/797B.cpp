#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
int odd[maxn],even[maxn],n;
int a[maxn];
int main(void)
{
    cin>>n;
    for(int i=0;i<n;i++)
       scanf("%d",&a[i]);
    even[0]=0;
    odd[0]=INT_MIN/2;
    for(int i=0;i<n;i++)
    {
        if((a[i]%2+2)%2==1)
        {
            odd[i+1]=max(odd[i],even[i]+a[i]);
            even[i+1]=max(even[i],odd[i]+a[i]);
        }
        else
        {
            odd[i+1]=max(odd[i],a[i]+odd[i]);
            even[i+1]=max(even[i],even[i]+a[i]);
        }
    }
    printf("%d",odd[n]);
    return 0;
}
