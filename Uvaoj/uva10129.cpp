#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
int n,indegree[30],outdegree[30],pre[30];
char input[1010];
bool exist[30];
int find_ancestor(int x)
{
	int r=x;
	while(pre[r]!=r)
		r=pre[r];
	int i=x,j;
	while(i!=r)
	{
		j=pre[i];
		pre[i]=r;
		i=j;
	}
	return r;
}

void join(int x,int y)
{
	int fx=find_ancestor(x);
	int fy=find_ancestor(y);
	if(fx!=fy)
		pre[fx]=fy;
}

int main(void)
{
	bool ans;
	int T,len,status1,status2;
	scanf("%d",&T);
	while(T--)
	{
		ans=true;
		memset(exist,0,sizeof(exist));
		status1=status2=0;
		memset(indegree,0,sizeof(indegree));
		memset(outdegree,0,sizeof(outdegree));
		for(int i=0;i<30;i++)
			pre[i]=i;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",input);
			len=strlen(input);
			int start=input[0]-'a';
			int finish=input[len-1]-'a';
			exist[start]=exist[finish]=true;
			outdegree[start]++;
			indegree[finish]++;
			join(start,finish);
		}
		for(int i=0;i<26;i++)
		{
			if(indegree[i]==outdegree[i])
				continue;
			if(abs(indegree[i]-outdegree[i])==1)
			{
				if(indegree[i]>outdegree[i])
					status1++;
				else
					status2++;
			}
			else
				ans=false;

		}
		if(ans)
		{
			if(status1!=status2)
				ans=false;
			else if(status1>1)
				ans=false;
		}
		if(ans)
		{
			int temp=-1;
			for(int i=0;i<26;i++)
			{
				if(!exist[i])
					continue;
				if(temp==-1)
					temp=find_ancestor(i);
				if(find_ancestor(i)!=temp)
					ans=false;
			}
		}
		if(!ans)
			printf("The door cannot be opened.\n");
		else
			printf("Ordering is possible.\n");
	}
	return 0;
}
