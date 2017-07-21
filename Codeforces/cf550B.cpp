#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int r,l,n,x;
int c[20],mark[20],num=0;
void dfs(int x,int sum,int xiao,int da)
{
    if((sum>=l)&&(sum<=r)&&(c[da]-c[xiao]>=x))
    {
        mark[x]=1;
        num++;
    }
    for(int i=x+1;i<=n;i++)
        if(!mark[i]&&(sum+c[i]>=l)&&(sum+c[i]<=r)&&(c[i]-c[xiao]>=x))
           {
               dfs(i,sum+c[i],xiao,da);
               mark[i]=0;
               sum-=
           }


}
int main(void)
{
    scanf("%d%d%d%d",&n,&l,&r,&x);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);//从1开始建立索引
    memset(mark,0,sizeof(mark));
    sort(c+1,c+n+1);
    dfs(1,c[1],1,1);
    printf("%d",num);
    return 0;
}
