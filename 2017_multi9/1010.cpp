#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
char a[2510],b[2510];
int length_a,length_b;
bool dp[2510][2510];
int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",a,b);
		length_a=strlen(a);
		length_b=strlen(b);
		memset(dp,0,sizeof(dp));
		dp[0][0]=true;
		for(int j=0;j+1<length_b;j+=2)
		{
			if((b[j]!='*') && (b[j+1]=='*'))
			{
				dp[0][j+2]=true;
			}
			else
				break;
		}
		for(int i=1;i<=length_a;i++)
		{
			for(int j=1;j<=length_b;j++)
			{
				char aa=a[i-1],bb=b[j-1];
				if(bb=='.')
					dp[i][j]=dp[i-1][j-1];
				else if(bb=='*')
				{
					if((i>1) && (a[i-1]==a[i-2]))
						dp[i][j]=dp[i-1][j];
					if(!dp[i][j])
						dp[i][j]=dp[i][j-1]|dp[i][j-2];
				}
				else
				{
					if(aa!=bb)
						dp[i][j]=false;
					else
						dp[i][j]=dp[i-1][j-1];
				}
			}
		}
		if(dp[length_a][length_b])
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
