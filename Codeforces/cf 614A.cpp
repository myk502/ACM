#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define zuida 18446744073709551615
using namespace std;

unsigned long long l,r,k;
int main(void)
{
    long double rr,tempp,kk,zuidaa;
    scanf("%llu%llu%llu",&l,&r,&k);
    //printf("l=%lld and r=%lld and k=%lld\n",l,r,k);
    unsigned long long temp=1;
    int num=0;
    while(temp<l)
    {
        temp*=k;
        num++;
    }
    if(temp>r)
    {
        printf("-1");
        goto myk;
    }
    while(temp<=r)
    {
        printf("%llu ",temp);
        rr=r*1.0;
        tempp=temp*1.0;
        kk=k*1.0;
        zuidaa=zuida*1.0;
        if(zuida/temp<k)
            break;
        temp*=k;

    }
    myk:return 0;
}
