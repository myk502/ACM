#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int a[1010][1010],n;
bool islegal(int x,int y)
{
    return((x>=1)&&(x<=n)&&(y>=1)&&(y<=n));
}

int main(void)
{
    //freopen("in","r",stdin);
    int cnt=0,kk=0;
    int min_row,min_column,max_row,max_column;
    min_row=min_column=1000+10;
    max_row=max_column=-1;
    cin>>n;
    memset(a,-1,sizeof(a));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
            {
                min_row=min(min_row,i);
                min_column=min(min_column,j);
                max_row=max(max_row,i);
                max_column=max(max_column,j);
            }
        }
    //cout<<min_row<<" "<<min_column<<endl;
    //cout<<max_row<<" "<<max_column<<endl;
    int row=max_row-min_row;
    int column=max_column-min_column;
    int ans=(row-1)*(column-1);
    if(ans<0)
        ans=0;
    cout<<ans;
    return 0;
}
