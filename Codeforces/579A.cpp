#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct myk{
int x;
int number;
int y;};
myk b[320000];
int temp,n,i,j,num=0,num_b,c[410],temp_x,temp_y,num_caozuo=0,status[410];
bool cmp(myk a,myk b)
{
    return(a.number>b.number);
}
void caozuo(int temp_x,int temp_y)
{
    c[temp_x]=temp_y;
    c[temp_y]=temp_x;
    status[temp_x]=status[temp_y]=1;
    num_caozuo+=2;
}
int main(void)
{
    scanf("%d",&n);
    for(i=2;i<=2*n;i++)
        for(j=1;j<i;j++)
    {
        if(scanf("%d",&temp)!=EOF)
        {
            b[++num].number=temp;
            b[num].x=i;
            b[num].y=j;
        }


    }
    sort(b+1,b+num+1,cmp);
    num_b=num;
    num=1;
    memset(status,0,sizeof(status));
    while((num_caozuo<2*n-2)&&(num<=num_b))
    {
        temp_x=b[num].x;
        temp_y=b[num].y;
        if((status[temp_x]==0)&&(status[temp_y]==0))
            caozuo(temp_x,temp_y);
        num++;
    }
    for(i=1;i<=2*n;i++)
    {
        if(status[i]==0)
        {
            temp_x=i;
            status[i]=1;
            break;
        }
    }
    for(i=1;i<=2*n;i++)
    {
        if(status[i]==0)
        {
            temp_y=i;
            status[i]=1;
            break;
        }
    }
    caozuo(temp_x,temp_y);
    for(i=1;i<=2*n;i++)
        printf("%d ",c[i]);
    return 0;
}
