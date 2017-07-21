#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
long long a[6000];
int visit[32][20][15][15];
int indexx=1;
struct Number
{
    int num_2;
    int num_3;
    int num_7;
    int num_5;
    long long num;
    Number(int xx2,int xx3,int xx5,int xx7,long long number)
    {
        num_2=xx2;
        num_3=xx3;
        num_5=xx5;
        num_7=xx7;
        num=number;
    }
    Number()
    {

    }
};
queue <Number> q;
void bfs(void)
{
    long long temp_num,new_temp,temp_2,temp_3,temp_5,temp_7,new_2,new_3,new_5,new_7;
    Number temp;
    while(!q.empty())
    {
        temp=q.front();
        new_2=temp_2=temp.num_2;
        new_3=temp_3=temp.num_3;
        new_5=temp_5=temp.num_5;
        new_7=temp_7=temp.num_7;
        temp_num=temp.num;
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(i==0)
            {
                new_temp=temp_num*2;
                new_2++;
            }
            if(i==1)
            {
                new_temp=temp_num*3;
                new_3++;
            }
            if(i==2)
            {
                new_temp=temp_num*5;
                new_5++;
            }
            if(i==3)
            {
                new_temp=temp_num*7;
                new_7++;
            }
            if((new_temp<=2000000000)&&!visit[new_2][new_3][new_5][new_7])
            {
                Number tempp(new_2,new_3,new_5,new_7,new_temp);
                q.push(tempp);
                visit[new_2][new_3][new_5][new_7]=1;
                a[indexx++]=new_temp;

            }
            new_2=temp_2;
            new_3=temp_3;
            new_5=temp_5;
            new_7=temp_7;
        }
    }
}
void init(void)
{
    Number tempp(0,0,0,0,1);
    memset(visit,0,sizeof(visit));
    q.push(tempp);
    visit[0][0][0][0]=1;
    a[indexx++]=1;
    bfs();
    sort(a+1,a+5843);
}
int main(void)
{
    int x,xx;
    init();
    while(scanf("%d",&x))
    {
        if(x==0)
            break;
        xx=x%10;
        if((xx==1)&&(x%100!=11))
        {
            printf("The %dst humble number is ",x);
        }
        else if((xx==2)&&(x%100!=12))
        {
            printf("The %dnd humble number is ",x);
        }
        else if((xx==3)&&(x%100!=13))
        {
            printf("The %drd humble number is ",x);
        }
        else
        {
            printf("The %dth humble number is ",x);
        }

        printf("%I64d.\n",a[x]);
    }
    return 0;
}
