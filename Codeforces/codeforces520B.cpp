#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct Edge{
int from;
int to;
int cost;};
int m,n;

int main(void)
{
    int ans=0;
    int cnt=0;
    scanf("%d%d",&n,&m);
    if(n>=m)
        printf("%d",n-m);
    else
    {
        while(m>n)
        {
            if(m%2==0)
            {
                ans++;
                m/=2;
            }
            else
            {
                m=(m+1)/2;
                ans+=2;
            }
        }
        ans+=n-m;
        printf("%d",ans);
    }
    return 0;
}
