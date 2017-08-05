#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;
int n,m,bits[32];
char op[10],address[20];
const int maxn=6500000;
int ip_modification(char* str,int& mask)
{
	mask=-1;
	int ans=0;
	int aa,bb,cc,dd;
	auto it=strchr(str,'/');
	sscanf(str,"%d.%d.%d.%d",&aa,&bb,&cc,&dd);
	ans+=dd;
	ans+=(cc<<8);
	ans+=(bb<<16);
	ans+=(aa<<24);
	if(it!=NULL)
		sscanf(it+1,"%d",&mask);
	return ans;
}

struct trie
{
	int tot,root,lch[maxn],rch[maxn],id[maxn];
	int status[maxn];//-1 0 1
	void init(void)
	{
		memset(status,0,sizeof(status));
		memset(id,0,sizeof(id));
		memset(lch,-1,sizeof(lch));
		memset(rch,-1,sizeof(rch));
		tot=0;
		root=create();
	}
	int create(void)
	{
		lch[tot]=rch[tot]=-1;
		return tot++;
	}
	void insert(int x,int mask,bool stat,int idd)
	{
		int now = root;
		if( (mask==0) &&(status[now]==0))
		{
			if(stat)
				status[now]=1;
			else
				status[now]=-1;
			id[now]=idd;
		}
		for(int j=31;j>=0;j--)
		{
			int xx=!!( x & bits[j] );
			if(xx==0)
			{
				if(lch[now]==-1)
					lch[now]=create();
				now=lch[now];
			}
			else
			{
				if(rch[now]==-1)
					rch[now]=create();
				now=rch[now];
			}
			if((j==31-mask+1) && (status[now]==0) )
			{
				if(stat)
					status[now]=1;
				else
					status[now]=-1;
				id[now]=idd;
			}

		}
		if(status[now]!=0)
			return ;
		if(stat)
			status[now]=1;
		else
			status[now]=-1;
		id[now]=idd;
	}
	bool search(int x)
	{
		int id_min=INT_MAX;
		bool ans=true;
		int now=root;
		for(int j=31;j>=0;j--)
		{
			if(status[now]==-1)
			{
				if(id[now]<id_min)
				{
					id_min=id[now];
					ans=false;
				}
			}
			if(status[now]==1)
			{
				if(id[now]<id_min)
				{
					id_min=id[now];
					ans=true;
				}
			}
			int xx=!!( x & bits[j]);
			/*
			if(x==-1)
			{
				printf("The %d-th bit is %d\n",j,xx);
			}
			*/
			if(xx==0)
				now=lch[now];
			else
				now=rch[now];
			if(now==-1)
				break;
		}
		if(now!=-1)
		{

			if(status[now]==-1)
			{
				if(id[now]<id_min)
				{
					id_min=id[now];
					ans=false;
				}
			}
			if(status[now]==1)
			{
				if(id[now]<id_min)
				{
					id_min=id[now];
					ans=true;
				}
			}
		}
		return ans;

	}
};
trie Trie;
void init(void)
{
	bits[0]=1;
	for(int i=1;i<32;i++)
		bits[i]=bits[i-1]<<1;
	Trie.init();
}
int main(void)
{
	int mask;
	bool flag;
	int ip;
	init();
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%s%s",op,address);
		mask=-1;
		ip=ip_modification(address,mask);
		//printf("%s  %d\n",address,ip);
		if(strcmp(op,"allow")==0)
			flag=true;
		else
			flag=false;
		Trie.insert(ip,mask,flag,i);
	}
	for(int i=0;i<m;i++)
	{
		scanf("%s",address);
		ip=ip_modification(address,mask);
		bool temp=Trie.search(ip);
		if(temp)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}
