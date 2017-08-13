#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
typedef pair<int,int> pii;
struct myk
{
	int up=10000,bottom=-1,left=10000,right=-1;
	pii stripe(void)
	{
		int xx=bottom-up;
		int yy=right-left;
		return make_pair(xx,yy);
	}
};
myk color[4];
int n,m;
string input;
int a[110][110];
int main(void)
{
	bool ans=false;
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>input;
		int len=input.length();
		for(int j=0;j<len;j++)
		{
			char it=input[j];
			if(it=='R')
				a[i][j+1]=0;
			if(it=='G')
				a[i][j+1]=1;
			if(it=='B')
				a[i][j+1]=2;
		}
	}
	//cout<<"mark1"<<endl;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int temp=a[i][j];
			color[temp].up=min(color[temp].up,i);
			color[temp].bottom=max(color[temp].bottom,i);
			color[temp].left=min(color[temp].left,j);
			color[temp].right=max(color[temp].right,j);
			
		}
	if( (color[0].stripe()==color[1].stripe()) && (color[1].stripe()==color[2].stripe()) )	
		ans=true;
	//cout<<"mark2"<<endl;
	if(ans)
	{
		for(int k=0;k<3;k++)
		{
			for(int i=color[k].up;i<=color[k].bottom;i++)
				for(int j=color[k].left;j<=color[k].right;j++)
				{
					if(a[i][j]!=k)
						ans=false;
				}
		}
	}
	if(ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return  0;
}
