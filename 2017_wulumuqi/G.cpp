#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
char s[maxn],t[15];
int n,m,k;
const long long Mod=100000081;
long long poww[15],hash_t,myhash[maxn],match[maxn];
int tree[maxn];
void init(void)
{
	poww[0]=1LL;
	for(int i=1;i<=10;i++)
		poww[i]=(poww[i-1]*29)%Mod;
}
long long get_hash(char* str,int ll,int rr)//[ll,rr]
{
	long long ans=0;
	int id=0;
	for(int i=rr;i>=ll;i--)
	{
		ans+=poww[id++]*(str[i]-'A'+1);
		ans%=Mod;
	}
	return ans;
}

void add(int k,int num)
{
	while(k<=n)
	{
		tree[k]+=num;
		k+=k&-k;
	}
}

int read(int k)
{
	int sum=0;
	while(k)
	{
		sum+=tree[k];
		k-=k&-k;
	}
	return sum;
}

int query(int ll,int rr)
{
	if(rr-ll+1<k)
		return 0;
	ll=ll+k-1;
	return read(rr)-read(ll-1);
}

int main(void)
{
	char input[10];
	int T;
	init();
	scanf("%d",&T);
	for(int ii=1;ii<=T;ii++)
	{
		if(ii!=1)
			printf("\n");
		memset(tree,0,sizeof(tree));
		scanf("%d",&m);
		scanf("%s%s",s+1,t);
		n=strlen(s+1);
		k=strlen(t);
		hash_t=get_hash(t,0,k-1);
		for(int i=1;i<=n;i++)
		{
			if(i-k+1<1)
			{
				myhash[i]=-1;
				match[i]=0;
			}
			else
			{
				myhash[i]=get_hash(s,i-k+1,i);
				match[i]=(myhash[i]==hash_t);
			}
			add(i,match[i]);
		}
		for(int iii=1;iii<=m;iii++)
		{
			scanf("%s",input);
			if(input[0]=='Q')
			{
				int ll,rr;
				scanf("%d%d",&ll,&rr);
				int ans=query(ll,rr);
				printf("%d\n",ans);
			}
			else
			{
				int id;
				char x;
				scanf("%d%s",&id,input);
				x=input[0];
				int offset=x-s[id];
				s[id]=x;
				for(int i=id;i<id+k;i++)
				{
					myhash[i]+=poww[i-id]*offset;
					myhash[i]%=Mod;
					myhash[i]=(myhash[i]+Mod)%Mod;
					int old_val=match[i];
					int new_val=(myhash[i]==hash_t);
					match[i]=new_val;
					add(i,new_val-old_val);
				}
			}
		}
	}
	return 0;
}
