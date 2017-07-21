#include<bits/stdc++.h>
using namespace std;
int n,m;
int color[5010];
int a[5010][5010];
vector <int> G[5010];
bool is_ac[5010];
bool colored[5010];//if i is in the set,means that it has been spread(we have started from i)
bool ans=true;
void paint(int i,int x)//paint Node i with color x
{
    if((color[i]!=-1)&&(color[i]!=x))
    {
        ans=false;
    }
    color[i]=x;
    if(colored[i]==true)
        return ;
    colored[i]=true;
    for(auto j:G[i])
        paint(j,1-x);


}
int main(void)
{

    int u,v;
    cin>>n>>m;
    memset(color,-1,sizeof(color));//init
    memset(a,-1,sizeof(a));
    memset(is_ac,0,sizeof(is_ac));
    memset(colored,0,sizeof(colored));
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        a[u][v]=a[v][u]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
                continue;
            if(a[i][j]==-1)
            {
                G[i].push_back(j);
                is_ac[i]=is_ac[j]=true;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(is_ac[i]==false)
            continue;
        int temp_color=color[i];
        if(temp_color==-1)
            temp_color=0;
        if(colored[i]==false)
            paint(i,temp_color);
    }
    if(ans)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
        {
            if((a[i][j]==1)&&(color[i]+color[j]==1))
                ans=false;
        }
    }
    if(ans)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    if(ans)
    {
        for(int i=1;i<=n;i++)
        {
            if(is_ac[i]==false)
                cout<<"b";
            else if(color[i])
                cout<<"a";
            else
                cout<<"c";
        }
    }
    return 0;
}
