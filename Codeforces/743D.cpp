#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10;
const long long INF=10000000000000000;
long long ans,max1,max2;
int n;
vector<int> G[maxn],B[maxn];
long long value[maxn],sum[maxn],dp[maxn];
void dfs1(int x)//calculate the sum of the subtree of x
{
    sum[x]=value[x];
    for(auto it:G[x])
    {
        dfs1(it);
        sum[x]+=sum[it];
    }
}
void dfs2(int x)//calculate the largest sum of sub-trees of x
{
    dp[x]=sum[x];
    for(auto it:G[x])
    {
        dfs2(it);
        dp[x]=max(dp[x],dp[it]);
    }
}
void doit(long long &max1,long long &max2,long long x)//update max1 and max2
{
    if(x<=max2)
        return ;
    if(x>=max1)
    {
        max2=max1;
        max1=x;
        return ;
    }
    {
        max2=x;
        return ;
    }
}
void dfs(int x,int fa)//瞎几把遍历
{
    for(auto i:B[x])
    {
        if(i==fa)
            continue;
        G[x].push_back(i);
        dfs(i,x);
    }
}
int main(void)
{
    int u,v;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>value[i];
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        B[u].push_back(v);
        B[v].push_back(u);
    }//读入，暂时存着，因为给的节点关系是无序的，需要经过预处理，使得其有序
    dfs(1,-1);//to ensure the father and child relation:G[u]=v then v is child of u
    dfs1(1);
    dfs2(1);
    ans=-INF;
    for(int i=1;i<=n;i++)
    {
        if(G[i].size()>=2)
        {
            max1=max(dp[G[i][0]],dp[G[i][1]]);//the largest
            max2=min(dp[G[i][0]],dp[G[i][1]]);//the second largest
            for(int j=2;j<G[i].size();j++)
            {
                doit(max1,max2,dp[G[i][j]]);
            }
            ans=max(ans,max1+max2);
        }
        else
            continue;
    }
    if(ans==-INF)
        cout<<"Impossible";
    else
        cout<<ans;
    return 0;
}
