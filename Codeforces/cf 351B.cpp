#include<stdio.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#include<algorithm>
using namespace std;
int m,n,l,r;
int main(void)
{
    int tempa,tempaa,tempbb,tempb;
    scanf("%d%d",&n,&m);
    l=1;
    r=n;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&tempaa,&tempbb);
        tempa=min(tempaa,tempbb);
        tempb=max(tempaa,tempbb);
        l=max(l,tempa);
        r=min(r,tempb);
    }
    if(l>=r)
        printf("0");
    else
        printf("%d",r-l);
    return 0;
}
