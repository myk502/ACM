#include<cstdio>
#include<iostream>
#include<cstring>
#include<cctype>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=210;
char buf[maxn][maxn];
int n;//The number of rows

void dfs(int r,int c)
{
	printf("%c(",buf[r][c]);
	if( (r+1<n) && buf[r+1][c]=='|')//if This Node is not leaf
	{
		int i=c;
		while( i-1>=0 && r+2<n &&  buf[r+2][i-1]=='-')
			i--;
		while(buf[r+2][i]=='-' && buf[r+3][i]!='\0')
		{
			if(!isspace(buf[r+3][i]))
				dfs(r+3,i);
			i++;
		}
	}
	printf(")");

}

void solve(void)
{
	n=0;
	while(fgets(buf[n],maxn,stdin))
	{
		if(buf[n][0]=='#')
			break;
		else
			n++;
	}
	/*
	for(int i=0;i<n;i++)
	{
		int len=strlen(buf[i]);
		for(int j=0;j<len;j++)
			printf("%c",buf[i][j]);
		printf("\n");
	}
	*/
	int len=strlen(buf[0]);
	printf("(");
	if(n)
		for(int i=0;i<len;i++)
		{
			if(!isspace(buf[0][i]))
			{
				dfs(0,i);
			}
		}
	printf(")");

}



int main(void)
{
	int T;
	fgets(buf[0],maxn,stdin);
	sscanf(buf[0],"%d",&T);
	while(T--)
	{
		solve();
		printf("\n");
	}
	return 0;
}
