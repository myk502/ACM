#include<bits/stdc++.h>
using namespace std;
int cal(int x)
{
	int ans=0;
	for(int i=1;i<=x;i++)
	{
		double temp=(double)x/(double)i;
		temp=ceil(temp);
		ans+=(int)temp;
	}
	return ans;
}
int main(void)
{
	for(int i=1;i<20;i++)
		printf("dp[%d]=%d\n",i,cal(i));
	return 0;
}
