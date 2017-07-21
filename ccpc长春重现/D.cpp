#include<bits/stdc++.h>
using namespace std;
int t,n,m,nn,p;
const int maxn=1000000+10;
int a[maxn],b[maxn],N[maxn],aa[maxn];
void buildnext(void)
{
    int j=0;
    int t=-1;
    N[0]=-1;
    while(j<m-1)
        if(0>t||b[j]==b[t])
        {
            j++;
            t++;
            N[j]=t;
        }
        else
            t=N[t];
}

int match(void)
{
    /*
    for(int i=0;i<m;i++)
        printf("next[%d]=%d\n",i,N[i]);
    */
    int i=0,j=0,cnt=0;
    while(i<n)
    {
        if(0>j||a[i]==b[j])
        {
            i++;
            j++;
        }
        else
            j=N[j];
        if((j==m))
        {
            //printf("i=%d\n",i);
            cnt++;
            j=0;
            i=i-j+1;
        }
    }
    return cnt;

}

int main(void)
{
    //freopen("in.txt","r",stdin);
    int ans;
    cin>>t;
    for(int ii=1;ii<=t;ii++)
    {
        ans=0;
        cin>>nn>>m>>p;
        for(int i=0;i<nn;i++)
            scanf("%d",&aa[i]);
        for(int i=0;i<m;i++)
        scanf("%d",&b[i]);
        buildnext();
        for(int i=0;i<p;i++)
        {
            //a[0]=aa[i];
            //a[1]=aa[i+p];
            int j;
            for(j=0;(i+j*p)<nn;j++)
            {
                a[j]=aa[i+j*p];
            }
            n=j;
            ans+=match();
        }
        printf("Case #%d: %d\n",ii,ans);
    }
    return 0;
}
