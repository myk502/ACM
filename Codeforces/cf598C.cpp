#include<cstdio>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
int n;
struct Vector
{
	int x,y,id;
	long double angle;
	Vector(int xx=-1,int yy=-1,int id=-1):x(xx),y(yy),id(id)
	{

	}
	bool operator < (const Vector& X)const
	{
		return this->angle < X.angle;
	}
};
Vector P[100000+10];
int main(void)
{
	int xx,yy;
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d%d",&xx,&yy);
		P[i] = Vector(xx,yy,i);
		P[i].angle = atan2(yy,xx);
	}
	sort(P,P+n);
	pii ans = make_pair(-1,-1);
	long double minn = 10000;
	for(int i = 1; i < n; i++)
	{
		long double temp = P[i].angle - P[i-1].angle;
		if(temp < minn)
		{
			minn = temp;
			ans = make_pair(P[i].id + 1,P[i-1].id + 1);
		}
	}
	if(P[0].angle < 0)
	{
		long double temp = 2*acos(-1) - P[n-1].angle + P[0].angle;
		if(temp < minn)
		{
			ans = make_pair(P[0].id + 1, P[n-1].id + 1);
		}
	}
	printf("%d %d\n",ans.first,ans.second);
	return 0;
}
