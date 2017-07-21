#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <iso646.h>
using namespace std;
#define zuida 200010
int temp,tempjia,tempjian,tempcheng,head,tail,n,k,yuansu[zuida],step[zuida],visit[zuida];
int panduan(int input)
{
    if((input>=0) and (input<zuida))
        return 1;
    else return 0;
}
void push(int temp)
{
    tail++;
    visit[temp]=1;
    yuansu[tail]=temp;
    step[temp]=1+step[yuansu[head]];
    printf("From %d to %d,step from %d to %d\n",yuansu[head],temp,step[yuansu[head]],step[temp]);

}
void bfs(void)
{
    step[n]=0;

    yuansu[0]=n;
    head=tail=0;
    while(head<=tail)
    {
        temp=yuansu[head];
        tempjia=temp+1;
        tempjian=temp-1;
        tempcheng=temp*2;

        if((temp>k) and !visit[tempjian])
        {
            push(tempjian);
            head++;
            if(yuansu[tail]==k) return ;
            continue;
        }


        if((!visit[tempcheng]) and panduan(tempcheng))
                push(tempcheng);
        if((!visit[tempjia]) and panduan(tempjia))
                push(tempjia);
        if((!visit[tempjian]) and panduan(tempjian))
                push(tempjian);
        if(yuansu[tail]==k) return ;
        head++;
    }
}

int main(void)
{

    scanf("%d %d",&n,&k);

    if(n>=k)
        printf("%d",n-k);
    else
    {  bfs();
       printf("%d",step[k]);
    }
    return 0;

}














