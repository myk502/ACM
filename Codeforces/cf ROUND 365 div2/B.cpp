#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<climits>
#include<cfloat>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
unsigned long long sum,sum_normal,sum_capital[10010],ans,n,k,c[10010],id[10010],iscapital[10010];

int main(void)
{
    cin>>n>>k;
    ans=sum_normal=sum=0;
    c[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        sum+=c[i];
    }
    memset(iscapital,0,sizeof(iscapital));
    memset(sum_capital,0,sizeof(sum_capital));
    //memset(sum_normal,0,sizeof(sum_normal));
    for(int i=1;i<=k;i++)
    {
        cin>>id[i];
        iscapital[id[i]]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(iscapital[i])
        {
            sum_capital[i]=sum_capital[i-1]+c[i];
            //sum_normal[i]=sum_normal[i-1];
        }
        else
        {
            sum_capital[i]=sum_capital[i-1];
            sum_normal+=c[i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        int j,k;
        if(i==1)
        {
            j=n;
            k=2;
        }
        if(i==n)
        {
            j=n-1;
            k=1;
        }
        if((i>1)&&(i<n))
        {
            j=i-1;
            k=i+1;
        }
        if(iscapital[i])
        {
            ans+=c[i]*c[k];
            ans+=(sum_normal)*c[i];
            ans+=sum_capital[j]*c[i];
            ans-=c[i]*c[j];
            if(!iscapital[k])
            {
                ans-=c[i]*c[k];
            }

        }
        else
        {
            ans+=c[i]*c[k];
        }
    }
    //cout<<ans<<endl;

    //cout<<ans<<endl;

    cout<<ans;
    return 0;
}
