#include<bits/stdc++.h>
using namespace std;
int n,a;
const int maxn=100000+10;
double angle[maxn];
int main(void)
{
    cin>>n>>a;
    double x=180.0/(double)n;
    for(int i=1;i<=n-2;i++)
        angle[i]=x*i;
    double minn=fabs(angle[1]-a);
    int min_id=1;
    for(int i=2;i<=n-2;i++)
    {
        if(fabs(angle[i]-a)<minn)
        {
            minn=fabs(angle[i]-a);
            min_id=i;
        }
    }
    printf("%d %d %d\n",min_id+2,1,2);
    return 0;
}
