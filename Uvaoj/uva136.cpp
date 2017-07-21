#include<cstdio>
#include<iostream>
#include<set>
#include<cmath>
#include<queue>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long> >pq;
set<long long> s;
int main(void)
{
    pq.push(1LL);
    s.insert(1LL);
    int cnt=2;
    long long next[4],temp;
    while(cnt<=1500)
    {
        temp=pq.top();
        //printf("%lld\n",temp);
        next[0]=temp*2LL;
        next[1]=temp*3LL;
        next[2]=temp*5LL;
        for(int i=0;i<3;i++)
        {
            if(s.count(next[i])==0)//if the number never appears in the priority queue
            {
                pq.push(next[i]);
                s.insert(next[i]);
            }
        }
        pq.pop();
        cnt++;
    }
    printf("The 1500'th ugly number is %I64d.\n",pq.top());
            


    return 0;
}
