#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 1000 + 10;
struct Point
{
	int x,y,z;
	Point(int x = 0, int y = 0,int z = 0):x(x),y(y),z(z)
	{
	}
};
Point P[maxn];
int n;
double dis[maxn][maxn],height[maxn][maxn];
double a[maxn][maxn],b[maxn];
bool visit[maxn];
double cal_dis(Point X,Point Y)
{
	double temp = (X.x - Y.x) * (X.x - Y.x);
	temp += (X.y - Y.y) * (X.y - Y.y);
	return sqrt(temp);
}

double prim(double x)
{
	double ans = 0;
	double minn,maxx = -1;
	int min_id;
	memset(visit,0,sizeof(visit));
	for(int i = 1; i <= n; i++)
	{
		a[i][i] = 0;
		for(int j = i + 1; j <= n; j++)
		{
			a[i][j] = a[j][i] = height[i][j] - x * dis[i][j];
			maxx = max(maxx,a[i][j]);
		}
	}
	maxx += 10000;
	for(int i = 1; i <= n; i++)
		b[i] = a[1][i];
	visit[1] = true;
	for(int i = 1; i < n; i++)
	{
		minn = maxx;
		for(int j = 1; j <= n; j++)
		{
			if(!visit[j] && b[j] < minn)
			{
				minn = b[j];
				min_id = j;
			}
		}
		visit[min_id] = true;
		ans += minn;
		for(int j = 1; j <= n; j++)
		{
			if(visit[j])
				continue;
			b[j] = min(b[j],a[min_id][j]);
		}
	}
	return ans;
}

int main(void)
{
	double ll,rr,mid;
	int xx,yy,zz;
	while(scanf("%d",&n) != EOF)
	{
		if(n == 0)
			break;
		for(int i = 1; i <= n;i++)
		{
			scanf("%d%d%d",&xx,&yy,&zz);
			P[i].x = xx;
			P[i].y = yy;
			P[i].z = zz;
		}
		for(int i = 1; i <= n; i++)
		{
			dis[i][i] = 0;
			height[i][i] = 0;
			for(int j = i + 1; j <= n; j++)
			{
				dis[i][j] = dis[j][i] = cal_dis(P[i],P[j]);
				height[i][j] = height[j][i] = abs(P[i].z - P[j].z);
			}
		}
		ll = rr = height[1][2]/dis[1][2];
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++)
			{
				ll = min(ll,height[i][j] / dis[i][j]);
				rr = max(rr,height[i][j] / dis[i][j]);
			}
		while(rr - ll > 0.00000001)
		{
			mid = (ll + rr) / 2;
			if(prim(mid) > 0)
				ll = mid;
			else
				rr = mid;
		}
		printf("%.3f\n",ll);
	}
	return 0;
}
