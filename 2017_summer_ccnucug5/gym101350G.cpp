#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=55;
#define sa(x) scanf("%d",&x)
#define pr(x) printf("%d\n",x)
#define de(x) cout<<#x<<" = "<<x<<endl;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
//--------------------------------------//
ll x[N],y[N];
ll n,m;
int k;
ll solve() {
    ll x1,x2,y1,y2,ans=0;
    for(int i=1;i<(1<<k);++i) {
        ll bits=0;
        ll res=1ll;
        for(int j=0;j<k;++j) {
            if((1<<j)&i) {
                if(!bits) x1=x2=x[j],y1=y2=y[j];
                else {
                    x1=min(x1,x[j]);
                    y1=min(y1,y[j]);
                    x2=max(x2,x[j]);
                    y2=max(y2,y[j]);
                }
                ++bits;
            }
        }
        ll t=x1*(n-x2+1)*y1*(m-y2+1);
        if(bits&1) ans+=t;
        else ans-=t;
    }

    return ans;
}
int main() {
    int T;sa(T);
    while(T--) {
        scanf("%I64d%I64d%d",&n,&m,&k);
        for(int i=0;i<k;++i) scanf("%I64d%I64d",&x[i],&y[i]);
        ll ans=(1ll+n)*n*(1ll+m)*m/4ll-solve();
        printf("%I64d\n",ans);
    }

    return 0;
}
