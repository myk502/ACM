#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int sum1,sum2,i,j,t,m,n,map1[110][110],map2[110][110];
int panduan(int i,int j)
{
    if((i>=0)&&(i<m)&&(j>=0)&&(j<n))
        return 1;
    else return 0;
}
int main(void)
{

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        map1[0][0]=1;
        map2[0][0]=0;
        for(i=1;i<n;i++)
            map1[0][i]=1-map1[0][i-1];
        for(j=1;j<m;j++)
            map1[j][0]=1-map1[j-1][0];
        for(i=1;i<n;i++)
            map2[0][i]=1-map2[0][i-1];
        for(j=1;j<m;j++)
            map2[j][0]=1-map2[j-1][0];
        for(i=1;i<m;i++)
            for(j=1;j<n;j++)
            {
                map1[i][j]=1-map1[i][j-1];
                map2[i][j]=1-map2[i][j-1];
            }
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                if(map1[i][j]==0)
                {
                    if(panduan(i-1,j))
                        map1[i-1][j]*=2;
                    if(panduan(i+1,j))
                        map1[i+1][j]*=2;
                    if(panduan(i,j-1))
                        map1[i][j-1]*=2;
                    if(panduan(i,j+1))
                        map1[i][j+1]*=2;
                }
                if(map2[i][j]==0)
                {
                    if(panduan(i-1,j))
                        map2[i-1][j]*=2;
                    if(panduan(i+1,j))
                        map2[i+1][j]*=2;
                    if(panduan(i,j-1))
                        map2[i][j-1]*=2;
                    if(panduan(i,j+1))
                        map2[i][j+1]*=2;
                }

            }
        sum1=sum2=0;
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            {
                sum1+=map1[i][j];
                sum2+=map2[i][j];
            }
        printf("%d\n",max(sum1,sum2));



    }
}
