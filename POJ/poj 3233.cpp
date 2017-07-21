#include<cstdio>
#include<cstring>
#include<iostream>
#include<climits>
#include<cmath>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int n,k,m;
struct Mat
{
    int line;
    int column;
    int a[100][100];
    Mat()
    {

    }
    Mat(int x,int y)
    {
        line=x;
        column=y;
        memset(a,0,sizeof(a));
    }
};
Mat MulMat(Mat A,Mat B,int MOD)//A's column and B's line must be equal
{
    int aa,bb,cc;
    aa=A.line;
    bb=A.column;
    cc=B.column;
    Mat C(aa,cc);
    for(int i=1;i<=aa;i++)
    {
        for(int j=1;j<=cc;j++)
        {
            for(int k=1;k<=bb;k++)
            {
                C.a[i][j]+=(A.a[i][k]*B.a[k][j])%MOD;
                C.a[i][j]%=MOD;
            }
        }
    }
    return C;
}
Mat operator *(const Mat& A,const Mat& B)
{
    return(MulMat(A,B,m));
}
Mat FastMod(Mat A,int n,int Mod)
{
    Mat E;
    if(n==0)
        return E;
    if(n==1)
        return A;
    if(n%2==1)
    {
        //printf("step1\n");
        return(MulMat(A,FastMod(A,n-1,Mod),Mod));
    }
    else
    {
        Mat temp=FastMod(A,n/2,Mod);
        //printf("step 2\n");
        return(MulMat(temp,temp,Mod));
    }
}
void shuchu(Mat X)
{
    int n=X.line;
    int m=X.column;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            printf("%d ",X.a[i][j]);
        printf("\n");
    }
}
int main(void)
{
    int temp;
    cin>>n>>k>>m;
    Mat A(n,n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&temp);
            temp%=m;
            A.a[i][j]=temp;
        }
    Mat A2=A*A;
    Mat F(2*n,n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            F.a[i][j]=A.a[i][j];
    for(int i=n+1;i<=2*n;i++)
        for(int j=1;j<=n;j++)
            F.a[i][j]=A2.a[i-n][j];
    Mat E(n,n);
    for(int i=1;i<=n;i++)
        E.a[i][i]=1;
    Mat D(2*n,2*n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            D.a[i][j]=E.a[i][j];
        for(int j=n+1;j<=2*n;j++)
            D.a[i][j]=E.a[i][j-n];
    }
    for(int i=n+1;i<=2*n;i++)
    {
        for(int j=1;j<=n;j++)
            D.a[i][j]=0;
        for(int j=n+1;j<=2*n;j++)
            D.a[i][j]=A.a[i-n][j-n];
    }
    if(k==1)
    {
        shuchu(A);
    }
    else
    {
        Mat DK=FastMod(D,k-1,m);
        Mat ANS(n,n);
        Mat TEMPP(2*n,n);
        TEMPP=DK*F;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                ANS.a[i][j]=TEMPP.a[i][j];
        shuchu(ANS);
    }
    return 0;
}
