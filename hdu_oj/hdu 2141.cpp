#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
int a[510],b[510],c[510],d[500*500+10],indexx,x,l,n,m,s;
int main(void)
{
    int t=0;
    int ans;
    while(cin>>l>>n>>m)
    {
        t++;
        printf("Case %d:\n",t);
        for(int i=1;i<=l;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        for(int i=1;i<=m;i++)
            scanf("%d",&c[i]);
        cin>>s;
        indexx=0;
        for(int i=1;i<=l;i++)
        {
            for(int j=1;j<=m;j++)
            {
                d[indexx++]=a[i]+c[j];
            }
        }

        sort(d,d+indexx);
        //printf("ok!\n");
        d[indexx]=-1;
        for(int ii=1;ii<=s;ii++)
        {
            ans=0;
            scanf("%d",&x);
            for(int i=1;i<=n;i++)
            {
                int temp=x-b[i];
                //int weizhi=1;
                int weizhi=lower_bound(d,d+indexx,temp)-d;
                if(d[weizhi]==temp)
                {
                    ans=1;
                    break;
                }

            }
            if(ans)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
