#include<bits/stdc++.h>
using namespace std;
int n,m;
int color[5010];//染色的颜色，-1为初始值，0 1为染色的颜色
int a[5010][5010];//邻接矩阵存图
vector <int> G[5010];//vector模拟邻接表，存储补图
bool is_ac[5010];//判断这个点是否为B
bool colored[5010];//代表这个点是否拓展过了（是否从这个点出发前往它的相邻点了）
bool ans=true;//初始化可以成功
void paint(int i,int x)//将节点i染成x颜色
{
    if((color[i]!=-1)&&(color[i]!=x))//如果i已经有了颜色，而且不是x
    {
        ans=false;//肯定失败
    }
    color[i]=x;
    if(colored[i]==true)
        return ;//如果已经拓展过不用重复拓展
    colored[i]=true;//设置已经拓展的tag
    for(auto j:G[i])
        paint(j,1-x);//dfs


}
int main(void)
{

    int u,v;
    cin>>n>>m;
    memset(color,-1,sizeof(color));//颜色全部初始化
    memset(a,-1,sizeof(a));
    memset(is_ac,0,sizeof(is_ac));//都初始化为是B
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
            if(a[i][j]==-1)//求补图
            {
                G[i].push_back(j);
                is_ac[i]=is_ac[j]=true;//这些点不会是B，是a或者C
            }
        }
    }
    for(int i=1;i<=n;i++)//对所有连通域进行染色
    {
        if(is_ac[i]==false)//是B的话直接不用考虑
            continue;
        int temp_color=color[i];
        if(temp_color==-1)//要是这个点的颜色还是初始的-1的话
            temp_color=0;
        if(colored[i]==false)//如果这个点还没有拓展过/处于不同的连通域
            paint(i,temp_color);
    }
    if(ans)//如果染色完毕，答案为true
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
        {
            if((a[i][j]==1)&&(color[i]+color[j]==1))//对第一个条件检查
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
