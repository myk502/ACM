#include <stdio.h>
int main()
{
    int score,a[110],n,i,maxn,minn;
    double x;

    while(scanf("%d",&n)!=EOF)
    {
        score=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        maxn=a[1];
        for(i=1;i<=n;i++)
        {
            if(a[i]>maxn)
                maxn=a[i];
        }
        minn=a[1];
        for(i=1;i<=n;i++)
        {
            if(a[i]<minn)
                minn=a[i];
        }
        for(i=1;i<=n;i++)
        {
            score=score+a[i];
        }
        score=score-maxn-minn;
        x=(1.0*score)/(n-2);
        printf("%.2f\n",x);
    }
return 0;
}
