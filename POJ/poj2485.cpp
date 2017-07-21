#include<stdio.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;

int n,father[510];
int a[510][510];
int find_ancestor(int x)
{
    int r=x;
    while(father[r]!=r)
        r=father[r];//此时r为根节点
    int i=x,j;
    while(i!=r)
    {
        j=father[i];
        father[i]=r;
        i=j;
    }
    return r;//路径压缩，把所有的x的父节点的父节点都设置为祖先
}
void add_bian(int x,int y)
{
    int fx=find_ancestor(x),fy=find_ancestor(y);
    if(fx!=fy)
        father[min(fx,fy)]=max(fx,fy);
}
int main(void)
{
    int total,t,cnt,min_cost,min_i,min_j;
    scanf("%d",&t);
    while(t--)
    {
        total=cnt=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            father[i]=i;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
        while(cnt<n-1)
        {
            min_cost=INT_MAX;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
            {
                if(i==j)
                    continue;

                if((a[i][j]<min_cost)&&(find_ancestor(i)!=find_ancestor(j)))
                {

                    min_i=i;
                    min_j=j;
                    min_cost=a[i][j];
                }
            }

            add_bian(min_i,min_j);
            cnt++;
            total=max(total,a[min_i][min_j]);
        }
        printf("%d\n",total);
    }
    return 0;
    return 0;
}
