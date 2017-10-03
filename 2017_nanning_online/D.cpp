#include<bits/stdc++.h>
using namespace std;
double a,b;
double d[25][25],dmin[25][25];
const double INF = 100000000;
string input;
int n,m;
typedef pair<int,int> pii;
pii pre[25][25];
pii init = make_pair(-1,-1);
stack<pii> s;
int main(void)
{
	double temp;
	cin>>a>>b;
	n = 0;
	scanf("\n");
	while(getline(cin,input))
	{
		n++;
		stringstream ss(input);
		m = 0;
		while(ss >> temp)
		{
			d[++m][n] = temp;
		}

	}
	for(int i = 1;i <= m;i++)
		for(int j = 1;j <= n;j++)
		{
			dmin[i][j] = INF + 100;
			pre[i][j] = init;
		}
	dmin[1][1] = d[1][1];
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			double val1 = INF;
			if(i-2 >=1 && j-1 >=1)
				val1 = dmin[i-2][j-1] + a*(d[i-1][j] + d[i][j]);
			double val2 = INF;
			if(i-1 >=1 && j-1>=1)
				val2 = dmin[i-1][j-1] + b*d[i][j];
			double val3 = INF;
			if(i-1>=1 && j-2>=1)
				val3 = dmin[i-1][j-2]+a*(d[i][j-1] + d[i][j]);
			if(dmin[i][j] > val1)
			{
				dmin[i][j] = val1;
				pre[i][j] = make_pair(i-2,j-1);
			}
			if(dmin[i][j] > val2)
			{
				dmin[i][j] = val2;
				pre[i][j] = make_pair(i-1,j-1);
			}
			if(dmin[i][j] > val3)
			{
				dmin[i][j] = val3;
				pre[i][j] = make_pair(i-1,j-2);
			}
		}
	}
	printf("%.6lf\n",dmin[m][n]);
	pii x = make_pair(m,n),y;
	while(x != make_pair(1,1))
	{
		s.push(x);
		y = pre[x.first][x.second];
		x = y;
		if(x == make_pair(1,1))
		{
			s.push(x);
			break;
		}
	}
	while(!s.empty())
	{
		pii temp = s.top();
		printf("(%d,%d)\n",temp.first,temp.second);
		s.pop();
	}
	return 0;
}
