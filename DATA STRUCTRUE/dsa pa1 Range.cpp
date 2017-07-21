#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define zuida 10000000
int a[zuida+10],b[zuida+10];//a用来存储哪些点有，b用来存储从1到i有的点的总数
int main(void)
{
    int l,r,m,n,temp;
    memset(b,0,sizeof(b));
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        a[temp]=1;
    }
    b[0]=(a[0]==1)?1:0;
    for(int i=1;i<=zuida;i++)
    {
        if(a[i]==1)
            b[i]=1+b[i-1];
        else
            b[i]=b[i-1];
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&l,&r);
        printf("%d\n",b[r]-b[l]+a[l]);
    }
    return 0;

}
