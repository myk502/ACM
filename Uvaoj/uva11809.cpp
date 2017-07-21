#include<stdio.h>
#include<iostream>
#include<string.h>
#include<limits.h>
#include<float.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct myk{
double aa;
int bb;};
myk chabiao[10][31];
char input[30];
int main(void)
{
    int i,j;
    long double m,e,t,a,b,ans;
    for(int i=0;i<10;i++)
        for(int j=1;j<=30;j++)
    {
        m=1-pow(2.0,-i-1);
        e=pow(2,j)-1;
        t=log10(m)+(log10(2)*e);
        chabiao[i][j].bb=(int)t;
        double temp=t-chabiao[i][j].bb;
        chabiao[i][j].aa=pow(10,temp);
        //printf("chabiao[%d][%d]:%d %d\n",i,j,chabiao[i][j].aa,chabiao[i][j].bb);
    }
    while(scanf("%s",input))
    {
        a=b=0.0;
        if((input[0]=='0')&&(input[1]=='e')&&(input[2]=='0'))
            break;
        a+=input[0]-'0';
        for(int i=2;i<=16;i++)
        {
            a+=(input[i]-'0')*pow(10,1-i);
        }
        for(int i=18;i<strlen(input);i++)
        {
            b+=pow(10,strlen(input)-i-1)*(input[i]-'0');
        }

        //cout<<"a="<<a<<endl<<"b="<<b<<endl;
        for(int i=0;i<10;i++)
            for(int j=1;j<=30;j++)
        {
            if((fabs(chabiao[i][j].aa-a)<1e-4)&&(chabiao[i][j].bb==b))
            {
                printf("%d %d\n",i,j);
                //goto jieshu;
            }
        }

    }
    return 0;
}
