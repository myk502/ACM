#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

int get_id(char* x)
{
	if(x[0]=='0' && x[1]=='0')
		return -1;
	int first=x[0]-'A';
	if(x[1]=='+')
		return 2*first;
	else
		return 2*first+1;
}
int n;
queue<int> q;
const int maxn=40000+10;
int G[60][60];
int indegree[maxn],id[maxn][4];
int main(void)
{
	char input[10];
	while(scanf("%d",&n)!=EOF)
	{
		memset(indegree,0,sizeof(indegree));
		memset(G,0,sizeof(G));
		while(!q.empty())
			q.pop();
		for(int i=0;i<n;i++)
		{
			scanf("%s",input);
			for(int j=0;j<4;j++)
				id[i][j]=get_id(input+(j<<1));
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<4;j++)
			{
				//printf("id[%d][%d]=%d\n",i,j,id[i][j]);
				if(id[i][j]==-1)
					continue;
				for(int kk=0;kk<4;kk++)
				{
					int temp=id[i][kk];
					if(kk==j)
						continue;
					if(temp==-1)
					continue;
					temp^=1;
					G[id[i][j]][temp]=1;
				}
				//G[id[i][j]][temp^1]=1;
				//printf("G[%d][%d]=1\n",id[i][j],temp);
			}
		}
		for(int j=0;j<60;j++)
		{
			for(int i=0;i<60;i++)
				if(G[i][j]==1)
					indegree[j]++;
		}
		for(int i=0;i<60;i++)
			if(indegree[i]==0)
				q.push(i);
		while(!q.empty())
		{
			int temp=q.front();
			q.pop();
			for(int to=0;to<60;to++)
			{
				if(G[temp][to]==1)
				{
					indegree[to]--;
					if(indegree[to]==0)
						q.push(to);
				}
			}
		}
		bool flag=true;
		for(int i=0;i<60;i++)
			if(indegree[i]!=0)
				flag=false;
		if(!flag)
			printf("unbounded\n");
		else
			printf("bounded\n");
	}
	return 0;
}
