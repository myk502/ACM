#include<cstdio>
#include<iostream>
using namespace std;
int a[60][60], n, m, sum = 0;
int A, B, C;
int sum_row[60], sum_col[60];

int cal_sum(int* b, int lend, int rend)//Calculate the sum of rows/columns of [lend, rend)
{
	int sum = 0;
	for(int i = lend; i < rend; i++)
		sum += b[i];
	return sum;
}

int main(void)
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int ans = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			sum += a[i][j];
			sum_row[i] += a[i][j];
			sum_col[j] += a[i][j];
		}
	cin >> A >> B >> C;
	if((A + B + C) != sum)
	{
		cout << 0 << endl;
		return 0;
	}
	//First consider rows
	for(int i = 1; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)//The three parts are:[0, i); [i, j); [j, n)
		{
			int sum1 = cal_sum(sum_row, 0, i), sum2 = cal_sum(sum_row, i, j);
			if((sum1 == A && sum2 == B) || (sum1 == B && sum2 == A) || (sum1 == A && sum2 == C) || (sum1 == C && sum2 == A))
				ans++;
			else if((sum1 == B && sum2 == C) || (sum1 == C && sum2 == B))//why should we use else if here?
				ans++;
		}
	}
	for(int i = 1; i < m; i++)
	{
		for(int j = i + 1; j < m; j++)//The three parts are:[0, i); [i, j); [j, n)
		{
			int sum1 = cal_sum(sum_col, 0, i), sum2 = cal_sum(sum_col, i, j);
			if((sum1 == A && sum2 == B) || (sum1 == B && sum2 == A) || (sum1 == A && sum2 == C) || (sum1 == C && sum2 == A))
				ans++;
			else if((sum1 == B && sum2 == C) || (sum1 == C && sum2 == B))
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
