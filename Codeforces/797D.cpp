#include<bits/stdc++.h>
using namespace std;
set<int> s;
int n;
const int maxn=100000+10;
struct BinNode
{
    int value,lchild,rchild;
    int L=0,R=1e9;
    bool isEligible(void)
    {
        return (value>=L) && (value<=R);
    }
    void setInterval(int xx,int yy)
    {
        L=xx;
        R=yy;
    }
};
BinNode P[maxn];
int cnt[maxn],root,ans=0;//ans is the number of Nodes can not be found
int find_root(void)
{
    int xx,yy;
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++)
    {
        xx=P[i].lchild;
        yy=P[i].rchild;
        if(xx!=-1)
            cnt[xx]++;
        if(yy!=-1)
            cnt[yy]++;
    }
    for(int i=1;i<=n;i++)
        if(cnt[i]==0)
            return i;
    return -1;//I think this will never happen
}
void dfs(int id,int mode)
{
    int ll,rr,L,R,x;
    if(id==-1)
        return;//There is no such Node
    ll=P[id].lchild;
    rr=P[id].rchild;
    L=P[id].L;
    R=P[id].R;
    x=P[id].value;
    if(mode==0)//The first dfs,we just insesrt value that can be searched to the set
    {
        if(P[id].isEligible())
            s.insert(x);
    }
    else
    {
        if(!P[id].isEligible() && (s.count(x)==0))
            ans++;
    }

    if(ll!=-1)//if LChild exists,then first update its interval, then dfs it
    {
        P[ll].setInterval(L,min(R,x-1));
        dfs(ll,mode);
    }
    if(rr!=-1)
    {
        P[rr].setInterval(max(L,x+1),R);
        dfs(rr,mode);
    }
}
        
int main(void)
{
    int aa,bb,cc;
    s.clear();
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&aa,&bb,&cc);
        P[i].value=aa;
        P[i].lchild=bb;
        P[i].rchild=cc;
    }
    root=find_root();
    dfs(root,0);
    dfs(root,1);
    cout<<ans<<endl;
    return 0;
}
