#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<set>
using namespace std;
int a[5010][5010];
set <int> hang;
set <int> lie;
set<int>::iterator it;
int m,n,k,zuizhonghang[5010],zuizhonglie[5010];
void paint(int x,int i,int j)
{
    if(x==1)
    {
        hang.insert(i);
        for(it=lie.begin();it!=lie.end();it++)
        {
            a[i][*it]=j;
        }
        zuizhonghang[i]=j;
    }
    if(x==2)
    {
        lie.insert(i);
        for(it=hang.begin();it!=hang.end();it++)
        {
            a[*it][i]=j;
        }
        zuizhonglie[i]=j;
    }
}
int main(void)
{
    int aa,b,c;
    scanf("%d%d%d",&n,&m,&k);
    memset(a,0,sizeof(a));
    //memset(status_hang,0,sizeof(status_hang));
    //memset(status_lie,0,sizeof(status_lie));
    hang.clear();
    lie.clear();
    for(int i=0;i<k;i++)
    {
        scanf("%d%d%d",&aa,&b,&c);
        paint(aa,b,c);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]!=0)
            {
                printf("%d ",a[i][j]);
            }
            else
           {
               a[i][j]=max(zuizhonghang[i],zuizhonglie[j]);
               printf("%d ",a[i][j]);
           }


        }
        printf("\n");
    }
    return 0;
}
