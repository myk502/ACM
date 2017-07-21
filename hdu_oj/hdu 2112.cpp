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
map <string,int> a;
char input[35];
int n,s,e,index_map,done[160],d[160],b[160][160];
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> >pq;
int GetNum(void)
{
    scanf("%s",input);
    if(a.count(input)==0)
    {
        a[input]=++index_map;
    }
    return(a[input]);
}
int main(void)
{

    int u,v,w;
    while(cin>>n)
    {
        if(n==-1)
            break;
        a.clear();
        index_map=0;
        s=GetNum();
        e=GetNum();
        for(int i=1;i<=150;i++)
            for(int j=1;j<=150;j++)
        {
            b[i][j]=150000;
            if(i==j)
                b[i][j]=0;
            d[i]=150000;
        }
        memset(done,0,sizeof(done));
        for(int ii=0;ii<n;ii++)
        {
            u=GetNum();
            v=GetNum();
            cin>>w;
            b[u][v]=b[v][u]=w;
        }
        while(!pq.empty())
            pq.pop();
        d[s]=0;
        pq.push(make_pair(d[s],s));

        while(!pq.empty())
        {
            pii u=pq.top();
            pq.pop();
            int x=u.second;
            if(done[x])
                continue;
            else
            {
                done[x]=1;
                for(int i=1;i<=index_map;i++)
                {
                    if(b[x][i]+d[x]<d[i])
                    {
                        d[i]=b[x][i]+d[x];

                        pq.push(make_pair(d[i],i));
                    }
                }
            }
        }
        if(d[e]==150000)
            printf("-1\n");
        else
            printf("%d\n",d[e]);

    }
    return 0;
}
