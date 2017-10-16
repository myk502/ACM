#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct Point
{
	long long x,y;
	Point(long long x = 0,long long y = 0):x(x),y(y)
	{
	}
};
typedef Point Vector;
Vector operator + (Vector A,Vector B)
{
	return Vector(A.x + B.x , A.y + B.y);
}    
Vector operator - (Vector A,Vector B)
{
	return Vector(A.x - B.x , A.y - B.y);
}
bool operator <(const Point& a,const Point& b)
{
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
const double eps = 1e-6;
int dcmp(const double& x)
{
	if(fabs(x) < eps)
		return 0;
	else
		return x < 0 ? -1 : 1;
}
bool operator == (const Point& a,const Point& b)
{
	return (a.x - b.x) == 0 && (a.y - b.y) == 0;
}
long long Dot(Vector A,Vector B)
{
	return A.x * B.x + A.y * B.y;
}

long long Cross(Vector A,Vector B)
{
	return A.x * B.y - A.y * B.x;
}
long long Length(Vector A)
{
	return Dot(A , A);
}
double DistanceToSegement(Point P,Point A,Point B)
{
	if(A == B)
		return sqrt(Length(P - A));
	Vector v1 = B - A, v2 = P - A, v3 = P - B;
	if((Dot(v1, v2)) < 0LL)
		return sqrt(Length(v2));
	else if((Dot(v1, v3)) > 0LL)
		return sqrt(Length(v3));
	else return fabs(Cross(v1, v2)) / sqrt(Length(v1));
}
int n;
const int maxn = 100000 + 10;
Point P[maxn];
int main(void)
{
	long long xx,yy;
	scanf("%d",&n);
	for(int i = 0 ; i < n;i++)
	{
		cin>>xx>>yy;
		P[i] = Point(xx,yy);
	}
	long long dis = Length(P[1] - P[0]);
	int id = 1;
	for(int i = 2; i < n;i++)
	{
		long long temp = Length(P[i] - P[0]);
		if(temp < dis)
		{
			id = i;
			dis = temp;
		}
	}
	double diss = -1;
	int ans = -1;
	for(int i = 1; i < n; i++)
	{
		if( i == id )
			continue;
		double temp = DistanceToSegement(P[i],P[0],P[id]);
		if(Cross(P[i] - P[0],P[id] - P[0]) == 0LL)
			continue;
		if( (dcmp(diss + 1) == 0) || temp < diss)
		{
			diss = temp;
			ans = i;
		}
	}
	printf("1 %d %d\n",id + 1,ans + 1);

	return 0;
}
