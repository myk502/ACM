#include<stdio.h>
#include<iso646.h>
#include<limits.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<ctype.h>
using namespace std;

int main(void)
{
    long long l,r,k,ans=1;
    int i=0,status=0;
    scanf("%I64d %I64d %I64d",&l,&r,&k);
    if(l>1)
    {
        while(ans<l)

        {
            i++;
            ans*=k;
        }


        while(ans<=r)
        {
            printf("%I64d ",ans);
            i++;
            status++;
            ans*=k;

        }

        if(status==0)
            printf("-1");
    }
    else
    {
        while(ans<=r)
        {
            printf("%I64d ",ans);
            i++;
            ans*=k;
        }
    }

    return 0;

}
