#include<bits/stdc++.h>
using namespace std;
long long n,a,b,c,p;
long long g;//g is the pow of a
struct Mat
{
    long long a[4][4];
    int row,column;
    Mat()
    {
        row=column=3;
        memset(a,0,sizeof(a));
        a[1][1]=a[2][2]=a[3][3]=1;
    }
    Mat(int x,int y):row(x),column(y)
    {
       memset(a,0,sizeof(a)); 
    }
    void init(void)//init the matrix
    {
        memset(a,0,sizeof(a));
        a[1][1]=a[2][2]=a[3][3]=1;
    }
    Mat operator *(const Mat& X)const
    {
        int row1,row2,col1,col2;
        row1=this->row;
        row2=X.row;
        col1=this->column;
        col2=X.column;
        Mat ANS(row1,col2);
        for(int i=1;i<=row1;i++)
            for(int j=1;j<=col2;j++)
                for(int k=1;k<=col1;k++)
                {
                    ANS.a[i][j]+=this->a[i][k]*X.a[k][j];
                    ANS.a[i][j]%=p;
                } 
        return ANS;
    }
    Mat& operator =(const Mat& X)
    {
        row=X.row;
        column=X.column;
        for(int i=1;i<=row;i++)
            for(int j=1;j<=column;j++)
                a[i][j]=X.a[i][j];
        return *this;
    }
};
Mat MulMat(Mat X,long long k)
{
    Mat ANS;
    while(k>0)
    {
        if(k&1)
            ANS=ANS*X;
        X=X*X;
        k>>=1;
    }
    return ANS;
}
long long FastMod(long long x,long long k)
{
    long long ans=1;
    while(k>0)
    {
        if(k&1)
        {
            ans*=x;
            ans%=p;
        }
        x=x*x;
        x%=p;
        k>>=1;
    }
    return ans;
}

int main(void)
{
    int T;
    long long ans;
    cin>>T;
    while(T--)
    {
        cin>>n>>a>>b>>c>>p;
        if(a%p==0)
        {
            cout<<0<<endl;
            continue;
        }
        p--;
        if(n==1)
            g=0;
        else if(n==2)
            g=b%p;        
        else
        {
            Mat A(3,3);
            A.a[1][1]=c%p;
            A.a[1][2]=1%p;
            A.a[1][3]=b%p;
            A.a[2][1]=1%p;
            A.a[3][3]=1%p;
            Mat B(3,1);
            B.a[1][1]=b%p;
            B.a[3][1]=1%p;
            Mat C=MulMat(A,n-2);
            Mat ANS=C*B;
            g=ANS.a[1][1];
        }
        p++;
        ans=FastMod(a,g);    
        cout<<ans<<endl;
    }
    return 0;
}

