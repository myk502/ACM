#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;

int visit[20];
int map[7][7];
int ans;

void Flip()
{
    int x,y;
    for(int i=1; i<=16; ++i)
    {
        if(visit[i]) //如果标记为 1，表示这个棋子要翻 
        {
            x = i/4 + 1; // 计算出棋子再棋盘中的位置 
            y = i % 4;
            if(i%4 == 0)
            {
                x--;
                y = 4;
            }
            map[x][y] = -map[x][y]; //翻自己 
            map[x-1][y] = -map[x-1][y]; //翻上 
            map[x+1][y] = -map[x+1][y]; //翻下 
            map[x][y+1] = -map[x][y+1]; //翻左 
            map[x][y-1] = -map[x][y-1]; //翻右 
        }
    }
    return;
}

int Judge() //判断是否为同一种颜色 
{
    for(int i=1; i<=4; ++i) 
        for(int j=1; j<=4; ++j)
        {
            if(map[i][j] != map[1][1])
                return 0;
        }
    return 1;
}

void DFS(int num,int times,int who) //num表示总共要翻几个琪，times表示已经翻了几个，who表示上一次翻的是哪一个棋 
{
    if(ans < inf) return; //如果已经找到答案了，就不用往下了 
    if(times == num) //当翻棋的数量达到了，就进行判断 
    {
        Flip(); //翻棋 
        if(Judge()) //判断全为同一种颜色 
        {
            ans = num;    //记录答案 
        }
        else Flip(); //否则将棋盘恢复原状 
        return;
    }
    
    for(int i=who+1; i<=16; ++i) //从上一个翻的棋子的下一个开始选择，这样可以防止出现重复的情况 
    {
        visit[i] = 1;//选中的标记为 1 
        DFS(num,times+1,i); //搜索翻下一个的情况， 
        visit[i] = 0; //清除标记 
    }
}

int main()
{
    char first;
    memset(map,0,sizeof(map));
    for(int i=1; i<=4; ++i)
    for(int j=1; j<=4; ++j)
    {
        cin>>first;//依次输入棋子 
        if(first == 'w')
            map[i][j] = 1; //若为白棋，记为 1
        else map[i][j] = -1; //黑记为为 -1
    }
    
    ans = inf; //初始化答案为无穷大 
    for(int i=0; i<=16; ++i) //枚举翻棋子数 
    {
        memset(visit,0,sizeof(visit)); //每种情况开始前要将标记数组初始化为 0 
        DFS(i,0,0); //搜索翻这么多棋子的所有情况 
        if(ans < inf) break; //如果答案不为无穷大，表示已经有结果了，不用搜了 
    }
    
    if(ans == inf) cout<<"Impossible"<<endl;
    else cout<<ans<<endl;
    return 0;
}
