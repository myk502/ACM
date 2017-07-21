#include<cstdio>
#include<cstring>
#include<iostream>
#include<climits>
#include<cmath>
#include<algorithm>
#include<ctype.h>
using namespace std;
int visit[20],a[20];
bool panduan(int x,int y)
{

    if(x>y)
        swap(x,y);
    if((x==1)&&(y==3))
        return(visit[2]>0);
    if((x==4)&&(y==6))
        return(visit[5]>0);
    if((x==7)&&(y==9))
        return(visit[8]>0);
    if((x==1)&&(y==7))
        return(visit[4]>0);
    if((x==2)&&(y==8))
        return(visit[5]>0);
    if((x==3)&&(y==9))
        return(visit[6]>0);
    if((x==1)&&(y==9))
        return(visit[5]>0);
    if((x==3)&&(y==7))
        return(visit[5]>0);
    return 1;
}
int main(void)
{
    int status,t,n;
    cin>>t;
    while(t--)
    {
        memset(visit,0,sizeof(visit));
        scanf("%d",&n);
        status=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if((a[i]>=1)&&(a[i]<=9))
            {
                visit[a[i]]++;
                if((i>1)&&(a[i-1]>=1)&&(a[i-1]<=9))
                    if(panduan(a[i-1],a[i])==0)
                        status=0;
            }
            else
                status=0;
        }
        //cout<<status<<endl;

        for(int i=1;i<=9;i++)
            if(visit[i]>1)
                status=0;
        if(n<4)
            status=0;
        //cout<<status<<endl;
        if(status)
            printf("valid\n");
        else
            printf("invalid\n");
    }
    return 0;
}
