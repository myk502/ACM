#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 200000 + 10;
int a[maxn],b[maxn];
int n, m;

int main(void)
{
	int x;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i = 0;i < m;i++)
	{
		scanf("%d",&x);
		auto it =upper_bound(a,a+n,x) - a;
		printf("%d ",it);
	}
	printf("\n");
	return 0;
}
