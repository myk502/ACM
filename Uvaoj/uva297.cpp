#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<sstream>
#include<algorithm>
using namespace std;
bool a[35][35];
void init(void)
{
	memset(a,0,sizeof(a));
}
char input[10000];
int length;
void solve(int &id,int row_begin,int row_offset,int col_begin,int col_offset)
{
	//printf("The character is %c.Row from %d to %d.Column from %d to %d.\n",input[id],row_begin,row_begin+row_offset,col_begin,col_begin+col_offset);
	char xx=input[id++];
	if(xx=='p')
	{
		solve(id,row_begin,row_offset/2,col_begin+(col_offset/2),col_offset/2);
		solve(id,row_begin,row_offset/2,col_begin,col_offset/2);
		solve(id,row_begin+(row_offset/2),row_offset/2,col_begin,col_offset/2);
		solve(id,row_begin+(row_offset/2),row_offset/2,col_begin+(col_offset/2),col_offset/2);
	}
	if(xx=='f')
	{
		for(int row=row_begin;row<row_begin+row_offset;row++)
			for(int col=col_begin;col<col_begin+col_offset;col++)
				a[row][col]=true;
	}
}
int main(void)
{
	int T,ans;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		init();
		scanf("%s",input);
		length=strlen(input);
		int pos=0;
		solve(pos,0,32,0,32);
		scanf("%s",input);
		length=strlen(input);
		pos=0;
		solve(pos,0,32,0,32);
		for(int i=0;i<32;i++)
			for(int j=0;j<32;j++)
				if(a[i][j])
					ans++;
		printf("There are %d black pixels.\n",ans);
	}
	return 0;
}
