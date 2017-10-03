#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 100000;
int num[maxn];
struct Node
{
	int num,op2,op3;
	Node(int num = 0,int op2 = 0,int op3 = 0):num(num),op2(op2),op3(op3)
	{
	}
};
queue<Node> q;
bool visit[maxn][4][3];
int operation(int x,int id,int op)//id = 0,1,2,3,4
{
	char temp[10];
	for(int i = 4; i >= 0;i--)
	{
		temp[i] = (x % 10) + '0';
		x /= 10;
	}
	temp[5] = '\0';
	int tempnum = temp[id] - '0';
	if(op == 2)
		tempnum = (tempnum + 1) % 10;
	if(op == 3)
		tempnum = (tempnum * 2) % 10;
	if(op != 1)
		temp[id] = tempnum + '0';
	else
		swap(temp[id],temp[id + 1]);
	int ans = 0;
	for(int i = 0; i < 5; i++)
	{
		ans += temp[i] - '0';
		ans *= 10;
	}
	ans /= 10;
	return ans;
}
void init(void)
{
	memset(num,-1,sizeof(num));
	num[12345] = 0;
	q.push(Node(12345,0,0));
	memset(visit,0,sizeof(visit));
	visit[12345][0][0] = true;
	while(!q.empty())
	{
		Node temp = q.front();
		//printf("We are visiting %d,num is %d.\n",temp.num,num[temp.num]);
		q.pop();
		int newval;
		if(temp.op2 < 3)//we can use op2
		{
			for(int i = 0; i < 5;i++)
			{
				newval = operation(temp.num,i,2);
				if(!visit[newval][temp.op2 + 1][temp.op3])
				{
					visit[newval][temp.op2 + 1][temp.op3] = true;
					q.push(Node(newval,temp.op2 + 1,temp.op3));
				}
				if(num[newval] == -1)
					num[newval] = num[temp.num] + 1;
				num[newval] = min(num[newval],num[temp.num] + 1);
			}
		}
		if(temp.op3 < 2)
		{
			for(int i = 0; i < 5;i++)
			{
				newval = operation(temp.num,i,3);
				if(!visit[newval][temp.op2][temp.op3 + 1])
				{
					visit[newval][temp.op2][temp.op3 + 1] = true;
					q.push(Node(newval,temp.op2,temp.op3 + 1));
				}
				if(num[newval] == -1)
					num[newval] = num[temp.num] + 1;
				num[newval] = min(num[newval],num[temp.num] + 1);
			}
		}
		for(int i = 0 ; i < 4;i++)
		{
			newval = operation(temp.num,i,1);
			if(!visit[newval][temp.op2][temp.op3])
			{
				visit[newval][temp.op2][temp.op3] = true;
				q.push(Node(newval,temp.op2,temp.op3));
			}
			if(num[newval] == -1)
				num[newval] = num[temp.num] + 1;
			num[newval] = min(num[newval],num[temp.num] + 1);
		}

	}
}

int n;

int main(void)
{
	init();
	while(scanf("%d", &n) != EOF) {
		printf("%d\n", num[n]);
	}
	return 0;
}
