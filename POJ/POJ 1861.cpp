#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<climits>
#include<cmath>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
int n,m,cnt,visit[1010];//cnt to count the index of edges(when adding edges)
struct Edge
{
    int from;
    int to;
    int cost;
};
Edge a[30000+10];
void add_edge(int u,int v,int w)
{
    a[cnt].to=v;
    a[cnt].cost=w;
    a[cnt].from=u;
}
bool cmp(Edge xx,Edge yy)
{
    return (xx.cost<yy.cost);
}
typedef pair<int,int> pii;
vector<pii> ANS;
int main(void)
{
    while(cin>>n>>m)
    {
        //cin>>n>>m;
        cnt=0;
        int ans_max=-1,cntt=0;//cntt to count the number of edges added to the set(prime)
        int u,v,w;
        memset(visit,0,sizeof(visit));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
            add_edge(v,u,w);
        }
        visit[1]=1;
        sort(a,a+2*m,cmp);
        ANS.clear();
        for(int ii=0;ii<2*m;ii++)
        {
            if(cntt>=n-1)
                break;
            int uu=a[ii].from,vv=a[ii].to,ww=a[ii].cost;
            //printf("uu=%d and vv=%d\n",uu,vv);
            if(visit[uu]+visit[vv]!=1)
                continue;
            else
            {
                cntt++;
                visit[uu]=visit[vv]=1;
                ans_max=max(ans_max,ww);
                ANS.push_back(make_pair(uu,vv));
            }
        }
        cout<<ans_max<<endl;
        printf("%d\n",n-1);
        vector<pii>::iterator it;
        for(it=ANS.begin();it!=ANS.end();it++)
        {
            pii temp=*it;
            printf("%d %d\n",min(temp.first,temp.second),max(temp.first,temp.second));
        }
    }
    return 0;
}
