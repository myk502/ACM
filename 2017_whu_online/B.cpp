#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10;
const int Mod=1e7+9;
int n,m,xx,yy,ans;
vector <int> G[maxn];
int father[maxn];
bool reachable[maxn][25];//whether the i-th node could be classified into the j-th group
int dp[maxn][25];//memorization search
void init(void)
{
    ans=0;
    memset(father,-1,sizeof(father));//compared with visit,father is more efficient
    memset(dp,-1,sizeof(dp));//important!
    for(int i=1;i<=n;i++)
        G[i].clear();
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d%d",&xx,&yy);
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&xx);
            if(xx==1)
                reachable[i][j]=true;
            else
                reachable[i][j]=false;
        }
    }
}
int  dfs(int i,int k)//The number of solutions in which you paint color j on Node i
{
    long long product=1LL;
    if(dp[i][k]!=-1)//to avoid duplicate search
        return dp[i][k];
    if(reachable[i][k]==0)//can not choose this color for Node i
        return 0;
    for(auto j:G[i])//traverse the son of i
    {
        int cnt=0;
        if(j==father[i])//ensure we don't go back to i's father
            continue;
        father[j]=i;
        for(int kk=1;kk<=m;kk++)//for every color
        {
            if((kk==k))
                continue;
            if(dp[j][kk]==-1)
                dp[j][kk]=dfs(j,kk);
            cnt=(cnt+dp[j][kk])%Mod;
        }
        product=(product*(long long)cnt)%Mod;

    }
    return (int)product;
}
int main(void)//dp on tree
{
    while(cin>>n>>m)
    {
        init();
        if(m==1)
        {
            cout<<0<<endl;
            continue;
        }
        for(int j=1;j<=m;j++)//enumerate the color of Node 1;consider Node 1 to be the root
        {
            if(reachable[1][j]==0)//can not choose this color
                continue;
            dp[1][j]=dfs(1,j);
            ans=(ans+dp[1][j])%Mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
