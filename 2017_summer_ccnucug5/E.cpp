#include<cstdio>
#include<iostream>
#include<cstring>
#include<climits>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
const int maxx=INT_MAX/2-20;
const int maxn=2000000;
pii pre[maxn];
int n,dp[maxn],mod[maxn];
void init(int n)
{
	mod[0]=1;
	for(int i=1;i<maxn;i++)
		mod[i]=(mod[i-1]*10)%n;
}
bool ans_bit[100000];
int main(void)
{
	ios::sync_with_stdio(false);
	cin>>n;
	init(n);
	for(int i=0;i<maxn;i++)
	{
		dp[i]=maxx;
	}
	dp[1]=0;
	dp[0]=0;//important!This status can not be chosen
	pre[1]=make_pair(-1,0);
	for(int i=1;i<n;i++)
	{
		int k=mod[i];
		if(dp[0]!=0)
			break;
		for(int j=0;j<n;j++)
		{
			if((j!=0)&&(dp[j]!=maxx))
				continue;
			int k=mod[i];
			int kk=(j-k+n)%n;
			if(dp[kk]!=maxx)
			{
				if(pre[kk].second==i)
					continue;
				//printf("i=%d,j=%d,kk=%d,dp[%d]=%d\n",i,j,kk,j,i);
				dp[j]=i;
				pre[j]=make_pair(kk,dp[j]);
			}

		}
	}
	/*
	for(int i=0;i<5;i++)
		printf("dp[%d]=%d\n",i,dp[i]);
	*/
	int max_bit=-1;
	memset(ans_bit,0,sizeof(ans_bit));
	int x=0;
	do
	{
		int pre_id=pre[x].first;
		int this_bit=pre[x].second;
		ans_bit[this_bit]=true;
		max_bit=max(max_bit,this_bit);
		x=pre_id;
	}
	while(x>1);
	if(x==1)//The LSB is 1
	{
		ans_bit[0]=true;
		max_bit=max(max_bit,0);
	}
	for(int i=max_bit;i>=0;i--)
	{
		if(ans_bit[i])
			cout<<"1";
		else
			cout<<"0";
	}
	cout<<endl;
	return 0;
}
