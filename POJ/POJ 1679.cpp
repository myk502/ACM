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
int n,m,pre[110];
struct Edge
{
    int from;
    int to;
    int cost;

};
Edge a[10010];
int indexx;
int find_ancestor(int x)
{
    int r=x;
    while(pre[r]!=r)
    {
        r=pre[r];
    }
    int i=x,j;
    while(i!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
void join(int x,int y)
{
    int fx=find_ancestor(x);
    int fy=find_ancestor(y);
    if(fx!=fy)
        pre[fx]=fy;
}
bool cmp(Edge xx,Edge yy)
{
    return(xx.cost<yy.cost);
}
int main(void)
{
    int t,u,v,w,cnt,flag,ans;
    cin>>t;
    while(t--)
    {
        cnt=0;
        cin>>n>>m;
        flag=0;
        ans=0;
        for(int i=1;i<=n;i++)
            pre[i]=i;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            Edge input;
            input.from=u;
            input.to=v;
            input.cost=w;
            a[i]=input;
        }
        sort(a,a+m,cmp);
        indexx=0;
        while(cnt<n-1)
        {
            Edge temp=a[indexx];
            int uu=temp.from,vv=temp.to,ww=temp.cost;
            int fauu=find_ancestor(uu),favv=find_ancestor(vv);
            if(find_ancestor(uu)!=find_ancestor(vv))
            {
                for(int j=indexx+1;j<m;j++)
                {
                    Edge tempp=a[j];
                    int uuu=tempp.from,vvv=tempp.to,www=tempp.cost;
                    if(www!=ww)
                        break;
                    int fauuu=find_ancestor(uuu),favvv=find_ancestor(vvv);
                    if((fauu==fauuu)&&(favv==favvv))
                        flag=1;
                    if((fauu==favvv)&&(fauuu==favv))
                        flag=1;
                }
                cnt++;
                join(uu,vv);
                ans+=ww;
            }
            indexx++;
        }
        if(flag==1)
            printf("Not Unique!\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
