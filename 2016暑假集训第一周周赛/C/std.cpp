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

const int maxn=10000+100;
int N,A[maxn];
char name[maxn][25];

int main(int argc, char* argv[])
{
    int zz=0;
    scanf("%d",&zz);
    for (int test=1; test<=zz; test++)
    {
        scanf("%d",&N);
        for (int i=1; i<=N; i++) scanf("%s%d",name[i],&A[i]);
        int ans=-1,k;
        for (int i=1; i<N; i++)
        {
            int ret=abs(A[i]-A[i+1]);
            if (ret>ans) ans=ret,k=i;
        }
        printf("%d\n",ans);
        printf("%s %s\n",name[k],name[k+1]);
    }
    return 0;
}