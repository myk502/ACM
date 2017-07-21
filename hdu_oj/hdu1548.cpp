#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <iso646.h>
using namespace std;
int temp1,temp2,head,tail,i,a,b,n,k[210],yuansu[210],visit[210],step[210];
int panduan(int input)
{
    if((input>=1) and (input<=n))
       return 1;
    else return 0;
}
void initialization(void)
{
    memset(step,-1,sizeof(step));
    memset(yuansu,-1,sizeof(yuansu));
    memset(visit,0,sizeof(visit));
    yuansu[1]=a;
    head=tail=1;
    visit[a]=1;
}
void push(int temp)
{
    tail++;
    yuansu[tail]=temp;
    visit[temp]=1;
    step[temp]=step[yuansu[head]]+1;

}
void bfs(void)
{
    while((head)<=tail)
    {
        temp1=yuansu[head]+k[yuansu[head]];
        temp2=yuansu[head]-k[yuansu[head]];
        if((panduan(temp1)==1) and !visit[temp1])
            push(temp1);
        if(temp1==b)
            return ;

        if(panduan(temp2) and !visit[temp2])
            push(temp2);
        if(temp1==b)
            return ;
        head++;
    }
}
int main(void)
{
    while((scanf("%d",&n)!=EOF) and (n!=0))
    {
        scanf("%d %d",&a,&b);
        for(i=1;i<=n;i++)
            scanf("%d",&k[i]);
        initialization();
        bfs();
        myk:if ((step[b]==-1) and (a!=b))
                printf("-1\n");
            else
                printf("%d\n",step[b]+1);

    }
    return 0;
}














