#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define zuida 100000+10
int n,k,a[zuida],num_0[zuida],num_1[zuida];
int main(void)
{
    int ans=-1;
    char temp;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%c",&temp);
        if(temp=='a')
            a[i]=0;
        else
            a[i]=1;
    }
    num_0[0]=num_1[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            num_0[i]=num_0[i-1]+1;
            num_1[i]=num_1[i-1];
        }
        else
        {
            num_0[i]=num_0[i-1];
            num_1[i]=num_1[i-1]+1;
        }
    }
    for(int j=1;j<=n;j++)//0 to 1
    {
        int i,l,r,mid,num0;
        l=0;
        r=j;
        while(r-l>1)
        {
            mid=(l+r)/2;
            num0=num_0[j]-num_0[mid];
            if(a[mid]==0)
                num0++;
            if(num0<=k)
                r=mid;
            else
                l=mid;
        }
        ans=max(ans,j-r+1);

    }
    for(int i=1;i<=n;i++)
        a[i]=1-a[i];
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            num_0[i]=num_0[i-1]+1;
            num_1[i]=num_1[i-1];
        }
        else
        {
            num_0[i]=num_0[i-1];
            num_1[i]=num_1[i-1]+1;
        }
    }
    for(int j=1;j<=n;j++)//1 to 0
    {
        int i,l,r,mid,num0;
        l=0;
        r=j;
        while(r-l>1)
        {
            mid=(l+r)/2;
            num0=num_0[j]-num_0[mid];
            if(a[mid]==0)
                num0++;
            if(num0<=k)
                r=mid;
            else
                l=mid;
        }
        ans=max(ans,j-r+1);

    }
    printf("%d",ans);
    return 0;
}
