#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;
int a[5010][5010];
struct myk{
int num;
int bianhao;};
int m,n,k;
myk zuizhonghang[5010],zuizhonglie[5010];
void paint(int cixu,int x,int i,int j)
{
    if(x==1)
    {
        zuizhonghang[i].num=j;
        zuizhonghang[i].bianhao=cixu;
    }
    if(x==2)
    {

        zuizhonglie[i].num=j;
        zuizhonglie[i].bianhao=cixu;
    }
}
int main(void)
{
    int aa,b,c;
    scanf("%d%d%d",&n,&m,&k);
    memset(a,0,sizeof(a));
    for(int i=1;i<=5000;i++)
    {
        zuizhonghang[i].bianhao=0;
        zuizhonglie[i].bianhao=0;
    }
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d%d",&aa,&b,&c);
        paint(i,aa,b,c);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if((zuizhonghang[i].bianhao==0)&&(zuizhonglie[j].bianhao==0))
                a[i][j]=0;
            else
                a[i][j]=(zuizhonghang[i].bianhao>zuizhonglie[j].bianhao)?zuizhonghang[i].num:zuizhonglie[j].num;
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
