#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;
int n;
const int maxn=100000+10;
struct myk{
int a,b,c;
int index;
};
myk s[maxn];
bool cmp1(myk aa,myk bb)
{
    if(aa.a!=bb.a)
        return(aa.a<bb.a);
    else
        return(aa.b<bb.b);
}
bool cmp2(myk aa,myk bb)
{
    if(aa.a!=bb.a)
        return(aa.a<bb.a);
    else
        return(aa.c<bb.c);
}
bool cmp3(myk aa,myk bb)
{
    if(aa.b!=bb.b)
        return(aa.b<bb.b);
    else
        return(aa.c<bb.c);
}
int get_mid(int a,int b,int c)
{
    if(a>=b)
    {
        if(b>=c)
            return b;
        if(b<c)
            return min(a,c);
    }
    else//a<b
    {
        if(c<a)
            return a;
        else//c>=a
            return min(b,c);
    }
}
int main(void)
{
    cin>>n;
    int index_0,index_1,index_2,flag,r=INT_MIN,temp,tempa,tempb,tempc;//r´æ´¢Á½±¶µÄr
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&tempa,&tempb,&tempc);
        a[i].a=min(tempa,min(tempb,tempc));
        a[i].c=max(tempa,max(tempb,tempc));
        a[i].b=get_mid(tempa,tempb,tempc);
        s[i].index=i;
        temp=min(s[i].a,min(s[i].b,s[i].c));
        if(temp>r)
        {
            r=temp;
            index_0=i;
        }
    }
    flag=0;
    //printf("r=%d\n",r);
    {
        sort(s+1,s+n+1,cmp1);
        for(int i=1;i<n;i++)//i and i+1
        {
            if((s[i].a==s[i+1].a)&&(s[i].b==s[i+1].b))
            {
                if((i==n-1)||(s[i+2].a!=s[i].a)||(s[i+2].b!=s[i].b))
                {
                    int aa=s[i].a,bb=s[i].b,cc=s[i].c+s[i+1].c;
                    int rr=min(aa,min(bb,cc));
                    if(rr>r)
                    {
                        flag=1;
                        index_1=s[i].index;
                        index_2=s[i+1].index;
                    }
                }
            }
        }
    }
    {
        sort(s+1,s+n+1,cmp2);
        for(int i=1;i<n;i++)//i and i+1
        {
            if((s[i].a==s[i+1].a)&&(s[i].c==s[i+1].c))
            {
                if((i==n-1)||(s[i+2].a!=s[i].a)||(s[i+2].c!=s[i].c))
                {
                    int aa=s[i].a,cc=s[i].c,bb=s[i].b+s[i+1].b;
                    int rr=min(aa,min(bb,cc));
                    if(rr>r)
                    {
                        flag=1;
                        index_1=s[i].index;
                        index_2=s[i+1].index;
                    }
                }
            }
        }
    }
    {
        sort(s+1,s+n+1,cmp3);
        for(int i=1;i<n;i++)//i and i+1
        {
            if((s[i].b==s[i+1].b)&&(s[i].c==s[i+1].c))
            {
                if((i==n-1)||(s[i+2].b!=s[i].b)||(s[i+2].c!=s[i].c))
                {
                    int aa=s[i].a+s[i+1].a,cc=s[i].c,bb=s[i].b;
                    int rr=min(aa,min(bb,cc));
                    if(rr>r)
                    {
                        flag=1;
                        index_1=s[i].index;
                        index_2=s[i+1].index;
                    }
                }
            }
        }
    }
    if(flag==0)
        printf("1\n%d",index_0);
    else
        printf("2\n%d %d",min(index_1,index_2),max(index_1,index_2));
    return 0;
}
