#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
char s[maxn];
int ans1,ans2,n,a[maxn],unsorted,num_0,num_1,m,k;
int main(void)
{
    cin>>n;
    scanf("%s",s);
    num_0=num_1=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='b')
        {
            a[i]=0;
            num_0++;
        }
        else
        {
            a[i]=1;
            num_1++;
        }
    }
    {
        int temp=0,temp_unsorted=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=temp)
                temp_unsorted++;
            temp=1-temp;
        }
        unsorted=temp_unsorted;
        m=abs(num_1-(n/2));
        k=(unsorted-m)/2;
        ans1=m+k;
    }
    {
        int temp=1,temp_unsorted=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=temp)
                temp_unsorted++;
            temp=1-temp;
        }
        unsorted=temp_unsorted;
        m=abs(num_0-(n/2));
        k=(unsorted-m)/2;
        ans2=m+k;
    }
    printf("%d",min(ans1,ans2));
    return 0;
}
