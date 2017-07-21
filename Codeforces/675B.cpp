#include<stdio.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<vector>
#include<set>
#include<ctype.h>
#include<algorithm>
using namespace std;
int n,a,b,c,d;
int main(void)
{
    int l=INT_MIN,r=INT_MAX;
    long long ans=0;
    scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
    for(int y=1;y<=n;y++)
    {
        l=1;
        r=n;
        l=max(l,1+c-b);
        l=max(l,1+d-a);
        l=max(l,1+c+d-a-b);
        r=min(r,c+n-b);
        r=min(r,n+d-a);
        r=min(r,n+c+d-a-b);
        if(l<=r)
            ans+=r-l+1;
    }
    printf("%I64d",ans);
    return 0;
}
