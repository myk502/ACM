#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=1000000;
int t,group[maxn];//group[i] is the group of i
bool in_queue[1000+10];
typedef queue<int> Queue;
Queue Q[1000+10];//Q[i] is the ith group
Queue q;//q is a queue of groups

void init(void)
{
    int temp;
    memset(group,-1,sizeof(group));
    memset(in_queue,0,sizeof(in_queue));
    while(!q.empty())
        q.pop();
    int n;//id is the id of team,n is the number of members of the team
    for(int id=0;id<t;id++)
    {
        scanf("%d",&n);
        while(!Q[id].empty())
            Q[id].pop();
        for(int j=0;j<n;j++)
        {
            scanf("%d",&temp);
            group[temp]=id;
        }
    }
}

void push(int x)
{
    int y=group[x];
    if(in_queue[y])//if there is another group memeber in queue
        Q[y].push(x);
    else
    {
        in_queue[y]=true;
        q.push(y);
        Q[y].push(x);
    }
}
int pop(void)
{
    int y=q.front();
    int ans=Q[y].front();
    if(Q[y].empty())
        printf("warning1!,y=%d\n",y);
    Q[y].pop();
    if(Q[y].empty())
    {
        if(q.empty())
            printf("warning2!\n");
        q.pop();
        in_queue[y]=false;
    }
    return ans;
}

int main(void)
{
    char input[10];
    int cas=0,x;
    while(scanf("%d",&t)!=EOF)
    {
        if(t==0)
            break;
        printf("Scenario #%d\n",++cas);
        init();//read data and do initialization
        
//        for(int i=259001;i<=259005;i++)
//            printf("%d ",group[i]);
//        printf("\n");
//        for(int i=260001;i<=260006;i++)
//            printf("%d ",group[i]);
//        printf("\n");
//
        while(scanf("%s",input)!=EOF)
        {
            if(input[0]=='S')//the stop command
                break;    
            if(input[0]=='E')
            {
                scanf("%d",&x);
                push(x);
            }
            else
            {
                printf("%d\n",pop());
                //printf("dd\n");
            } 
            
        }
	printf("\n");
    }
    return 0;
}
