#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int n;
long long k;
const int maxn=100000+10;
int a[maxn],cnt[maxn];
struct Discreate
{
	int id;
	int value;
};
Discreate b[maxn];
bool cmp(Discreate X,Discreate Y)
{
	return X.value<Y.value;
}
bool judge(int mid)
{
	memset(cnt,0,sizeof(cnt));
	long long ans=0;//the number of intervals whose value >mid
	long long sum=( (long long)n*n )/2;
	int ll=0,num_mode=0,mode=-1;
	for(int i=0;i<n;i++)
	{
		cnt[a[i]]++;
		if(cnt[a[i]]>num_mode)
		{
			num_mode=cnt[a[i]];
			mode=a[i];
		}
		if(num_mode>=mid)
		{
			while(num_mode>=mid)
			{
				cnt[a[ll]]--;
				if(a[ll]==mode)
					num_mode--;
				ll++;
			}
			cnt[mode]++;
			num_mode++;
			ll--;
			ans+=ll+1;
		}
	}
	//printf("We are judgeing %d and ans=%d\n",mid,ans);
	return ans>=k;
}
int main(void)
{
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[i].value=a[i];
		b[i].id=i;
	}
	sort(b,b+n,cmp);
	a[b[0].id]=0;
	int cnt_a=0;
	for(int i=1;i<n;i++)
	{
		int index_a=b[i].id;
		if(b[i].value==b[i-1].value)
			a[index_a]=cnt_a;
		else
			a[index_a]=++cnt_a;
	}
	/*
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	cout<<endl;
	*/
	int ll=1,rr=n+1;
	//printf("judge(2)=%d\n",judge(2));
	
	while(rr-ll>1)
	{
		//printf("ll=%d,rr=%d\n",ll,rr);
		int mid=(ll+rr)>>1;
		//printf("judge(%d)=%d\n",mid,judge(mid));
		if(judge(mid))
			ll=mid;
		else
			rr=mid;
	}
	cout<<ll<<endl;
	
	return 0;
}
