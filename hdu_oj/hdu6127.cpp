#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
const int maxn=50000+10;
long long sum[maxn],dp[maxn];
struct Point
{
	long long x,y,val;
	Point(long long xx=0LL,long long yy=0LL,long long value=0LL):x(xx),y(yy),val(value)
	{

	}
	friend Point operator -(const Point& X)
	{
		return Point(-X.x,-X.y);
	}
};
Point P[maxn];
typedef Point Vector;
long long Cross(Vector A,Vector B)
{
	return A.x*B.y-A.y*B.x;
}
int cmp(Point A,Point B)
{
	return Cross(A,B)>0LL;
}
vector<Point> v;
int main(void)
{
	ios::sync_with_stdio(false);
	long long xx,yy,zz,ans;
	bool flag;
	int T;
	cin>>T;
	while(T--)
	{
		flag=false;
		v.clear();
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>xx>>yy>>zz;
			v.push_back(Point(xx,yy,zz));
		}
		int id=0;
		for(auto it:v)
		{
			if(it.y>0LL)
				P[id++]=it;
			else if((it.y==0LL)&&(it.x>0LL))
			{
				flag=true;
				P[id++]=it;
			}
		}
		sort(P,P+id,cmp);
		int backup=id;
		for(auto it:v)
		{
			if(it.y<0LL)
				P[id++]=it;
			else if((it.y==0LL)&&(it.x<0LL))
				P[id++]=it;
		}
		sort(P+backup,P+n,cmp);
		sum[0]=0LL;
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]+P[i-1].val;
		ans=0;
		id=backup;
		if((id>0) && (id<n))
		{
			int ll=0,rr=id;
			if(!flag)
				ans=sum[id]*(sum[n]-sum[id]);
			while((ll<id) || (rr<n))
			{
				if(Cross(-P[ll],P[rr])>0)
					ll++;
				else
					rr++;
				long long lsum=sum[rr]-sum[ll];
				long long rsum=sum[n]-sum[rr]+sum[ll];
				ans=max(ans,lsum*rsum);
				if((ll==id-1)&&(rr==n-1))
					break;

			}
			cout<<ans<<endl;
			continue;
		}
		dp[0]=0;
		for(int i=1;i<n;i++)
		{
			dp[i]=dp[i-1]+( (sum[n]-sum[i]-sum[i-1])*P[i-1].val );
			ans=max(ans,dp[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}

