#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
struct Point
{
	int aa,bb,cc,dd;
	Point(int aa = 0, int bb = 0, int cc = 0, int dd = 0):aa(aa),bb(bb),cc(cc),dd(dd)
	{

	}
	bool operator == (const Point &X)const
	{
		return (aa == X.aa) && (bb == X.bb) && (cc == X.cc) && (dd == X.dd);
	}
	Point operator +(const Point& X)const
	{
		return Point((aa + X.aa), (bb + X.bb), (cc + X.cc), (dd + X.dd));
	}
};
queue<Point> q;
vector<Point> v1, v2;
void init(void)
{
	Point a_win = Point(3,0,0,0);
	Point b_win = Point(0,3,0,0);
	Point c_win = Point(0,0,3,0);
	Point d_win = Point(0,0,0,3);
	v1.clear();
	v2.clear();
	//a vs b
	v2.push_back(a_win);
	v2.push_back(b_win);
	v2.push_back(Point(1,1,0,0));
	//a vs c
	for(auto it:v2)
	{
		v1.push_back(it + a_win);
		v1.push_back(it + c_win);
		v1.push_back(it + Point(1,0,1,0));
	}
	//a vs d
	v2.clear();
	for(auto it:v1)
	{
		v2.push_back(it + a_win);
		v2.push_back(it + d_win);
		v2.push_back(it + Point(1,0,0,1));
	}
	//b vs c
	v1.clear();
	for(auto it:v2)
	{
		v1.push_back(it + b_win);
		v1.push_back(it + c_win);
		v1.push_back(it + Point(0,1,1,0));
	}
	//b vs d
	v2.clear();
	for(auto it:v1)
	{
		v2.push_back(it + b_win);
		v2.push_back(it + d_win);
		v2.push_back(it + Point(0,1,0,1));
	}
	//c vs d
	v1.clear();
	for(auto it:v2)
	{
		v1.push_back(it + c_win);
		v1.push_back(it + d_win);
		v1.push_back(it + Point(0,0,1,1));
	}

}

int main(void)
{
	int T, a, b, c, d;
	init();
	scanf("%d",&T);
	int cnt = 0;
	for(int ii = 1; ii <= T; ii++)
	{
		cnt = 0;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("Case #%d: ",ii);
		for(auto it:v1)
		{
			if(it == Point(a,b,c,d))
				cnt++;
		}
		if(cnt == 1)
			printf("Yes\n");
		else if(cnt == 0)
			printf("Wrong Scoreboard\n");
		else
			printf("No\n");
	}

	return 0;
}
