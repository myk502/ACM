#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const long long Mod=2147493647;
struct Mat
{
    long long line;
    long long column;
    long long a[8][8];
    Mat()
    {
        line=column=7;
        for(int i=1;i<=7;i++)
        {
            for(int j=1;j<=7;j++)
            {
                if(i==j)
                    a[i][j]=1;
                else
                    a[i][j]=0;
            }
        }
    }
    Mat(long long x,long long y)
    {
        line=x;
        column=y;
        memset(a,0,sizeof(a));
    }
};

Mat MulMat(Mat A,Mat B,long long MOD)
{
    long long aa,bb,cc;
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
Mat FastMod(Mat A,long long n,long long Mod)
{
    Mat E(A.line,A.column);
    if(n==0)
        return E;
    if(n==1)
        return A;
    if(n%2==1)
        return(MulMat(A,FastMod(A,n-1,Mod),Mod));
    else
    {
        Mat temp=FastMod(A,n/2,Mod);
        return(MulMat(temp,temp,Mod));
    }
}
long long t,n,a,b;
int main(void)
{
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        if(n==1)
            cout<<a<<endl;
        if(n==2)
            cout<<b<<endl;
        if(n>2)
        {
            Mat B(7,1);
            B.a[1][1]=a;
            B.a[2][1]=b;
            B.a[3][1]=81;
            B.a[4][1]=27;
            B.a[5][1]=9;
            B.a[6][1]=3;
            B.a[7][1]=1;
            Mat A(7,7);
            A.a[1][2]=1;
            A.a[2][1]=2;
            A.a[2][2]=1;
            A.a[2][3]=1;
            A.a[3][3]=1;
            A.a[3][4]=4;
            A.a[3][5]=6;
            A.a[3][6]=4;
            A.a[3][7]=1;
            A.a[4][4]=1;
            A.a[4][5]=3;
            A.a[4][6]=3;
            A.a[4][7]=1;
            A.a[5][5]=1;
            A.a[5][6]=2;
            A.a[5][7]=1;
            A.a[6][6]=1;
            A.a[6][7]=1;
            A.a[7][7]=1;
            Mat C=FastMod(A,n-2,Mod);
            Mat ANS=MulMat(C,B,Mod);
            cout<<ANS.a[2][1]<<endl;
        }
    }
    return 0;
}
