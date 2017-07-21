#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
#include<math.h>
using namespace std;
int a[110][110],b[110][110];
const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
int mianji=0,zhouchang=0,n;
bool panduanbianjie(int a,int b)
{
    if((a==n)||(b==n)||(a==1)||(b==1))//从1到n存储
        return true;
    else
        return false;
}
bool panduan(int aa,int bb)
{
    if(panduanbianjie(aa,bb))
        return true;
    int num=0,xx,yy;//四周非肿瘤点的个数
    for(int i=0;i<4;i++)
    {
        xx=aa+dx[i];
        yy=bb+dy[i];
        if(b[xx][yy]==0)
            num++;
    }
    if(num==0)
        return false;
    else
        return true;

}
int main(void)
{
    scanf("%d",&n);
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        scanf("%d",&a[i][j]);
        if(a[i][j]<=50)
        {
            b[i][j]=1;//1代表在肿瘤上
            mianji++;
        }
        else
            b[i][j]=0;
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        if((panduan(i,j))&&b[i][j])
            zhouchang++;
    }
    printf("%d %d",mianji,zhouchang);
    return 0;
}
