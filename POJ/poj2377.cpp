#include<stdio.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#include<ctype.h>
#include<algorithm>
using namespace std;
int a[1010][1010],m,n,father[1010];
struct Edge{
int from;
int to;
int cost;};
Edge b[20000+10];//边集数组存储
#define zuida 100000000//不知道能不能过卡数据肯定爆炸
bool cmp(Edge a,Edge b)
{
    return(a.cost>b.cost);
}
int find_ancestor(int x)
{
    int r=x;
    while(father[r]!=r)
    {
        r=father[r];
    }
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
    int temp_a,temp_b,temp_c,liantong=1,cnt,total,max_cost,max_i,max_j;
    int cntt=0,num=0;//num表示目前存储了多少条边
    Edge temp;//用来暂时存储边
    cnt=total=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        a[i][j]=-1;//因为是最大生成树，所以Kruskal算法找的是最长边，赋初值为-1
        a[i][i]=0;
        father[i]=i;
    }
    while(m--)//注意以后不能用到m了！！！这里很坑爹
    {
        scanf("%d%d%d",&temp_a,&temp_b,&temp_c);
        if(temp_c>a[temp_a][temp_b])
        {
            temp.from=temp_a;
            temp.to=temp_b;
            temp.cost=temp_c;
            b[num++]=temp;//到最后num会等于边的条数，但是只有0到num-1存有边
        //如果题目边重复出现就会有bug要注意
        //保留a数组的目的是剔除重复边（取最大值）
        }
        a[temp_a][temp_b]=max(a[temp_a][temp_b],temp_c);//最大生成树，找最长边
        a[temp_b][temp_a]=a[temp_a][temp_b];
        add_bian(temp_a,temp_b);
        //为了检测图的连通性，首先将所有边全部加入并查集
    }
    int temp_father=find_ancestor(1);//第一个元素的father
    for(int i=1;i<=n;i++)
        if(find_ancestor(i)!=temp_father)
            liantong=0;
    if(liantong==0)
        printf("-1");
    else
    {
        for(int i=1;i<=n;i++)
            father[i]=i;//再一次初始化father用于之后Kruskal算法
        sort(b,b+num,cmp);//把边集数组排序
        while(cnt<n-1)
        {
            max_i=b[cntt].from;
            max_j=b[cntt].to;
            cntt++;//自增运算符一定要谨慎使用
            if(find_ancestor(max_i)!=find_ancestor(max_j))
            {
                add_bian(max_i,max_j);
                cnt++;
                total+=a[max_i][max_j];
                //printf("%d to %d\n",max_i,max_j);
            }
        }
        printf("%d",total);
    }
    return 0;
}
