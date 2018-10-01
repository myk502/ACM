#include<bits/stdc++.h>
using namespace std;
int a[15][15];
char str[30][100];
int dx, dy, xx, yy;
bool visit[30][30];
int main(void)
{
	for(int i = 1; i <= 9; i++)
	{
		gets(str[i]);
		while(str[i][0] == '\n' || str[i][0] == '\0')
			gets(str[i]);
		for(int id = 1, j = 0; id <= 9; j++)
		{
			if(isspace(str[i][j]))
				continue;
			char temp = str[i][j];
			if(temp == '.')
				a[i][id] = 0;
			if(temp == 111)
				a[i][id] = 1;
			if(temp == 120)
				a[i][id] = -1;
			id++;
		}
	}
	scanf("%d%d", &xx, &yy);
	memset(visit, 0, sizeof(visit));
	while(xx - 3 > 0)
		xx -= 3;
	while(yy -3 > 0)
		yy -= 3;
	dx = (xx - 1) * 3;
	dy = (yy - 1) * 3;
	bool flag = false;//whether there is empty cells in that area
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 3; j++)
		{
			if(a[i+dx][j+dy] == 0)
				flag = true;
			visit[i+dx][j+dy] = true;
		}
	if(flag)
	{
		for(int i = 1; i <= 9; i++)
		{
			for(int j = 1; j <= 9; j++)
			{
				if(a[i][j] == -1)
					printf("%c", 120);
				if(a[i][j] == 1)
					printf("%c", 111);
				if(a[i][j] == 0 && visit[i][j])
					printf("!");
				if(a[i][j] == 0 && !visit[i][j])
					printf(".");
				if(j == 3 || j == 6)
					printf(" ");
			}
			printf("\n");
			if(i == 3 || i == 6)
				printf("\n");
		}
	}
	else
	{
		for(int i = 1; i <= 9; i++)
		{
			for(int j = 1; j <= 9; j++)
			{
				if(a[i][j] == -1)
					printf("%c", 120);
				if(a[i][j] == 1)
					printf("%c", 111);
				if(a[i][j] == 0)
					printf("!");
				if(j == 3 || j == 6)
					printf(" ");
			}
			printf("\n");
			if(i == 3 || i == 6)
				printf("\n");
		}
	}
	return 0;
}
