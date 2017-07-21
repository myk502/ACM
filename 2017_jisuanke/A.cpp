#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<climits>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int n,k;
const int maxn=200000+10;
int h[maxn],sum[maxn];
int tree[maxn<<2];
struct Point
{
    int x,y;
    Point(int xx=0,int yy=0):x(xx),y(yy)
    {

    }
};
vector<int> G[200000+10];
Point P[2000+10];
void PushUp(int rt)
{
    tree[rt]=min(tree[rt<<1],tree[rt<<1|1]);
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&tree[rt]);
        h[l]=tree[rt];
        return ;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if((L<=l)&&(r<=R))
        return tree[rt];
    int m=(l+r)>>1;
    int ans=INT_MAX;
    if(L<=m)
        ans=min(ans,query(L,R,lson));
    if(R>m)
        ans=min(ans,query(L,R,rson));
    return ans;
}
int dis(Point A,Point B)
{
    int ll,rr,hmin,h1,h2,ans;
    ll=min(A.x,B.x);
    rr=max(A.x,B.x);
    h1=A.y;
    h2=B.y;
    ans=abs(ll-rr)+abs(h1-h2);
    hmin=query(ll,rr,1,n,1);
    if(hmin<min(h1,h2))
    {
        ans+=2*abs(hmin-min(h1,h2));
    }
    return ans;
}
int main(void)
{
    int xx,yy,mm,cnt=0;
    cin>>n>>k;
    build(1,n,1);
    sum[0]=0;
    cin>>mm;
    for(int i=1;i<=mm;i++)
    {
        scanf("%d%d",&xx,&yy);
        P[i].x=xx;
        P[i].y=yy;
        G[xx].push_back(yy);
    }
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+G[i].size();
    for(int i=1;i<=mm;i++)
    {
        int xxx=P[i].x;
        for(int j=xxx-k;j<=xxx-k+38;j++)
        {
            if((j<0)||(j>n))
                continue;
            for(auto it:G[j])
            {
                if((j==P[i].x)&&(it==P[i].y))
                    continue;
                if(dis(Point(j,it),P[i])<=k)
                    cnt++;
            }
        }
        if(k-38>0)
        {
            cnt+=sum[xxx+k-38]-sum[xxx-k+38]-G[xxx+k-38].size();
        }
    }
    cout<<cnt/2;
    return 0;
}
