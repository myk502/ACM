#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int a[110][110],n,m;
int row_min,row_max,col_min,col_max;
void readin(void)
{
	row_min=col_min=200;
	row_max=col_max=-1;
	string input;
	for(int i=1;i<=n;i++)
	{
		cin>>input;
		for(int j=1;j<=m;j++)
		{
			char temp=input[j-1];
			if(temp=='W')
				a[i][j]=0;
			else
			{
				a[i][j]=1;
				row_min=min(row_min,i);
				row_max=max(row_max,i);
				col_min=min(col_min,j);
				col_max=max(col_max,j);
			}
		}
	}

}
int main(void)
{
	int ans=0;
	int _size;
	cin>>n>>m;
	readin();
	if(row_min==200)
	{
		printf("1\n");
		return 0;
	}
	int jj=col_max-col_min+1;
	int ii=row_max-row_min+1;
	_size=max(ii,jj);
	if((_size>n)||(_size>m))
		printf("-1\n");
	else
	{
		for(int i=row_min;i<=row_max;i++)
			for(int j=col_min;j<=col_max;j++)
			{
				if(a[i][j]==0)
					ans++;
			}
		if(ii<_size)
			ans+=(jj-ii)*jj;
		if(jj<_size)
			ans+=(ii-jj)*ii;
		cout<<ans<<endl;
	}
	return 0;
}
