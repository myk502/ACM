#include<bits/stdc++.h>
using namespace std;
int tree[5010];
int n,a[5010];
void add(int k,int num)
{
    while(k<=n)
    {
        tree[k]+=num;
        k+=k&-k;
        //printf("k=%d",k);
    }
}

int read(int k)
{
    int sum=0;
    while(k)
    {
        sum+=tree[k];
        k-=k&-k;
    }
    return sum;
}

int main(void)
{
    int ans,cnt,num_inverse;//cnt is the number of integers we add to the binary indexed tree
    //freopen("in","r",stdin);
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            a[i]++;
            //printf("a[%d]=%d\n",i,a[i]);
        }
        cnt=num_inverse=0;
        memset(tree,0,sizeof(tree));
        for(int i=1;i<=n;i++)
        {
            //printf("cnt=%d,read(a[i])=%d\n",cnt,read(a[i]));
            num_inverse+=cnt-read(a[i]);
            add(a[i],1);
            cnt++;
        }
        ans=num_inverse;
        for(int i=1;i<n;i++)
        {
            //printf("num_inverse=%d\n",num_inverse);
            num_inverse=num_inverse-2*a[i]+n+1;
            ans=min(ans,num_inverse);
        }


        cout<<ans<<endl;
    }
    return 0;
}
