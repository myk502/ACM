#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
bool exist[210][210];
struct Point
{
	int x,y;
	Point(int x=-1,int y=-1):x(x),y(y)
	{

	}
	friend ostream& operator <<(ostream& out,const Point& X)
	{
		printf("(%d,%d)",X.x,X.y);
		return out;
	}
};
Point P[210],A,B,C,D;
int n,xx1,xx2,xx3,xx4,yy1,yy2,yy3,yy4,ans;
int judge(Point P,Point A,Point B)
{
	int x_lowerbound=min(A.x,B.x);
	int x_upperbound=max(A.x,B.x);
	int y_lowerbound=min(A.y,B.y);
	int y_upperbound=max(A.y,B.y);
	int xx=P.x,yy=P.y;
	if((xx<x_lowerbound) || (xx>x_upperbound) || (yy<y_lowerbound) || (yy>y_upperbound))
		return -1;
	if((xx==x_lowerbound) || (xx==x_upperbound) || (yy==y_lowerbound) || (yy==y_upperbound) )
		return 0;
	return 1;
}
int cal(Point ,Point );
bool solve(void)
{
	bool flag;
	int temp=0;
	flag=true;
	for(int i=min(xx1,xx2);i<=max(xx1,xx2);i++)
	{
		for(int j=min(yy1,yy2);j<=max(yy1,yy2);j++)
		{
			int val=judge(Point(i,j),C,D);
			if(temp==0)
				temp=val;
			if((val==0) || (val!=temp))
				flag=false;
		}
	}
	if(flag)
	{
		if(temp==1)
			ans=max(ans,max(cal(A,B),cal(C,D)));
		else
			ans=max(ans,cal(A,B)+cal(C,D));
		return flag;
	}
	flag=true;
	temp=0;
	for(int i=min(xx3,xx4);i<=max(xx3,xx4);i++)
	{
		for(int j=min(yy3,yy4);j<=max(yy3,yy4);j++)
		{
			int val=judge(Point(i,j),A,B);
			if(temp==0)
				temp=val;
			if((val==0) || (val!=temp))
				flag=false;
		}
	}
	if(flag)
	{
		if(temp==1)
			ans=max(ans,max(cal(A,B),cal(C,D)));
		else
			ans=max(ans,cal(A,B)+cal(C,D));
		return flag;
	}
	return false;

}

int cal(Point A,Point B)
{
	int x_lowerbound=min(A.x,B.x);
	int x_upperbound=max(A.x,B.x);
	int y_lowerbound=min(A.y,B.y);
	int y_upperbound=max(A.y,B.y);
	return (x_upperbound-x_lowerbound)*(y_upperbound-y_lowerbound);
}

int main(void)
{
	int temp_xx,temp_yy;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		ans=-1;
		memset(exist,0,sizeof(exist));
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&temp_xx,&temp_yy);
			P[i]=Point(temp_xx,temp_yy);
			exist[temp_xx][temp_yy]=true;
		}
		for(int i=0;i<n;i++)
		{
			A=P[i];
			xx1=A.x;
			yy1=A.y;
			for(int j=i+1;j<n;j++)
			{
				B=P[j];
				xx2=B.x;
				yy2=B.y;
				/*
				if((xx2<=xx1) || (yy1<=yy2))
					continue;
				*/
				if(!exist[xx1][yy2] || !exist[xx2][yy1])
					continue;
				if(cal(A,B)==0)
					continue;
				for(int k=j+1;k<n;k++)
				{
					C=P[k];
					xx3=C.x;
					yy3=C.y;
					for(int m=k+1;m<n;m++)
					{
						D=P[m];
						xx4=D.x;
						yy4=D.y;
						/*
						if((xx3>=xx4) || (yy3<=yy4))
							continue;
						*/
						if(!exist[xx3][yy4] || !exist[xx4][yy3])
							continue;
						if(cal(C,D)==0)
							continue;
						solve();

					}
				}
			}
		}
		if(ans==-1)
			printf("imp\n");
		else
			printf("%d\n",ans);

	}
	return 0;
}
