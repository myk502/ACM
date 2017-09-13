#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int n,m;
int s[20],a[20],b[20],pattern[20];
int cnt[3];
int ans_a,ans_b;
int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&s[i]);
	for(int i=0;i<m;i++)
		scanf("%d",&pattern[i]);
	int id=0;
	for(int i=0;i<m;i++)
	{
		int val=(i&1)?0:1;
		for(int j=0;j<pattern[i];j++)
		{
			a[id]=val;
			b[id]=!val;
			id++;
		}
	}
	cnt[0]=cnt[1]=0;
	for(int i=0;i<n;i++)
	{
		cnt[s[i]]++;
	}
	int temp=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==1)
			temp++;
	}
	if(temp!=cnt[1])
		ans_a=10000;
	else
	{
		ans_a=0;
		int i=0,j=0;
		while(1)
		{
			if(i==n || j==n)
				break;
			while(i<n && s[i]!=0)
				i++;
			while(j<n && a[j]!=0)
				j++;
			if(i==n || j==n)
				break;
			ans_a+=abs(i-j);
			i++;
			j++;
		}
	}
	temp=0;
	for(int i=0;i<n;i++)
		if(b[i]==1)
			temp++;
	if(temp!=cnt[1])
		ans_b=10000;
	else
	{
		ans_b=0;
		int i=0,j=0;
		while(1)
		{
			if(i==n || j==n)
				break;
			while(i<n && s[i]!=0)
				i++;
			while(j<n && b[j]!=0)
				j++;
			if(i==n || j==n)
				break;
			ans_b+=abs(i-j);
			i++;
			j++;
		}
	}
	int ans=min(ans_a,ans_b);
	printf("%d\n",ans);
	return 0;
}
