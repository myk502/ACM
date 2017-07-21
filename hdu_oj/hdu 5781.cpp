#include<bits/stdc++.h>
using namespace std;
double dp[2010][30];
int k,w;
int main(void)
{
    for(int j=1;j<=30;j++)
        dp[0][j]=0;
    for(int i=0;i<=2000;i++)
        dp[i][0]=1000000000;
    for(int i=1;i<=2000;i++)
    {
        dp[i][1]=(double)(i*(i+3))/(double)(2*(i+1));
        for(int j=2;j<=30;j++)
        {
            double minn=100000000;
            for(int k=1;k<=i;k++)
                minn=min(minn,(k*dp[k-1][j-1]+(i-k+1)*dp[i-k][j])/(i+1));
            dp[i][j]=minn+1;
        }
    }
    while(cin>>k>>w)
    {
        if(w>25)
            w=25;
        printf("%.6f\n",dp[k][w]);
    }
    return 0;
}
