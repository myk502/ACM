#include<bits/stdc++.h>
using namespace std;
int cnt[11];
vector<int> ans;
bool cmp(int x,int y)
{
	return x>y;
}
int main(void)
{
	int n,k;
	int a[100];
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			int maxx=-1;
			memset(cnt,0,sizeof(cnt));
			for(int k=i;k<=j;k++)
			{
				cnt[a[k]]++;
			}
			for(int ii=0;ii<=10;ii++)
			{
				maxx=max(maxx,cnt[ii]);
			}
			ans.push_back(maxx);
		}
	sort(ans.begin(),ans.end(),cmp);
	for(auto it:ans)
		cout<<it<<endl;
	return 0;
}
