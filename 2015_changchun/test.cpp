#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
int n,a[maxn];
int cnt[2];
int pos_true,pos_false;
int main(void)
{
	bool flag,ans;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans=false;
		cnt[0]=cnt[1]=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<n;i++)
		{
			if(a[i]>=a[i-1])
			{
				cnt[1]++;
			}
			if(a[i]>a[i-1])
				pos_true=i;
			if(a[i]<=a[i-1])
			{
				cnt[0]++;
			}
			if(a[i]<a[i-1])
				pos_false=i;
			
		}
		if(cnt[1]==n-1 || cnt[0]==n-1)
			ans=true;
		if(cnt[0]==n-2)
		{
			if(pos_true==n-1)
				ans=true;
			if(pos_true==1)
				ans=true;
			else
			{
				if(a[pos_true-1]>=a[pos_true+1])
					ans=true;
			}
		}
		if(cnt[1]==n-2)
		{
			if(pos_false==n-1)
				ans=true;
			if(pos_false==1)
				ans=true;
			else if(a[pos_false-1]<=a[pos_false+1])
				ans=true;
		}
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
