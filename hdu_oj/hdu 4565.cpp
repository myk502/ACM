#include<cstdio>
#include<cstring>
#include<set>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;
int a,b,n,m;
struct Mat
{
    int line;
    int column;
    int a[4][4];//注意!!!根据题目需要更改大小
    Mat()
    {
        line=column=2;//同上！！！这里是初始化为单位矩阵，但是在正式写代码时不建议用这个，用下面那个比较好
        a[1][1]=1;
        a[1][2]=0;
        a[2][1]=0;
        a[2][2]=1;
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
int main(void)
{
    int s1,s0;
    while(cin>>a>>b>>n>>m)
    {
        s0=1;
        s1=a+a;
        s1%=m;
        Mat Z(2,1);
        Z.a[1][1]=s1;
        Z.a[2][1]=s0;
        Mat X(2,2);
        X.a[1][1]=(2*a)%m;
        X.a[1][2]=(b-a*a)%m;
        X.a[1][2]+=m;
        X.a[1][2]%=m;
        X.a[2][1]=1;
        X.a[2][2]=0;
        Mat Y=FastMod(X,n,m);
        Mat ANS=Y*Z;
        int ans;
        ans=ANS.a[2][1];
        cout<<ans<<endl;
    }
    return 0;
}
