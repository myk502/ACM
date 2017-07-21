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
int main(void)
{
    BigNum a(8111200);
    BigNum b(32192);
    BigNum c;
    c=a-b;
    //a.print();
   // b.print();
    //printf("%d %d\n",a.len,b.len);
    c.print();
    return 0;
}
