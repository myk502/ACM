#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int n;
long long bits[65],s[1010],pow2[65],ans;
const int maxn=64000;
struct Trie
{
	int tot,root,go[2][maxn],cnt[maxn];
	void init(void)
	{
		memset(go,-1,sizeof(go));
		memset(cnt,0,sizeof(cnt));
		tot=0;
		root=create();
	}
	int create(void)
	{
		go[0][tot]=go[1][tot]=-1;
		return tot++;
	}
	void insert(long long x)
	{
		int now=root;
		for(int i=31;i>=0;i--)
		{
			int flag=x&bits[i];
			flag=!!flag;
			//cout<<"x="<<x<<"  i="<<i<<" flag="<<flag<<endl;
			if(go[flag][now]==-1)
				go[flag][now]=create();
			now=go[flag][now];
			cnt[now]++;
		}
	}
	void dele(long long x)
	{
		int now=root;
		for(int i=31;i>=0;i--)
		{
			int flag=x&bits[i];
			flag=!!flag;
			now=go[flag][now];
			cnt[now]--;
		}
	}
	
	long long solve(long long x)
	{
		long long ans=0;
		int now=root;
		for(int i=31;i>=0;i--)
		{
			int flag=x&bits[i];
			flag=!!flag;
			if(go[flag][now]==-1)
				now=go[!flag][now];
			else
			{
				int tempnow=go[flag][now];
				if(cnt[tempnow]>0)
				{
					ans+=pow2[i];
					now=tempnow;
				}
				else
					now=go[!flag][now];
			}
		}
		return ans;
	}

};
Trie mytrie;
void init(void)
{
	bits[0]=1LL;
	for(int i=1;i<64;i++)
		bits[i]=bits[i-1]<<1;
	mytrie.init();
	for(int i=0;i<n;i++)
		mytrie.insert(s[i]);
	ans=0;
	pow2[0]=1;
	for(int i=1;i<60;i++)
		pow2[i]=pow2[i-1]*2;
}

int main(void)
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>s[i];
		if(n<=100)
		{
			ans=0;
			for(int i=0;i<n;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					for(int k=0;k<n;k++)
					{
						if((k==i)||(k==j))
							continue;
						long long sum=s[i]+s[j];
						ans=max(ans,sum^s[k]);
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}
		init();
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				mytrie.dele(s[i]);
				mytrie.dele(s[j]);
				long long temp=mytrie.solve(~(s[i]+s[j]));
				ans=max(ans,temp);
				mytrie.insert(s[j]);
				mytrie.insert(s[i]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
