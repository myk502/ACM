#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
int n,a[maxn];
int cnt[3];
int pos_true,pos_false,pos_equal;
int main(void)
{
	bool flag,ans;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans=false;
		cnt[0]=cnt[1]=cnt[3]=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<n;i++)
		{
			if(a[i]>a[i-1])
			{
				cnt[1]++;
				pos_true=i;
			}
			if(a[i]>a[i-1])
			{
				cnt[0]++;
				pos_false++;
			}
			if(a[i]==a[i-1])
			{
				cnt[2]++;
				pos_
			}
		}
		if(cnt[1]==0 || cnt[0]==0)
			ans=true;
		if(cnt[1]==1)
		{
			if(pos_true==n-1)
				ans=true;
			else
			{
				if(a[pos_true-1]>=a[pos_true+1])
					ans=true;
			}
		}
		if(cnt[0]==1)
		{
			if(pos_false==n-1)
				ans=true;
			else if(a[pos_true-1]<=a[pos_true+1])
				ans=true;
		}
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
