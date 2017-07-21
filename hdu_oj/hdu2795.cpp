#include <bits/stdc++.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=200000+10;
int tree[maxn<<2],h,w,n,width[maxn];
void PushUp(int rt)
{
    tree[rt]=max(tree[rt<<1],tree[rt<<1|1]);
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]=w;
        return ;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}
int query(int x,int l,int r,int rt)//make sure every query,tree[rt] is no less than x
{
//recursion basis
    if(l==r)
        return l;
    int m=(l+r)>>1;
    if(tree[rt<<1]>=x)//go to lchild
        return query(x,lson);
    else
        return query(x,rson);
}
void update(int p,int add,int l,int r,int rt)
{
    if(l==r)
    {
        tree[rt]+=add;
        return ;
    }
    int m=(l+r)>>1;
    if(p<=m)
        update(p,add,lson);
    else
        update(p,add,rson);
    PushUp(rt);
}
int main(void)
{
    int ans;
    while(cin>>h>>w>>n)
    {
        build(1,n,1);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&width[i]);
            if(width[i]>tree[1])//it is impossible to put up the poster
                printf("-1\n");
            else
            {
                ans=query(width[i],1,n,1);
                if(ans<=h)
                {
                    printf("%d\n",ans);
                    update(ans,-width[i],1,n,1);
                }
                else
                    printf("-1\n");
            }


        }
    }
    return 0;
}
