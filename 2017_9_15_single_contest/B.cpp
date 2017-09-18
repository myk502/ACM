#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
const int maxn=10000+10;
char a[maxn],temp[maxn];
int n,m,ll,rr,kk;
void solve(int l,int r,int k)
{
	int id = l;
	int len = r - l + 1;
	k %= len;
	if(!k)
		return ;
	for(int i = r + 1 - k ; i <= r;i++)
		temp[id++] = a[i];
	for(int i = l; i <= r-k; i++)
		temp[id++] = a[i];
	for(int i = l; i <= r; i++)
		a[i] = temp[i];

}
int main(void)
{
	scanf("%s",a+1);
	n = strlen(a + 1);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&ll,&rr,&kk);
		solve(ll,rr,kk);
	}
	printf("%s\n",a+1);
	return 0;
}
