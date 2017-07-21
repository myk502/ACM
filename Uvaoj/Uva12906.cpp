#include<bits/stdc++.h>
using namespace std;
typedef set<int> Set;
map<Set,int> IDcache;
vector<Set> Setcache;
int find_id(Set x)//if exists a map-link whose key is x return the value;else new a map-link
{
    if(IDcache.count(x))
        return IDcache[x];
    Setcache.push_back(x);
    return IDcache[x]=Setcache.size()-1;
}
int main(void)
{
    int T;
    cin>>T;
    while(T--)
    {
        stack<int> s;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            string op;
            cin>>op;
            if(op[0]=='P')
            {
                s.push(find_id(Set()));
            }
            else if(op[0]=='D')
            {
                s.push(s.top());
            }
            else
            {
                Set s1=Setcache[s.top()];
                s.pop();
                Set s2=Setcache[s.top()];
                s.pop();
                Set ss;
                if(op[0]=='U')
                    set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(ss,ss.begin()));
                if(op[0]=='I')
                    set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(ss,ss.begin()));
                if(op[0]=='A')
                {
                    s2.insert(find_id(s1));
                    ss=s2;
                }
                s.push(find_id(ss));
            }
            cout<<Setcache[s.top()].size()<<endl;
        }
        printf("***\n");
    }
    return 0;
}
