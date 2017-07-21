#include<bits/stdc++.h>
using namespace std;
int s,t,n,m,k,d[10000+10][11];
const int INF=INT_MAX/2-10;
typedef pair<int,int> pii;
vector<pii> G[10000+10];
bool visit[10000+10][11];
struct Node
{
    int id;
    int level;
    int dis;
    Node(int id,int level,int dis):id(id),level(level),dis(dis)
    {

    }
    bool operator <(const Node& X)const
    {
        return dis>X.dis;
    }
};
priority_queue<Node> pq;
int main(void)
{
    int a,b,c;
    cin>>n>>m>>k;
    cin>>s>>t;
    for(int i=0;i<n;i++)
        G[i].clear();
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }
    memset(visit,0,sizeof(visit));
    for(int i=0;i<n;i++)
        for(int j=0;j<=k;j++)
            d[i][j]=INF;
   // visit[s][0]=true;
    d[s][0]=0;//start from s,the zero level
    pq.push(Node(s,0,0));
    while(!pq.empty())
    {
        Node X=pq.top();
        pq.pop();
        int x=X.id;
        int lv=X.level;
        if(visit[x][lv]==true)
            continue;
        else
        {
            visit[x][lv]=true;
            vector<pii>::iterator it;
            for(it=G[x].begin();it!=G[x].end();it++)
            {
                int y=(*it).first;
                int u=(*it).second;
                //the same level
                if(u+d[x][lv]<d[y][lv])
                {

                    d[y][lv]=u+d[x][lv];
                    pq.push(Node(y,lv,d[y][lv]));
                }
                //the +1 level
                if(lv<k)
                    if(d[x][lv]<d[y][lv+1])
                    {
                        d[y][lv+1]=d[x][lv];
                        pq.push(Node(y,lv+1,d[y][lv+1]));
                    }
            }
        }
    }
    int ans=d[t][0];
    for(int i=0;i<=k;i++)
    {
        ans=min(ans,d[t][i]);
    }
    cout<<ans<<endl;
    return 0;
}
