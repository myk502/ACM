#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=250000+10;
vector<int> rmq;
int st[25][maxn<<1];
int n,a[maxn<<1],b[maxn],c[maxn<<1];
const long long Mod=1000000000+7;
void RMQinit(int n)
{
    for(int i=1;i<=n;i++)
		st[0][i]=c[i];
    for(int i=1;i<23;i++)
        for(int j=1;j<=n;j++)
            if(j+(1<<i)-1>n) continue;
            else st[i][j]=max(st[i-1][j],st[i-1][j+(1<<i-1)]);
}
int RMQ(int L,int R)
{
    int k=0;
    while((1<<(k+1))<=R-L+1) k++;
    return max(st[k][L],st[k][R-(1<<k)+1]);
}
bool cmp(int x,int y)
{
	return x>y;
}
int main(void)
{
	long long ans;
	int maxx;
	ios::sync_with_stdio(false);
	while(cin>>n)
	{
		ans=0;
		maxx=-1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			c[i]=a[i]-i;
		}
		RMQinit(n);
		rmq.clear();
		for(int i=1;i<=n;i++)
		{
			cin>>b[i];
			rmq.push_back(RMQ(b[i],n));
		}
		sort(rmq.begin(),rmq.end(),cmp);
		/*
		for(auto it:rmq)
			cout<<it<<" ";
		cout<<endl;
		*/
		for(int i=n+1;i<=(n<<1);i++)
		{
			a[i]=max(rmq[i-n-1],maxx);\
			maxx=max(maxx,a[i]-i);
			ans=(ans+a[i])%Mod;
		}
		cout<<ans<<endl;
	}
	return 0;

}
