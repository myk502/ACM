#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<vector>
using namespace std;
char a[2020][2020];
bitset<2020> in[2020],out[2020],inp[2020],outp[2020],inq[2020],outq[2020];
bitset<2020> temp;
int n;
int main(void)
{
	bool flag;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		flag = true;

		scanf("%d",&n);
		for(int i = 1; i <= n; i++)
			scanf("%s",a[i] + 1);
		for(int i = 0; i < 2020; i++)
		{
			in[i].reset();
			out[i].reset();
			inp[i].reset();
			inq[i].reset();
			outp[i].reset();
			outq[i].reset();
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(a[i][j] != '-')
				{
					out[i][j] = 1;
					in[j][i] = 1;
				}
				if(a[i][j] == 'P')
				{
					outp[i][j] = 1;
					inp[j][i] = 1;
				}
				if(a[i][j] == 'Q')
				{
					outq[i][j] = 1;
					inq[j][i] = 1;
				}
			}
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				int ii = i, jj = j;
				if(a[i][j] == '-')
					swap(ii,jj);
				temp = in[ii] & out[jj];
				if(temp.any() == true)
					flag =false;
				if(!flag)
					goto myk;
				if(a[ii][jj] == 'P')
					temp = outq[ii] & inq[jj];
				else
					temp = outp[ii] & inp[jj];
				if(temp.any() == true)
				{
					flag = false;
					goto myk;
				}
			}
		}
   myk:if(flag)
			printf("T\n");
		else
			printf("N\n");
	}
	return 0;
}
