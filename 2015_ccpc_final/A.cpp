#include<cstdio>
#include<iostream>
#include<cmath>
int a[3][3],origin[3][3];
void rotate(void)
{
	int b[3][3];
	b[1][1] = a[2][1];
	b[1][2] = a[1][1];
	b[2][1] = a[2][2];
	b[2][2] = a[1][2];
	for(int i = 1; i <= 2; i++)
		for(int j = 1; j <= 2; j++)
			a[i][j] = b[i][j];
}
bool judge(void)
{
	bool flag = true;
	for(int i = 1; i <= 2; i++)
		for(int j = 1; j <= 2; j++)
			if(a[i][j] != origin[i][j])
				flag = false;
	return flag;
}
int main(void)
{
	int T;
	scanf("%d", &T);
	for(int ii = 1; ii <= T; ii++)
	{
		scanf("%d%d%d%d", &origin[1][1], &origin[1][2], &origin[2][1], &origin[2][2]);
		scanf("%d%d%d%d",&a[1][1], &a[1][2], &a[2][1], &a[2][2]);
		bool ans = judge();
		for(int i = 1; i < 4; i++)
		{
			rotate();
			if(judge())
				ans = true;
		}
		if(ans)
			printf("Case #%d: POSSIBLE\n", ii);
		else
			printf("Case #%d: IMPOSSIBLE\n", ii);
	}
	return 0;
}
