#include<cstdio>
#include<cstring>
#include<iostream>
#include<climits>
#include<cmath>
#include<time.h>
#include<algorithm>
#include<ctype.h>
using namespace std;
#define MAX_T 100000
#define getNumInRange(x,lower,upper) while((*(x)=rand()%upper)<lower)//[x)
int main(void)
{
    int t,n,x;
    freopen("in.txt","w",stdout);
    srand((unsigned)(time(0)));
    getNumInRange(&t,0,MAX_T);
    t=1;
    printf("%d\n",t);
    while(t--)
    {
        getNumInRange(&n,1,10);
        printf("%d ",n);
        for(int i=0;i<n;i++)
        {
            getNumInRange(&x,0,INT_MAX);
            printf("%d ",x);
        }
        printf("\n");

    }
    return 0;
}

