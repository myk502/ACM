#include<cstdio>
#include<cstring>
#include<iostream>
#include<climits>
#include<cmath>
#include<algorithm>
#include<ctype.h>
using namespace std;
int s[20],a[]={1,4,7,1,2,3,1,3},b[]={3,6,9,7,8,9,9,7},c[]={2,5,8,4,5,6,5,5},visit[10];
int k,t,status;
int xunzhao(int x,int y,int z)
{
    int temp=0,length=k,you=0;
    for(int i=1;i<k;i++)
    {
        if((s[i]==x)&&(s[i+1]==y))
        {
            you=0;
            for(int j=1;j<i;j++)
                if(s[j]==z)
                    you=1;
            if(you==0)
                temp=1;
        }
    }
    return temp;
}
int zhixian(void)
{
    int temp=1;
    for(int i=0;i<8;i++)
    {
        if((xunzhao(a[i],b[i],c[i]))||(xunzhao(b[i],a[i],c[i])))
        {
            temp=0;
        }

    }
    return temp;
}
int main(void)
{
    freopen("in.txt","r",stdin);
    freopen("out_wrong.txt","w",stdout);
    cin>>t;
    while(t--)
    {
        scanf("%d",&k);
        memset(visit,0,sizeof(visit));
        status=1;
        for(int i=1;i<=k;i++)
        {
            scanf("%d",&s[i]);

            if((s[i]>=1)&&(s[i]<=9))
                visit[s[i]]++;
            else
            {
                status=0;
                continue;//´íÎó1
            }
        }

        if(k<4)
            status=0;
        for(int i=1;i<10;i++)
            if(visit[i]>1)
        {
            status=0;
            break;
        }
        if(!zhixian())
            status=0;
        //printf("xunzhao(1,3,2)=%d\n",xunzhao(1,3,2));
        if(status)
            printf("valid\n");
        else
            printf("invalid\n");
    }
    return 0;
}
