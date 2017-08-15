#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=1000000;
int sum[maxn];
void build(int x)
{
	int v;
	cin>>v;
	if(v==-1)
		return ;
	sum[x]+=v;
	build(x-1);
	build(x+1);
}
bool init(void)
{
	int v;
	cin>>v;
	if(v==-1)
		return false;
	memset(sum,0,sizeof(sum));
	int pos=maxn/2;
	sum[pos]+=v;
	build(pos-1);
	build(pos+1);
	return true;
}
int main(void)
{
	int k=1;
	while(init())
	{
		int i=0;
		while(sum[i]==0)
			i++;
		printf("Case %d:\n",k++);
		printf("%d",sum[i++]);
		while(sum[i]!=0)
			printf(" %d",sum[i++]);
		printf("\n\n");
	}
	return 0;
}
