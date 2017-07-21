#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int n,m,t,x;
int a[110],sum[110];
struct XOR
{
    int left,right;
    int ans;
    XOR(int x,int y,int z):left(x),right(y),ans(z)
    {

    }
    int width()
    {
        return right-left+1;
    }
    bool operator <(const int &X)
    {
        return ans<X;
    }
    bool  operator >(const int &x)
    {
        return ans>x;
    }
    bool operator <=(const int &x)
    {
        return ans<=x;
    }
    bool operator >=(const int &x)
    {
        return ans>=x;
    }
    bool operator ==(const int &x)
    {
        return ans==x;
    }
};
vector<XOR> b;
bool cmp(XOR a,XOR b)
{
    if(a.ans!=b.ans)
        return(a.ans<b.ans);
    else
        return(a.width()>b.width());
}
int main(void)
{
    cin>>t;
    while(t--)
    {
        b.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sum[0]=0;
        sum[1]=a[1];
        for(int i=2;i<=n;i++)
            sum[i]=sum[i-1]^a[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                b.push_back(XOR(i,j,sum[j]^sum[i-1]));
            }
        }
        sort(b.begin(),b.end(),cmp);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&x);
            if(x<0)
            {
                printf("%d\n",b[0].width());
            }
            else
            {
                int xx=0;
                vector<XOR>::iterator it1;
                vector<XOR>::iterator it2;
                while(true)
                {
                    it1=lower_bound(b.begin(),b.end(),x+xx);
                    it2=lower_bound(b.begin(),b.end(),x-xx);
                    if((it1->ans==x+xx)&&(it2->ans==x-xx))
                    {
                        printf("%d\n",max(it1->width(),it2->width()));
                        break;
                    }
                    if(it1->ans==x+xx)
                    {
                        printf("%d\n",it1->width());
                        break;
                    }
                    if(it2->ans==x-xx)
                    {
                        printf("%d\n",it2->width());
                        break;
                    }
                    {
                        xx++;
                    }

                }
            }
        }
        printf("\n");
    }
    return 0;
}
