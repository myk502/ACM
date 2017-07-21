#include<bits/stdc++.h>

using namespace std;

int R,C;
char a[101][101];
bool dp[2][101][200][200];
int main()
{
    scanf("%d%d",&R,&C);
    for (int i=0;i<R;i++){
        scanf("%s",a[i]);
    }
    memset(dp,0,sizeof(dp));
    int ans = 0;
    if (a[0][0]=='>') dp[0][0][1][0] = 1;
    if (a[0][0]=='|') dp[0][0][0][1] = 1;
    if (a[0][0]=='-') dp[0][0][0][0] = 1;
    for (int i=0;i<R;i++)
    {
        for (int j=0;j<C;j++)
        for (int k=0;k<=i+j+1;k++)
        for (int k1=0;k1<=i+j+1-k;k1++)
            dp[(i+1)%2][j][k][k1] = 0;
        for (int j=0;j<C;j++){
        for (int k=0;k<=i+j+1;k++)
        for (int k1=0;k1<=i+j+1-k;k1++)
        if (dp[i%2][j][k][k1]){
            ans=max(ans,min(k,min(k1,i+j+1-k-k1)));
            if (i+1<R){
                if (a[i+1][j]=='>') dp[(i+1)%2][j][k+1][k1] = 1;
                if (a[i+1][j]=='|') dp[(i+1)%2][j][k][k1+1] = 1;
                if (a[i+1][j]=='-') dp[(i+1)%2][j][k][k1] = 1;
            }
            if (j+1<C){
                if (a[i][j+1]=='>') dp[(i)%2][j+1][k+1][k1] = 1;
                if (a[i][j+1]=='|') dp[(i)%2][j+1][k][k1+1] = 1;
                if (a[i][j+1]=='-') dp[(i)%2][j+1][k][k1] = 1;
            }
        }
    }
    }

    printf("%d\n",ans);
    return 0;
}
