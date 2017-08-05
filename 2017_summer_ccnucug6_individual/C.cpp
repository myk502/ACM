#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
string ss[maxn];
int n,len,tot=1;//len is the length of answer
vector<int>G[1000000+10];
set<int> s;
char ans[1000000+10];
struct myk
{
	int lend,rend,id;
	myk(int xx=0,int yy=0,int zz=0):lend(xx),rend(yy),id(zz)
	{

	}
};
myk bb[1000000+10];
int main(void)
{
	int k,start_point,len_string;
	ios::sync_with_stdio(false);
	cin>>n;
	len=-1;
	for(int ii=1;ii<=n;ii++)
	{
		cin>>ss[ii]>>k;
		len_string=ss[ii].length();
		for(int i=0;i<k;i++)
		{
			cin>>start_point;
			bb[tot].lend=start_point;
			bb[tot].rend=start_point+len_string;
			bb[tot].id=ii;
			G[start_point].push_back(tot);
			G[start_point+len_string].push_back(-tot);
			len=max(len,len_string+start_point);
			tot++;
		}

	}
	s.clear();
	for(int i=1;i<len;i++)
	{
		for(auto it:G[i])
		{
			//printf("We are now at %d and it=%d\n",i,it);
			if(it>0)
				s.insert(it);
			else
				s.erase(-it);
		}
		if(s.empty())
			ans[i]='a';
		else
		{
			auto it=s.begin();
			int idx=i-bb[*it].lend;
			//printf("idx=%d\n",idx);
			int idx_string=bb[*it].id;
			//printf("The string is");
			//cout<<ss[idx_string]<<endl;
			ans[i]=ss[idx_string][idx];
		}
		//printf("ans[%d]=%c\n",i,ans[i]);
	}
	ans[len]='\0';
	printf("%s\n",ans+1);
	return 0;
}
