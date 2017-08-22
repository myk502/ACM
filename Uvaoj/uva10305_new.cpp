#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
queue<int> zero_indegree;
int n,m,indegree[110];
vector<int> G[110];
vector<int> ANS;
int main(void)
{
	int aa,bb;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0)
			break;
		for(int i=1;i<=n;i++)
			G[i].clear();
		ANS.clear();
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&aa,&bb);
			indegree[bb]++;
			G[aa].push_back(bb);
		}
		for(int i=1;i<=n;i++)
		{
			if(indegree[i]==0)
			{
				zero_indegree.push(i);
			}
		}
		while(!zero_indegree.empty())
		{
			int temp=zero_indegree.front();
			zero_indegree.pop();
			ANS.push_back(temp);
			for(auto it:G[temp])
			{
				indegree[it]--;
				if(indegree[it]==0)
					zero_indegree.push(it);
			}
		}
		for(auto it:ANS)
			printf("%d ",it);
		printf("\n");
	}
	return 0;
}
