#include<bits/stdc++.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=100000+10;
int n,q,sum[maxn<<2],lazy[maxn<<2];
void PushUp(int rt)//向上更新,从两个孩子更新
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void PushDown(int rt,int num)//rt is the root,num is the number of elements in this node
{
    if(lazy[rt])//if the Node rt has a lazy mark
    {
        lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];//push down the lazy mark
        sum[rt<<1|1]=(num>>1)*lazy[rt];//because this lazy mark is a change
        //not an increment,so we simply need to change the sum[]
        sum[rt<<1]=(num-(num>>1))*lazy[rt];
        lazy[rt]=0;//clear the lazy mark
    }
}
void build(int l,int r,int rt)
{
    lazy[rt]=0;
    if(l==r)
    {
        sum[rt]=1;
        return ;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update(int L,int R,int value,int l,int r,int rt)
//change the elements of [L,R] to value
{
    if(l>=L && R>=r)
    {
        sum[rt]=(r-l+1)*value;
        lazy[rt]=value;
        return ;
    }
    int m=(l+r)>>1;
    //because now we need to split the interval,we have to push down the lazy
    //mark
    PushDown(rt,r-l+1);
    if(L<=m)
        update(L,R,value,lson);
    if(R>m)
        update(L,R,value,rson);
    PushUp(rt);

}
int main(void)
{
    //freopen("in","r",stdin);
    int aa,bb,cc;
    int T;
    cin>>T;
    for(int ii=1;ii<=T;ii++)
    {
        cin>>n>>q;
        build(1,n,1);
        while(q--)
        {
            //printf("q=%d\n",q);
            scanf("%d%d%d",&aa,&bb,&cc);
            update(aa,bb,cc,1,n,1);
        }
        printf("Case %d: The total value of the hook is %d.\n",ii,sum[1]);
    }
    return 0;
}
