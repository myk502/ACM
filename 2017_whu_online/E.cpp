#include<bits/stdc++.h>
using namespace std;
const long long Mod=1e9+7;
int n,m,T;
struct Mat
{
    int row,column;
    long long a[101][101];
    Mat(int xx,int yy):row(xx),column(yy)//构造函数
    {
        for(int i=1;i<=row;i++)
            for(int j=1;j<=column;j++)
                a[i][j]=0LL;
    }
    Mat operator *(const Mat& X)//重载矩阵乘法,必须确保合法
    {
        Mat Y(this->row,X.column);
        for(int i=1;i<=this->row;i++)
            for(int j=1;j<=X.column;j++)
        {
            for(int k=1;k<=this->column;k++)
                Y.a[i][j]=(Y.a[i][j]+this->a[i][k]*X.a[k][j])%Mod;
        }
        return Y;
    }
    Mat operator +(const Mat& X)
    {
        Mat Y(row,column);
        for(int i=1;i<=row;i++)
            for(int j=1;j<=column;j++)
        {
            Y.a[i][j]=(this->a[i][j]+X.a[i][j])%Mod;
        }
        return Y;
    }
    Mat& operator =(const Mat& X)
    {
        for(int i=1;i<=row;i++)
            for(int j=1;j<=column;j++)
            a[i][j]=X.a[i][j];
        return *this;
    }
};
Mat FastMod(Mat X,int i)//计算矩阵快速幂;i>0
{
    if(i==1)
        return X;
    Mat ANS=Mat(X.row,X.column);
    for(int i=1;i<=X.row;i++)
        ANS.a[i][i]=1LL;
    while(i)
    {
        if(i&1)
            ANS=ANS*X;
        i>>=1;
        X=X*X;
    }
    return ANS;
}

int main(void)
{
    int xx,yy;
    long long ans=0;
    cin>>n>>m;
    Mat A(n,n);
    Mat SUM(n,n);
    Mat TEMP(n,n);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&xx,&yy);
        A.a[xx][yy]=1LL;
        A.a[yy][xx]=1LL;
        if(xx==n)
            A.a[xx][yy]=0LL;
        if(yy==n)
            A.a[yy][xx]=0LL;
        //cout<<xx<<"with"<<yy<<endl;
    }
    scanf("%d",&T);
    Mat B(2*n,2*n);
    //为B赋值
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            B.a[i][j]=A.a[i][j];
        for(int j=n+1;j<=2*n;j++)
            B.a[i][j]=A.a[i][j-n];
    }
    for(int i=n+1;i<=2*n;i++)
    {
        for(int j=1;j<=n;j++)
            B.a[i][j]=0LL;
        for(int j=n+1;j<=2*n;j++)
        {
            if(i==j)
                B.a[i][j]=1LL;
            else
                B.a[i][j]=0LL;
        }
    }
    Mat C(2*n,n);
    //为C赋值
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            C.a[i][j]=A.a[i][j];
    for(int i=n+1;i<=2*n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i-n==j)
                C.a[i][j]=1LL;
            else
                C.a[i][j]=0LL;
        }


    Mat ANS(2*n,n);
    Mat D(2*n,2*n);
    //printf("mark1\n");
    //printf("T=%d\n",T);
    if(T!=1)
    {
        D=FastMod(B,T-1);
        ANS=D*C;
    }
    else
        ANS=C;

    ans=ANS.a[1][n];
    cout<<ans;
    return 0;
}
