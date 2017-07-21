#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<climits>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=300000+10;
int n,a[maxn];
vector<int> G[maxn];
vector<int> A,B;//A stores the Node whose value is max-1,B stores the Node
//whose value is max

int solve(int x,int m)
{
   if( (B.size()==1) &&  (x==B[0]) )//consider whether the answer is m
   {
       int cnt=0;
       for(auto i:G[x])
       {
           if(a[i]==m-1)
               cnt++;
       }
       if(cnt==A.size())
           return m;
   }
   {
       int cnt=0;
       for(auto i:G[x])
       {
           if(a[i]==m)
               cnt++;
       }
       if(a[x]==m)
           cnt++;
       if(cnt==B.size())
           return m+1;
   }
   return m+2;
}
        

int main(void)
{
    int u,v,maxn=INT_MIN,ans;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
       scanf("%d",&a[i]);
       if(a[i]>maxn)
           maxn=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==maxn-1)
            A.push_back(i);
        if(a[i]==maxn)
            B.push_back(i);
    }
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ans=maxn+2;
    for(int i=1;i<=n;i++)//i is the start point
        ans=min(ans,solve(i,maxn));
    cout<<ans<<endl;

    return 0;
}
