#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#include<iostream>
#include<queue>
#include<set>
#include<map>
using namespace std;
int t;
char a[210],b[210],c[420];
int dp[210][210],length_a,length_b,length_c;

int main(void)
{
    int i,j;
    cin>>t;
    for(int ii=1;ii<=t;ii++)
    {
        scanf("%s%s%s",a,b,c);
        //printf("%s\n%s\n%s\n",a,b,c);
        memset(dp,0,sizeof(dp));//to be confirmed

        length_a=strlen(a);
        length_b=strlen(b);
        length_c=strlen(c);
        if(length_c!=length_a+length_b)
        {
            printf("Data set %d: no\n",ii);
            continue;
        }
        dp[0][0]=1;
        for(int i=1;i<=length_a;i++)
        {
            if(a[i-1]==c[i-1])
                dp[i][0]=1;
            else
                break;
        }
        for(int j=1;j<=length_b;j++)
        {
            if(b[j-1]==c[j-1])
                dp[0][j]=1;
            else
                break;
        }
        for(int i=1;i<=length_a;i++)
        {
            for(int j=1;j<=length_b;j++)
            {
                dp[i][j]=((a[i-1]==c[i+j-1])&&(dp[i-1][j]))||((b[j-1]==c[i+j-1])&&(dp[i][j-1]));
                //printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
            }
        }
        if(dp[length_a][length_b]==1)
        {
            printf("Data set %d: yes\n",ii);
        }
        else
        {
            printf("Data set %d: no\n",ii);
        }
    }
    return 0;
}
