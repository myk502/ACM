#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<map>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=200000+10;
int a[maxn],sum[maxn],n,odd_with_ones,odd_without_ones,even_with_ones,even_without_ones;
int main(void)
{
	long long ans;
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		sum[0]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]^a[i];
		}
		odd_with_ones=odd_without_ones=even_with_ones=even_without_ones=0;
		for(int i=n-1;i>=1;i--)
		{
			if(a[i]==0)
			{
				if(a[i+1]==1)
				{
					odd_with_ones=odd_with_ones+odd_without_ones;
					odd_without_ones=0;
					even_with_ones=even_with_ones+even_without_ones;
					even_without_ones=0;
				}
			}
			else
			{
				if(a[i+1]==1)
				{
					int aa=odd_with_ones,bb=even_with_ones;
					odd_with_ones=bb+even_without_ones;
					even_with_ones=aa+odd_without_ones;
					odd_without_ones=even_without_ones=0;
				}
				else
				{
					swap(odd_with_ones,even_with_ones);
					swap(odd_without_ones,even_without_ones);
				}
			}
			if(a[i]==a[i+1])
				odd_without_ones++;
			else
				even_without_ones++;
			ans+=odd_with_ones;
		}
		cout<<ans<<endl;

	}
	return 0;
}
