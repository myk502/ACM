#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define zuida 100000
int a[zuida+10],b[zuida+10],father[zuida+10],status[zuida+10];
int m,n,tempa,tempb,num;
int main(void)
{
    int num=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d%d",&tempa,&tempb);
        father[max(tempa,tempb)]=min(tempa,tempb);
    }

    b[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(b[father[i]]>m)
            b[i]=m+1;
        else
        {
            if(a[i]==0)
            {
                b[i]=0;
            }
            else
            {
                if(a[father[i]]==0)
                    b[i]=1;
                else
                    b[i]=1+b[father[i]];
            }
        }

    }
    memset(status,1,sizeof(status));
    for(int i=2;i<=n;i++)
    {
        status[father[i]]=0;
    }
    for(int i=2;i<=n;i++)
    {
        if((status[i])&&(b[i]<=m))
            num++;
    }
    printf("%d",num);
    return 0;
}
