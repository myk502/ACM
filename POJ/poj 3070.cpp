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
int input;
struct Mat
{
    int line;
    int column;
    int a[4][4];
    Mat()
    {
        line=column=2;
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

    while(scanf("%d",&input))
    {
        if(input==-1)
            break;
        Mat X;
        X.a[1][2]=1;
        X.a[2][1]=1;
        X.a[2][2]=0;
        if(input==0)
            printf("%d\n",0);
        else
        {
            Mat Y=FastMod(X,input-1,10000);
            //printf("Y=\n%d %d\n%d %d\n",Y.a[1][1],Y.a[1][2],Y.a[2][1],Y.a[2][2]);
            Mat temp(2,1);
            temp.a[1][1]=1;
            temp.a[2][1]=1;
            Mat Z=MulMat(Y,temp,10000);
            printf("%d\n",Z.a[2][1]);
        }

    }



    return 0;
}
