#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<ctype.h>
#include<string>
#include<sstream>
#include<iostream>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std;
int a[66],status[52];
int main(void)
{
    int flag,n,sum,zuixiao,zuida,num;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            break;
        zuixiao=INT_MAX;
        zuida=INT_MIN;
        sum=0;
        num=n;
        memset(status,0,sizeof(status));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            status[a[i]]++;
            sum+=a[i];
            zuixiao=min(zuixiao,a[i]);
            zuida=max(zuida,a[i]);
        }
        sort(a,a+n);
        for(int i=zuida;i<=sum;i++)
        {
            flag=1;
            for(int j=0;j<n;j++)
            {
                int temp=i-a[j];
                if(num==0)
                    break;
                if(status[temp]!=status[a[j]])
                {
                    flag=0;
                    break;
                }
                else
                {
                    num-=2*status[temp];
                    status[temp]=0;
                    status[a[j]]=0;

                }
            }
            if(flag==0)
                continue;
            else
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
