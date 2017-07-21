#include<bits/stdc++.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=50000+10;
int sum[maxn<<2];
int n;
void PushUp(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&sum[rt]);
        //printf("We are building the node %d.\n",l);
        return ;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    PushUp(rt);
}

void update(int p,int add,int l,int r,int rt)
{
    if(l==r)
    {
        sum[rt]+=add;
        return ;
    }
    int m=(l+r)>>1;
    if(p<=m)
        update(p,add,lson);
    else
        update(p,add,rson);
    PushUp(rt);
}

int query(int L,int R,int l,int r,int rt)
{
    if(L<=l && R>=r)
        return sum[rt];
    int rnt=0,m=(l+r)>>1;
    if(m>=L)
        rnt+=query(L,R,lson);
    if(R>m)
        rnt+=query(L,R,rson);
    return rnt;
}

int main(void)
{
    char order[20];
    int T,num1,num2,ans;
    cin>>T;
    for(int ii=1;ii<=T;ii++)
    {
        printf("Case %d:\n",ii);
        memset(sum,0,sizeof(sum));
        scanf("%d",&n);
        build(1,n,1);
        while(scanf("%s",order))
        {
            if(order[0]=='E')
                break;
            if(order[0]=='Q')
            {
                scanf("%d%d",&num1,&num2);
                ans=query(num1,num2,1,n,1);
                printf("%d\n",ans);
            }
            if(order[0]=='A')
            {
                scanf("%d%d",&num1,&num2);
                update(num1,num2,1,n,1);
            }
            if(order[0]=='S')
            {
                scanf("%d%d",&num1,&num2);
                update(num1,-num2,1,n,1);
            }

        }
    }
    return 0;
}
