#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
#include<math.h>
using namespace std;

double ans1,ans2,ans;
long long a,b,temp;
int main(void)
{
    int k;
    double x;
    scanf("%I64d%I64d",&a,&b);
    if(a<b)
        printf("-1");
    if(a==b)
        printf("%.9lf",a*1.0);
    if(a>b)
    {
        k=(a-b)/(2*b);
        ans1=(double)(a-b)/(2*k);
        //printf("a=%I64d b=%I64d \n",a,b);
        //x=(a*1.0-b*1.0)/2.0;
        //printf("x=%lf\n",x);
        //do




        k=(a+b)/(2*b);
        ans2=(double)(a+b)/(2*k);


        ans=(ans1<ans2)?ans1:ans2;
        printf("%.9lf",ans);
    }
    return 0;
}
