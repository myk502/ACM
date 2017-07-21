#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<cfloat>
#include<sstream>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
int a,b,n;
struct Mat
{
    int line;
    int column;
    int a[5][5];
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
    return(MulMat(A,B,7));
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
    int ans;
    while(cin>>a>>b>>n)
    {
        if((a==0)&&(b==0)&&(n==0))
            break;
        if((n==1)||(n==2))
        {
            printf("1\n");
            continue;
        }
        else
        {
            Mat D(2,2);
            D.a[1][1]=a%7;
            D.a[1][2]=b%7;
            D.a[2][1]=1;
            D.a[2][2]=0;
            Mat E=FastMod(D,n-2,7);
            ans=E.a[1][1]+E.a[1][2];
            ans%=7;
            printf("%d\n",ans);
        }
    }
    return 0;
}
