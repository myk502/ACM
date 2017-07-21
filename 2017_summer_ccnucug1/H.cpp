#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
long long  num[10];
long long pow_10[15];

void init(void)
{
    pow_10[0]=1;
    for(int i=1;i<15;i++)
        pow_10[i]=pow_10[i-1]*10;
    num[1]=1;
    for(int i=2;i<=9;i++)
        num[i]=10*num[i-1]+pow_10[i-1];
}
long long getleft(long long x,int& _pow)
{
    for(int i=0;i<10;i++)
    {
        if(pow_10[i]<=x && pow_10[i+1]>x)
        {
            _pow=i;
            return pow_10[i];
        } 
    }
}

long long solve(long long x)
{
    if(x==0LL)
        return 0;
    long long cnt=0;
    int _pow;
    long long y=getleft(x,_pow);
    int first_num=x/y;
    if(first_num!=1)
    {
        for(int i=0;i<first_num;i++)
            cnt+=num[_pow];
        cnt+=y;
    }
    else
    {
        cnt+=num[_pow];
        cnt+=x-y+1;
    }
    cnt+=solve(x%y);
    return cnt;
    
}
int main(void)
{
    init();
    long long input;
    cin>>input;
    cout<<solve(input)<<endl;
    return 0;
}
