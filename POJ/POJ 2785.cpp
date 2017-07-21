#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=4010;
int n,a[maxn],b[maxn],c[maxn],d[maxn];
int main(void)
{
    int sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    }
    vector<int> sum1;
    vector<int> sum2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sum1.push_back(a[i]+b[j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sum2.push_back(c[i]+d[j]);
        }
    }
    sort(sum2.begin(),sum2.end());
    for(int i=0;i<sum1.size();i++)
    {
        int x=-sum1[i];
        sum+=upper_bound(sum2.begin(),sum2.end(),x)-lower_bound(sum2.begin(),sum2.end(),x);
    }
    printf("%d\n",sum);
    return 0;
}
