
#include<bits/stdc++.h>
using namespace std;
const int MAXN=100001;
int n;
int a[MAXN];
int b[MAXN],c[MAXN],d[MAXN];
bool vis[MAXN];
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        memset(vis,0,sizeof(vis));
        for (int i=0;i<n;i++)
        {
            int t=a[i],j=0,m=0;
            while (t>0)
            {
                d[m]=t;
                m++;
                vis[t]=1;
                c[t]++;
                b[t]+=j;
                int k1=t*2,k2=j+1;
                while (k1<MAXN)
                {
                    if (vis[k1]) break;
                    d[m]=k1;
                    m++;
                    vis[k1]=1;
                    c[k1]++;
                    b[k1]+=k2;
                    k2++;
                    k1*=2;
                }
                j++;
                t/=2;
            }
            for (j=0;j<m;j++) vis[d[j]]=0;
        }
        int ans=b[1];
        for (int i=1;i<MAXN;i++)
        {
            if (c[i]>=n){
                while (c[i]>n){}
                ans=min(ans,b[i]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
