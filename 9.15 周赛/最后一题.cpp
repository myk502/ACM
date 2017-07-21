#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;
int t,n;
struct wolf
{
    int attack;
    int buff;
    int pre;
    int next;
};
struct temp
{
    int buff;
    int index;
};
wolf a[210];
temp b[210];
bool cmp(temp aa,temp bb)
{
    return(aa.buff>bb.buff);
}
int main(void)
{
    int cnt;
    cin>>t;
    for(int ii=1;ii<=t;ii++)
    {
        cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].attack);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].buff);
            b[i].index=i;
            b[i].buff=a[i].buff;
        }
        a[0].attack=a[0].buff=a[n+1].attack=a[n+1].buff=0;
        a[0].pre=-1;
        a[0].next=1;
        a[n+1].next=-1;
        a[n+1].pre=n;
        for(int i=1;i<=n;i++)
        {
            a[i].pre=i-1;
            a[i].next=i+1;
        }
        sort(b+1,b+1+n,cmp);
        /*
        for(int i=1;i<=n;i++)
            printf("%d ",b[i].buff);
        printf("\n");
        */
        for(int i=1;i<=n;i++)
        {
            int temp_index=b[i].index;
            cnt+=a[temp_index].attack+a[a[temp_index].pre].buff+a[a[temp_index].next].buff;
            //printf("a[%d].next=%d\n",temp_index,a[temp_index].next);
            a[a[temp_index].pre].next=a[temp_index].next;
            a[a[temp_index].next].pre=a[temp_index].pre;
            //printf("Now we are attacking Number %d and cnt is %d\n",temp_index,cnt);
        }
        printf("Case #%d: %d\n",ii,cnt);
    }
    return 0;
}
