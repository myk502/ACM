#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
#include<ctype.h>
using namespace std;
#define zuida 1000000
int num,prime[zuida+10],isprime[zuida+10],ismeiprime[zuida+10];//prime数组中存放素数
int sum[zuida+10];
int i,j;//循环变量
int geweihe(int input)
{
    char temp[10];
    int sum=0;
    sprintf(temp,"%07d",input);

    for(int i=0;i<7;i++)
    {
        sum+=temp[i]-'0';
    }
    return sum;
}

int main(void)
{
    int t,l,r,num_sushu;
    scanf("%d",&t);
    memset(isprime,1,sizeof(isprime));//初始化为0
    isprime[0]=isprime[1]=0;//0,1都不是素数
    num=0;//num用来存放目前的素数个数
    for(i=2;i<=zuida;i++)
    {
        if(isprime[i])//如果i是素数
            prime[++num]=i;//将i存入，prime数组从1开始
        for(j=1;(j<=num)&&(i*prime[j]<=zuida);j++)
        {
            isprime[i*prime[j]]=0;//这个数一定不是素数
            if(i%prime[j]==0)
                break;//说明i是合数，而他去乘各个素数的结果，之前他的因子去乘各个素数一定已经得到过了，所以不用做
        }
    }
    for(int i=1;i<=zuida;i++)
    {
        int temp=geweihe(i);
        if((isprime[i])&&(isprime[temp]))
            ismeiprime[i]=1;
        else
            ismeiprime[i]=0;
    }
    sum[1]=0;
    for(int i=2;i<=zuida;i++)
    {
        if(ismeiprime[i])
            sum[i]=sum[i-1]+1;
        else
            sum[i]=sum[i-1];
    }
    for(int i=1;i<=t;i++)
    {
        num_sushu=0;
        scanf("%d%d",&l,&r);

        printf("Case #%d: %d\n",i,sum[r]-sum[l]+ismeiprime[l]);
    }

    return 0;
}
