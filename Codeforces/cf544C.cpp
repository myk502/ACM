#include<stdio.h>
#include<string.h>
#include<queue>
#include<math.h>
#include<limits.h>
#include<algorithm>
using namespace std;
int n,m,b,mod;
int v[510];
int d[510];
void initialization(void)
{
    d[0]=0;
    for(int j=1;j<=m;j++) d[j]=INT_MIN;
}

int main(void)
{
    scanf("%d%d%d%d",&n,&m,&b,&mod);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    initialization();
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;j++) d[j]=max(d[j],d[j-1]+v[i]);
}

