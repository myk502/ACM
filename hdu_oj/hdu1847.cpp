#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int sg[1010];
bool visit[15];
void init(void)
{
	sg[0]=0;
	for(int i=1;i<=1000;i++)
	{
		memset(visit,0,sizeof(visit));
		for(int j=0;j<10;j++)
		{
			if((1<<j)>i)
				break;
			int id=i-(1<<j);
			visit[sg[id]]=true;

		}
		for(int j=0;j<10;j++)
			if(!visit[j])
			{
				sg[i]=j;
				break;
			}
		
	}
}
int main(void)
{
	init();
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n)
	{
		if(sg[n]==0)
			cout<<"Cici"<<endl;
		else
			cout<<"Kiki"<<endl;
	}
	return 0;
}
