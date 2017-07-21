#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
using namespace std;
int ans,m,n,a[1010][1010],indegree[1010];
queue <int> q;
void kahn(void)
{
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int j=1;j<=n;j++)
        {
            if(a[x][j]==1)
            {
                a[x][j]=0;
                indegree[j]--;
                int status=0;
                if(indegree[j]==0)
                {
                    q.push(j);
                    status=1;
                }
                if(status==1)
                    ans++;
            }
        }
    }
}
int main(void)
{
    int tempa,tempb,tempc;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        while(!q.empty())
            q.pop();
        ans=0;
        memset(a,0,sizeof(a));
        memset(indegree,0,sizeof(indegree));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&tempa,&tempb,&tempc);
            if((tempc==-1)&&(a[tempa][tempb]!=1))
            {
                a[tempa][tempb]=1;
                indegree[tempb]++;
            }
            if((tempc==1)&&(a[tempb][tempa]!=1))
            {
                a[tempb][tempa]=1;
                indegree[tempa]++;
            }
        }
        for(int i=1;i<=n;i++)
            if(indegree[i]==0)
                q.push(i);
        kahn();
        printf("%d\n",ans);
    }
    return 0;
}
