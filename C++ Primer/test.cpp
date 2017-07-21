#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<ctime>
#include<set>
using namespace std;
typedef pair<int,int> pii;
const int maxn=200000+10;
int step[maxn];
queue <int> q;
set <pii> s;
set <int> s2;
set <int> s3;
int S,t,m,n,aa,bb;
int main(void)
{
    int temp,temp_step;
    cin>>t;
    while(t--)
    {
        s.clear();
        s2.clear();
        while(!q.empty())
            q.pop();
        memset(step,-1,sizeof(step));


        cin>>n>>m;
        for(int i=1;i<=n;i++)
            s2.insert(i);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&aa,&bb);
            s.insert(make_pair(aa,bb));
            s.insert(make_pair(bb,aa));
        }
        cin>>S;
        q.push(S);

        step[S]=0;
        s2.erase(S);
        while(!q.empty())
        {
            temp=q.front();
            temp_step=step[temp];
            q.pop();
            s3.clear();
            for(auto ii=s2.begin();ii!=s2.end();ii++)
            {
                int i=(*ii);
                if(s.count(make_pair(temp,i)))
                {
                    continue;
                }
                else
                {

                    step[i]=1+temp_step;
                    s.insert(make_pair(temp,i));
                    s.insert(make_pair(i,temp));
                    q.push(i);
                    s3.insert(i);
                }
            }
            for(auto ii=s3.begin();ii!=s3.end();ii++)
            {
                s2.erase(*ii);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(i==S)
                continue;
            printf("%d ",step[i]);
        }
        printf("\n");

    }
    return 0;
}
