#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;

const int MAX = 1003;
const int dirx[5] = {0,0,1,0,-1};
const int diry[5] = {0,1,0,-1,0};

bool visit[MAX][MAX];
int map[MAX][MAX];
int wan[MAX][MAX];
int n,m,bx,by;
bool mark;

bool yes(int x,int y,int dir){
	int dx = bx - x;
	int dy = by - y;
	if(dx!=0)dx = dx/abs(dx);
	if(dy!=0)dy = dy/abs(dy);
	if(dx==dirx[dir] && dy==diry[dir])return true;
	else return false;
}

void dfs(int x,int y,int cnt,int dir){
	int i,tx,ty;
	if(mark)return;
	if(x<1 || y<1 || x>n || y>m || cnt>2)return;
	//注意下面几个剪枝的顺序，顺序搞错了就会出错，因为最后一个元素非0
	if(x==bx && y==by){
		mark = true;
		return;
	}
	if(cnt==2 && !yes(x,y,dir))return;//这个剪枝不强力，加了此剪枝时间只减少了18ms
	if(map[x][y]!=0)return;
	if(wan[x][y]!=-1 && wan[x][y]<=cnt)return;
	wan[x][y] = cnt;
	for(i=1;i<=4;++i){
		tx = x + dirx[i];
		ty = y + diry[i];
		if(dir!=i){
			dfs(tx,ty,cnt+1,i);
		}else{
			dfs(tx,ty,cnt,i);
		}
	}
}

int main(){
    freopen("E:\\in.txt","r",stdin);
	freopen("E:\\out.txt","w",stdout);
	int i,j,t,ax,ay;
	while(scanf("%d %d",&n,&m)!=EOF){
		if(n==0 && m==0)break;
		for(i=1;i<=n;++i){
			for(j=1;j<=m;++j){
				scanf("%d",&map[i][j]);
			}
		}
		scanf("%d",&t);
		while(t--){
			memset(wan,-1,sizeof(wan));
			scanf("%d %d %d %d",&ax,&ay,&bx,&by);
			mark = false;
			if(map[ax][ay]!=map[bx][by] || map[ax][ay]==0||((ax==bx)&&(ay==by))){
				printf("NO\n");
				continue;
			}
			wan[ax][ay] = 0;
			for(i=1;i<=4;++i){
				dfs(ax+dirx[i],ay+diry[i],0,i);
			}
			if(mark){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}

    return 0;
}
