#include<bits/stdc++.h>
using namespace std;
char first[100];
int a,b,l,r;
bool exist[200];
void generate_next(int i,int a)
{
    set<char> s;
    s.clear();
    for(int ii=i-a;ii<i;ii++)
        s.insert(first[ii]);
    for(int ii=i;ii<i+a;ii++)
    {
        for(int j=0;j<24;j++)
        {
            if(s.count('a'+j)==0)
            {
                first[ii]='a'+j;
                exist[j]=true;
                s.insert((char)('a'+j));
                break;
            }
        }
    }
}
void init(int a,int b)
{
    memset(exist,0,sizeof(exist));
    for(int i=1;i<=a;i++)
    {
        first[i]='a'+i-1;
        exist[i-1]=true;
    }
    for(int i=a+1;i<=a+b;i++)
    {
        first[i]='z';
        exist['z'-'a']=true;
    }
    generate_next(a+b+1,a);
    for(int i=2*a+b+1;i<=2*a+2*b;i++)
        first[i]='z';
    for(int i=2*a+2*b+1;i<=4*a+4*b;i++)
        first[i]=first[i-2*a-2*b];
    first[4*a+4*b+1]='\0';
}
int calc(int ii,int jj)
{
    memset(exist,0,sizeof(exist));
    for(int i=ii;i<=jj;i++)
    {
        exist[first[i]-'a']=true;
    }
    int cnt=0;
    for(int i=0;i<30;i++)
        if(exist[i])
            cnt++;
    return cnt;
}
bool range_intersect(int l1,int r1,int l2,int r2)
{
    return max(l1,l2)<=min(r1,r2);
}
int main(void)
{
    cin>>a>>b>>l>>r;
    init(a,b);
    if(r-l+1>=2*a+2*b)
    {
        cout<<calc(1,2*a+2*b);
    }
    else
    {
        int temp=(l-1)/(2*a+2*b);
        l-=temp*(2*a+2*b);
        r-=temp*(2*a+2*b);
        int ans=calc(l,r);
        int cnt=0,cnt2=0;
        if(range_intersect(l,r,1,a))
            cnt++;
        if(range_intersect(l,r,a+b+1,2*a+b))
            cnt++;
        if(range_intersect(l,r,2*a+2*b+1,3*a+2*b))
            cnt++;
        if(range_intersect(l,r,3*a+3*b+1,4*a+3*b))
            cnt++;
        if(range_intersect(l,r,a+1,a+b))
            cnt2++;
        if(range_intersect(l,r,2*a+b+1,2*a+2*b))
            cnt2++;
        if(range_intersect(l,r,3*a+2*b+1,3*a+3*b))
            cnt2++;
        if(range_intersect(l,r,4*a+3*b+1,4*a+4*b))
            cnt2++;
        //  printf("cnt=%d cnt2=%d\n",cnt,cnt2);
        if( (cnt==1)&&(cnt2!=0))
            ans--;
        cout<<ans;

    }

    return 0;
}
