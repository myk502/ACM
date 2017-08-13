#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<sstream>
#include<climits>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
int n,depth[maxn],lch[maxn],rch[maxn],inorder[maxn],postorder[maxn];
void init(void)
{
	memset(depth,-1,sizeof(depth));
	memset(lch,-1,sizeof(lch));
	memset(rch,-1,sizeof(rch));
}
string input;
int read_from_input(int* a)
{
	stringstream ss(input);
	int temp;
	int cnt=0;
	while(ss>>temp)
		a[cnt++]=temp;
	return cnt;
}
int solve(int l1,int r1,int l2,int r2)
{
	int root,id;
	if(l1==r1)
		return -1;
	root=postorder[r1-1];
	for(int i=l2;i<r2;i++)
		if(inorder[i]==root)
		{
			id=i;
			break;
		}
	int lnum=id-l2;
	lch[root]=solve(l1,l1+lnum,l2,id);
	rch[root]=solve(l1+lnum,r1-1,id+1,r2);
	return root;
}
void dfs(int id,int fa)
{
	if(id==-1)
		return ;
	if(fa==-1)
		depth[id]=id;
	else
		depth[id]=depth[fa]+id;
	dfs(lch[id],id);
	dfs(rch[id],id);
}
int main(void)
{
	ios::sync_with_stdio(false);
	int ans,ans_id;
	while(getline(cin,input))
	{
		init();
		ans=INT_MAX;
		read_from_input(inorder);
		getline(cin,input);
		n=read_from_input(postorder);
		solve(0,n,0,n);
		dfs(postorder[n-1],-1);
		for(int i=0;i<maxn;i++)
		{
			if(depth[i]==-1)
				continue;
			if((depth[i]<ans)&&(lch[i]==-1)&&(rch[i]==-1))
			{
				ans=depth[i];
				ans_id=i;
			}
		}
		cout<<ans_id<<endl;
	}
	return 0;
}
