#include<cstdio>
#include<map>
#include<string>
#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
const int maxn=100000+10;
struct Node
{
	string text;
	int frequency;
};
Node a[maxn];
int b[maxn];
string s[maxn];
vector<int> G[1000000+10];
#define MID(a,b) (a+((b-a) >> 1 ))
bool cmp(Node X,Node Y)
{
	return X.text<Y.text;
}
struct P_Tree
{
	int n,order[maxn];
	int valu[20][maxn],num[20][maxn];
	long long sum[maxn],lsum[20][maxn],isum;

	void init(int len)
	{
		n=len;
		sum[0]=0;
		for(int i=0;i<20;i++)
			valu[i][0]=0,num[i][0]=0,lsum[i][0]=0;
		for(int i=1;i<=n;i++)
		{
			order[i]=b[i];
			valu[0][i]=order[i];
			sum[i]=sum[i-1]+order[i];
		}
		sort(order+1,order+1+n);
		build(1,n,0);
	}

	void build(int lft,int rht,int ind)
	{
		if(lft==rht)
			return ;
		int mid=MID(lft,rht);
		int same=mid-lft+1,ln=lft,rn=mid+1;
		for(int i=lft;i<=rht;i++)
			if(valu[ind][i]<order[mid])
				same--;
		for(int i=lft;i<=rht;i++)
		{
			int flag=0;
			if((valu[ind][i]<order[mid]) || (valu[ind][i]==order[mid] && same) )
			{
				flag=1;
				valu[ind+1][ln++]=valu[ind][i];
				lsum[ind][i]=lsum[ind][i-1]+valu[ind][i];
				if(valu[ind][i]==order[mid])
					same--;
			}
			else
			{
				valu[ind+1][rn++]=valu[ind][i];
				lsum[ind][i]=lsum[ind][i-1];
			}
			num[ind][i]=num[ind][i-1]+flag;
		}
		build(lft,mid,ind+1);
		build(mid+1,rht,ind+1);
	}

	int query(int st,int ed,int k,int lft,int rht,int ind)
	{
		if(lft==rht)
			return valu[ind][lft];
		int mid=MID(lft,rht);
		int lx=num[ind][st-1]-num[ind][lft-1];
		int ly=num[ind][ed]-num[ind][st-1];
		int rx=st-1-lft+1-lx;
		int ry=ed-st+1-ly;
		if(ly>=k)
			return query(lft+lx,lft+lx+ly-1,k,lft,mid,ind+1);
		else
		{
			isum+=lsum[ind][ed]-lsum[ind][st-1];
			st=mid+1+rx;
			ed=mid+1+rx+ry-1;
			return query(st,ed,k-ly,mid+1,rht,ind+1);
		}
	}
}tree;
int main(void)
{
	string temp,temp2;
	int tempval;
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp>>tempval;
		a[i].text=temp;
		a[i].frequency=tempval;
	}
	sort(a,a+n,cmp);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i-1].frequency;
		s[i]=a[i-1].text;
	}
	for(int i=1;i<=n;i++)
	{
		G[b[i]].push_back(i);
		//printf("push %d to G[%d]\n",i,b[i]);
	}
	tree.init(n);
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>temp;
		temp2=temp;
		int len=temp.length();
		temp2[len-1]++;
		auto ll=lower_bound(s+1,s+n+1,temp)-s;
		auto rr=lower_bound(s+1,s+n+1,temp2)-s;
		//cout<<ll<<" "<<rr<<endl;
		int num=rr-ll;
		int tempcnt=0;
		while(1)
		{
			if(tempcnt==10)
				break;
			if(tempcnt==num)
				break;
			int id=num-tempcnt;
			int tempans=tree.query(ll,rr-1,id,1,n,0);
			//cout<<tempans<<" mark"<<endl;
			for(auto it:G[tempans])
			{
				if(tempcnt==10 || tempcnt==num)
					break;
				cout<<s[it]<<endl;
				tempcnt++;
			}

		}
		cout<<endl;

	}

	return 0;
}
