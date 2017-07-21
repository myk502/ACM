#include<stdio.h>
#include<string.h> 
#include<queue>
#include<algorithm>
using namespace std;

const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
struct myk{
	int x;
	int y;
	int t;
};
myk temp;
int step[25][25][2],visit[25][25][2];
char a[25][25],b[25][25][2];
int temp_x,temp_y,temp_t,m,n,start_x,start_y,end_x,end_y,xx,yy,tt;
queue <myk> q;
bool panduan(int aa,int bb)
{
	if((aa>=1)&&(aa<=n)&&(bb>=1)&&(bb<=m))
		return true;
	else
		return false; 
}
bool panduan2(int xx,int yy,int tt,int i)
{
	if((b[xx][yy][tt]!='-')&&(b[xx][yy][tt]!='|'))
		return true;
	if(b[xx][yy][tt]=='-')
	{
		if((i==2)||(i==3))
			return true;
		else
			return false;
	}
	if(b[xx][yy][tt]=='|')
	{
		if((i==0)||(i==1))
			return true;
		else
			return false;
	}
}
void duru(void)
 {
 	
 	for(int i=1;i<=n;i++)
 	for(int j=1;j<=m;j++)
 	{
 		scanf("\n");
 		scanf("%c",&a[i][j]);
 		if(a[i][j]=='S')
 		{
 			start_x=i;
 			start_y=j;
		}
		if(a[i][j]=='T')
		{
			end_x=i;
			end_y=j;
		}
		if(a[i][j]=='-')
		{
			b[i][j][0]='|';
			b[i][j][1]='-'; 
		} 
		if(a[i][j]=='|')
		{
			b[i][j][0]='-';
			b[i][j][1]='|'; 
		}
	}
	
 	
 }
 void initialization(void)
 {
 	while(!q.empty())
 		q.pop();
 	memset(visit,0,sizeof(visit));
 	memset(step,-1,sizeof(step));
 	temp.x=start_x;
 	temp.y=start_y;
 	temp.t=0;
 	q.push(temp);
 	visit[start_x][start_y][0]=1;
 	step[start_x][start_y][0]=0;
 }
void push(int xx,int yy,int tt)
{
	temp.x=xx;
	temp.y=yy;
	temp.t=tt;
	q.push(temp);
	visit[xx][yy][tt]=1;
	if((b[xx][yy][tt]!='-')&&(b[xx][yy][tt]!='|'))
		step[xx][yy][tt]=1+step[temp_x][temp_y][temp_t];
	else
		step[xx][yy][tt]=step[temp_x][temp_y][temp_t];
} 
void bfs(void)
{
 	while(!q.empty())
 	{
 		temp=q.front();
 		temp_x=temp.x;
 		temp_y=temp.y;
 		temp_t=temp.t;
 		if((b[temp_x][temp_y][temp_t]=='-'))
 			for(int i=2;i<=3;i++)
 			{
 				xx=dx[i]+temp_x;
 				yy=dy[i]+temp_y;
 				tt=1-(temp_t);
 				if((panduan(xx,yy))&&(panduan2(xx,yy,tt,i))&&(!visit[xx][yy][tt])&&(b[xx][yy][tt]!='*'))
 				{
 					push(xx,yy,tt);
 					if((xx==end_x)&&(yy==end_y))
 						return ;
				}
	        }
	    if((b[temp_x][temp_y][temp_t]=='|'))
 			for(int i=0;i<=1;i++)
 			{
 				xx=dx[i]+temp_x;
 				yy=dy[i]+temp_y;
 				tt=1-(temp_t);
 				if((panduan(xx,yy))&&(panduan2(xx,yy,tt,i))&&(!visit[xx][yy][tt])&&(b[xx][yy][tt]!='*'))
 				{
 					push(xx,yy,tt);
 					if((xx==end_x)&&(yy==end_y))
 						return ;
				}
	        }
 		if((b[temp_x][temp_y][temp_t]!='|')&&(b[temp_x][temp_y][temp_t]!='-'))
 			for(int i=0;i<4;i++)
 		{
 			xx=dx[i]+temp_x;
 			yy=dy[i]+temp_y;
 			tt=1-(temp_t);
 			if((panduan(xx,yy))&&(panduan2(xx,yy,tt,i))&&(!visit[xx][yy][tt])&&(b[xx][yy][tt]!='*'))
 			{
 				push(xx,yy,tt);
 				if((xx==end_x)&&(yy==end_y))
 					return ;
			}
	    }
	    
	}
} 
 int main(void)
 {
 	while((scanf("%d%d",&n,&m)!=EOF))
 	{
 		
 		duru();
 		initialization();
 		bfs();
 		printf("%d\n",max(step[end_x][end_y][0],step[end_x][end_y][1]));
	}
 }
