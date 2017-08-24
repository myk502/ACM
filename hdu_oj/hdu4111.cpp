#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n,a[60];
string ANS;
int main(void)
{
	int T;
	scanf("%d",&T);
	for(int ii=1;ii<=T;ii++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int sg=0;
		for(int i=1;i<=n;i++)
			sg^=(a[i]%2);
		if(sg==0)
		{
			if(n%2==1)
				ANS="Bob";
			else
				ANS="Alice";
		}
		else
		{
			if(n%2==1)
				ANS="Alice";
			else
				ANS="Bob";
		}
		printf("Case #%d: ",ii);
		cout<<ANS<<endl;
	}
	return 0;
}
