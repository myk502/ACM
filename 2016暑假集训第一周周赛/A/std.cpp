#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
using namespace std;

const int maxn=100000+100;
int N,M,A[maxn][33],sum[maxn][33];

int main(int argc, char* argv[])
{
    int zz=0;
    scanf("%d",&zz);
    for (int test=1; test<=zz; test++)
    {
        scanf("%d%d",&N,&M);
        for (int i=1; i<=N; i++)
        {
            int x;
            scanf("%d",&x);
            for (int j=0; j<31; j++) A[i][j]=(x>>j)&1;
        }
        for (int j=0; j<31; j++) sum[0][j]=0;
        for (int i=1; i<=N; i++)
            for (int j=0; j<31; j++)
                sum[i][j]=sum[i-1][j]+A[i][j];
        while(M--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            int ans=0;
            for (int j=0; j<31; j++)
                if (sum[y][j]-sum[x-1][j]>0) ans|=(1<<j);
            printf("%d\n",ans);
        }
    }
    return 0;
}