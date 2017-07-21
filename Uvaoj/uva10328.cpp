#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
class BigNum
{
public:
    int len;
    int a[50];//下标代表第几位

    BigNum()//初始化构造函数
    {
        len=1;
        memset(a,0,sizeof(a));
    }
    BigNum(int x)//int转换为高精度的构造函数
    {
        len=0;
        if(x==0)
            len=1;
        memset(a,0,sizeof(a));
        while(x)
        {
            a[++len]=x%10;
            x/=10;
        }
    }
    BigNum(const BigNum &x)//复制构造函数
    {
        memset(a,0,sizeof(a));
        len=x.len;
        for(int i=0;i<=len;i++)
            a[i]=x.a[i];
    }
    BigNum operator-(const BigNum &b)const//这里没有考虑结果是负数的情况
    {
        BigNum c;
        int i=1,tuiwei=0;
        for(;i<=max(len,b.len);i++)
        {
            int temp=a[i]-b.a[i]+tuiwei;
            if(temp>=0)
            {
                c.a[i]=temp;
                tuiwei=0;
            }
            else
            {
                tuiwei=-1;
                c.a[i]=temp+10;
            }
        }
        for(int j=45;j>=0;j--)
        {
            if(c.a[j]!=0)
            {
                c.len=j;
                break;
            }
        }
        if(c.len==0)
            c.len=1;

        return c;

    }
    BigNum operator+(const BigNum &b)const
    {
        BigNum c;
        int i=1,jinwei=0;
        for(;i<=max(len,b.len);i++)
        {
            c.a[i]=(a[i]+b.a[i]+jinwei)%10;
            jinwei=(a[i]+b.a[i]+jinwei)/10;
        }
        if(jinwei)
            c.a[i]=jinwei%10;
        for(int j=45;j>=0;j--)
        {
            if(c.a[j]!=0)
            {
                c.len=j;
                break;
            }
        }
        if(c.len==0)
            c.len=1;
        return c;
    }
    void print(void)
    {
        for(int i=len;i>=1;i--)
            printf("%d",a[i]);
    }
    BigNum & operator =(const BigNum &x)
    {
        len=x.len;
        memset(a,0,sizeof(a));
        for(int i=0;i<=len;i++)
            a[i]=x.a[i];
        return *this;
    }

};
int n,k;
BigNum f[110][3];
int main(void)
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(cin>>n>>k)
    {
        k--;
        f[1][0]=BigNum(1);
        f[1][1]=(k==0)?BigNum(0):BigNum(1);
        for(int i=2;i<=n;i++)
        {
            f[i][0]=f[i-1][0]+f[i-1][1];

            if(i-1-k<0)
            {
                f[i][1]=f[i][0];

            }

            else if(i-1-k>0)
            {
                f[i][1]=f[i][0]-f[i-1-k][0];

            }

                else
                {
                    f[i][1]=f[i][0]-BigNum(1);
                }

        }
        BigNum total(1);
        for(int i=1;i<=n;i++)
            total=total+total;
        BigNum ans,anss;
        ans=total-f[n][0];//16-5
       // f[n][0].print();
        //printf("::::The length of f[n][0]=%d\n",f[n][0].len);
        ans=ans-f[n][1];//11-3

        //printf("STEP1\n");
        /*
        for(int i=1;i<=n;i++)
        {
            printf("Num%d:",i);
            f[i][0].print();
            printf(" ");
            f[i][1].print();
            printf("\n");
        }
        */
        ans.print();
        printf("\n");

    }
    return 0;
}
