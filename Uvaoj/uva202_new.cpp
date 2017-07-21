#include<cstdio>
#include<iostream>
#include<cstring>
#include<climits>
#include<cmath>
#include<algorithm>
using namespace std;
int xs[10000];
int main(void)
{
    int aa,k,m,temp,a,b,zs,num_repeat,index_repeat;
    int status[3010];
    while(cin>>a>>b)
    {
        aa=a;
        zs=a/b;
        memset(status,-1,sizeof(status));
        status[a%b]=0;
        a=a%b*10;
        for(int i=1;i<3010;i++)
        {
            xs[i]=a/b;
            temp=a%b;
            if(status[temp]==-1)
            {
                status[temp]=i;
                a=a%b*10;

            }
            else
            {

                k=status[temp];
                m=i;
                break;
            }
        }
        //printf("m=%d and k=%d\n",m,k);
        if(m-k>50)
        {
            printf("%d/%d = %d.",aa,b,zs);
            for(int i=1;i<=k;i++)
                printf("%d",xs[i]);
            printf("(");
            for(int i=k+1;i<=k+50;i++)
                printf("%d",xs[i]);
            printf("...)\n");
        }
        else
        {
            printf("%d/%d = %d.",aa,b,zs);
            for(int i=1;i<=k;i++)
                printf("%d",xs[i]);
            printf("(");
            for(int i=k+1;i<=m;i++)
                printf("%d",xs[i]);
            printf(")\n");
        }
        printf("   %d = number of digits in repeating cycle\n\n",m-k);
    }
    return 0;
}
