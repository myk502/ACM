#include<bits/stdc++.h>
using namespace std;

const int maxn=200000+10;
long long ans,cnt,a[maxn],differ;
int n;

int main(void)
{
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    sort(a,a+n);
    ans=20000000000LL;
    cnt=0;
    for(int i=1;i<n;i++)
    {
        differ=a[i]-a[i-1];
        //cout<<"differ="<<differ<<endl;
        if(differ==ans)
            cnt++;
        if(differ<ans)
        {
            ans=differ;
            cnt=1L;
        }
    }
    cout<<ans<<" "<<cnt;
    return 0;
}
