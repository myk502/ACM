#include<bits/stdc++.h>
using namespace std;
int n,m,a[10][10][10][10];
void init(void)
{
    memset(a,0,sizeof(a));
}
void readline(void)
{
    string mode;
    int i,j;
    for(int ii=0;ii<m;ii++)
    {
          cin>>mode>>i>>j;
          if(mode=="H")
          {
              a[i][j][i][j+1]=1;
              a[i][j+1][i][j]=1;
          }
          else
          {
              a[j][i][j+1][i]=1;
              a[j+1][i][j][i]=1;
          }
    }
}
bool isconnected(int aa,int bb,int cc,int dd)
{
    if((aa!=cc)&&(bb!=dd))
        return false;
    if(aa==cc)
    {
        bool flag=true;
        for(int jj=min(bb,dd);jj<max(bb,dd);jj++)
        {
            if(!a[aa][jj][aa][jj+1])
                flag=false;
        }
        return flag;
    }
    else
    {
        bool flag=true;
        for(int ii=min(aa,cc);ii<max(aa,cc);ii++)
        {
            if(!a[ii][bb][ii+1][bb])
                flag=false;
        }
        return flag;
    }
}
int main(void)
{
    //freopen("in","r",stdin);
    int cases=0;
    while(cin>>n>>m)
    {
        bool thereisasquare=false;
        init();
        readline();
        if(cases>0)
            printf("\n**********************************\n\n");
        printf("Problem #%d\n\n",++cases);
        for(int k=1;k<=9;k++)//the size of the square
        {
            int cnt=0;
            for(int i=1;(i+k)<=n;i++)
            for(int j=1;(j+k)<=n;j++)
            {
                bool flag1,flag2,flag3,flag4;
                flag1=isconnected(i,j,i,j+k);
                flag2=isconnected(i,j,i+k,j);
                flag3=isconnected(i+k,j,i+k,j+k);
                flag4=isconnected(i,j+k,i+k,j+k);
                if(flag1&&flag2&&flag3&&flag4)
                    cnt++;
            }
            if(cnt)
            {
                thereisasquare=true;
                printf("%d square (s) of size %d\n",cnt,k);
            }
        }
        if(!thereisasquare)
            printf("No completed squares can be found.\n");

    }
    return 0;
}
