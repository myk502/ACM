#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int m,n,q;
int row[maxn],col[maxn],rowindex[maxn],colindex[maxn];
int backup[maxn][maxn],num[maxn][maxn];
void init(void)
{
    memset(row,0,sizeof(row));
    memset(col,0,sizeof(col));
    for(int i=1;i<=n;i++)
        rowindex[i]=i;
    for(int i=1;i<=m;i++)
        colindex[i]=i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&backup[i][j]);
}
int main(void)
{
    int T,a,x,y;
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>q;
        init();
        while(q--)
        {
            scanf("%d%d%d",&a,&x,&y);
            if(a==1)
            {
                swap(row[x],row[y]);
                swap(rowindex[x],rowindex[y]);
            }
            if(a==2)
            {
                swap(col[x],col[y]);
                swap(colindex[x],colindex[y]);
            }
            if(a==3)
                row[x]+=y;
            if(a==4)
                col[x]+=y;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                num[i][j]=backup[rowindex[i]][colindex[j]]+row[i]+col[j];
                if(j!=1)
                    printf(" %d",num[i][j]);
                else
                    printf("%d",num[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
