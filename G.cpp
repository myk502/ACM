#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node
{
	int x,y;
	Node(int x = 0,int y = 0):x(x),y(y)
	{
	}
};
Node A,B,C,D;
bool mysolve(Node a,Node b,Node c)
{
	if(a.x == b.x && (a.y + b.y == c.x || a.y + b.y == c.y))
		return true;
	if(a.x == b.y && (a.y + b.x == c.x || a.y + b.x == c.y))
		return true;
	if(a.y == b.x && (a.x + b.y == c.x || a.x + b.y == c.y))
		return true;
	if(a.y == b.y && (a.x + b.x == c.x || a.x + b.x == c.y))
		return true;
	return false;
}
bool solve(Node a,Node b,Node c)
{
	int cnt[1010];
	memset(cnt,0,sizeof(cnt));
	if(a.x != a.y)
	{
		cnt[a.x]++;
		cnt[a.y]++;
	}
	else
		cnt[a.x]++;
	if(b.x != b.y)
	{
		cnt[b.x]++;
		cnt[b.y]++;
	}
	else
		cnt[b.x]++;
	if(c.x != c.y)
	{
		cnt[c.x]++;
		cnt[c.y]++;
	}
	else
		cnt[c.x]++;
	for(int i = 1; i <= 1000;i++)
		if(cnt[i] >= 3)
			return true;
	if(mysolve(a,b,c) || mysolve(a,c,b) || mysolve(b,c,a))
		return true;
	return false;
}
int main(void)
{
	int T;
	scanf("%d",&T);
	bool flag;
	while(T--)
	{
		scanf("%d%d%d%d%d%d%d%d",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y,&D.x,&D.y);
		flag = false;
		if(solve(A,B,C) || solve(A,B,D) || solve(A,C,D) || solve(B,C,D))
			flag = true;
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
