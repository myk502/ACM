#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<vector>
#include<sstream>
#include<queue>
#include<limits.h>
#include<set>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,index_b=0;
int r[1010],c[1010];
int a[1010][1010];
int main(void)
{
    cin>>n>>m;
    int num=0,flag=0;
    string temp;
    char tempp;
    memset(r,0,sizeof(r));
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++)
    {
        cin>>temp;
        stringstream ss(temp);
        for(int j=1;j<=m;j++)
        {
            ss>>tempp;
            if(tempp=='*')
            {
                a[i][j]=1;
                r[i]++;
                c[j]++;
                num++;
            }
            else
                a[i][j]=0;
        }
    }
    int ans_x,ans_y;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(r[i]+c[j]-a[i][j]==num)
        {
            flag=1;
            ans_x=i;
            ans_y=j;
        }
    }
    if(!flag)
        printf("NO");
    else
        printf("YES\n%d %d",ans_x,ans_y);




    return 0;
}
