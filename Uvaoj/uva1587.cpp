#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct myk{
int chang;
int kuan;};
myk a[10];
bool cmp1(myk x,myk y)//以长优先排序
{
    if(x.chang!=y.chang)
        return(x.chang<y.chang);
    else
        return(x.kuan<y.kuan);
}
int main(void)
{
    int ans,num;
    int b[20];
    while(1)
    {
        ans=1;
        for(int i=1;i<=6;i++)
            if(scanf("%d%d",&a[i].chang,&a[i].kuan)==EOF)
                goto myk;
        num=0;
        for(int i=1;i<=6;i++)
        {
            if(a[i].chang<a[i].kuan)
                swap(a[i].chang,a[i].kuan);
        }
        sort(a+1,a+7,cmp1);
        /*
        for(int i=1;i<=6;i++)
            printf("%d %d\n",a[i].chang,a[i].kuan);
        */
        for(int i=1;i<=3;i++)
        {
            if((a[2*i-1].chang!=a[2*i].chang)||(a[2*i-1].kuan!=a[2*i].kuan))
                ans=0;
        }

        for(int i=1;i<=3;i++)
        {
            b[num++]=a[2*i].chang;
            b[num++]=a[i*2].kuan;
        }
        sort(b,b+6);

        if((b[0]!=b[1])||(b[2]!=b[3])||(b[4]!=b[5]))
            ans=0;
        //printf("ans=%d\n",ans);
        if(ans)
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
    }
    myk:return 0;
}
