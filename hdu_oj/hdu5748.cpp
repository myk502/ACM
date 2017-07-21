#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
int n,a[maxn],length,L[maxn],dp[maxn],LL[maxn];
//LL[] is 
void cal_lis(void)
{
    for(int i=0;i<maxn;i++)
        L[i]=INT_MAX;
    L[1]=a[0];
    length=1;
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        int temp=lower_bound(L+1,L+length+1,a[i])-L;
        dp[i]=temp;//This is the f(i)
        L[temp]=min(L[temp],a[i]);
        length=max(length,temp);
    }
}
int main(void)
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        cal_lis();
        LL[0]=0;//store the maximal value 
	printf("%d",dp[0]);
        for(int i=1;i<n;i++)
            printf(" %d",dp[i]);
        printf("\n");
    }

    return 0;
}
