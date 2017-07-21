#include<stdio.h>
#include<string.h>
#include<iostream>
#include<limits.h>
#include<math.h>
#include<algorithm>
#include<ctype.h>
using namespace std;
bool cmp(unsigned long long x,unsigned long long y)
{
    return (x<y);
}
int main(void)
{
    int t,status;
    unsigned long long a[5];
    cin>>t;
    while(t--)
    {
        status=1;
        for(int i=0;i<4;i++)
        {
            cin>>a[i];
            if(a[i]==0)
                status=0;
        }
        sort(a,a+4,cmp);
        if(a[0]+a[1]<=a[3]-a[2])
            status=0;
        if(status)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
