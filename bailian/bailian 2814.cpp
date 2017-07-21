#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
//#include<math.h>
#include<algorithm>
using namespace std;
int a[5][5],b[5][5],beifen[5][5];
bool iseligble(void)
{
    int status=1;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
        if(a[i][j]!=0)
            status=0;
    return status;
}
void put(int x,int y,int t)
{
    if((y==1)&&(x==1))
    {
        a[x][y]=(a[x][y]+t)%4;
        a[x][y+1]=(a[x][y+1]+t)%4;
        a[x+1][y]=(a[x+1][y]+t)%4;
        a[x+1][y+1]=(a[x+1][y+1]+t)%4;
    }
    if((x==1)&&(y==2))
    {
        a[x][y]=(a[x][y]+t)%4;
        a[x][y-1]=(a[x][y-1]+t)%4;
        a[x][y+1]=(a[x][y+1]+t)%4;
    }
    if((x==1)&&(y==3))
    {
        a[x][y]=(a[x][y]+t)%4;
        a[x][y-1]=(a[x][y-1]+t)%4;
        a[x+1][y]=(a[x+1][y]+t)%4;
        a[x+1][y-1]=(a[x+1][y-1]+t)%4;
    }
    if((x==2)&&(y==1))
    {
        a[x][y]=(a[x][y]+t)%4;
        a[x-1][y]=(a[x-1][y]+t)%4;
        a[x+1][y]=(a[x+1][y]+t)%4;
    }
    if((x==2)&&(y==2))
    {
        a[x][y]=(a[x][y]+t)%4;
        a[x-1][y]=(a[x-1][y]+t)%4;
        a[x+1][y]=(a[x+1][y]+t)%4;
        a[x][y-1]=(a[x][y-1]+t)%4;
        a[x][y+1]=(a[x][y+1]+t)%4;
    }
    if((x==2)&&(y==3))
    {
        a[x][y]=(a[x][y]+t)%4;
        a[x-1][y]=(a[x-1][y]+t)%4;
        a[x+1][y]=(a[x+1][y]+t)%4;
    }
    if((x==3)&&(y==1))
    {
        a[x][y]=(a[x][y]+t)%4;
        a[x-1][y]=(a[x-1][y]+t)%4;
        a[x][y+1]=(a[x][y+1]+t)%4;
        a[x-1][y+1]=(a[x-1][y+1]+t)%4;
    }
    if((x==3)&&(y==2))
    {
        a[x][y]=(a[x][y]+t)%4;
        a[x][y-1]=(a[x][y-1]+t)%4;
        a[x][y+1]=(a[x][y+1]+t)%4;
    }
    if((x==3)&&(y==3))
    {
        a[x][y]=(a[x][y]+t)%4;
        a[x-1][y]=(a[x-1][y]+t)%4;
        a[x][y-1]=(a[x][y-1]+t)%4;
        a[x-1][y-1]=(a[x-1][y-1]+t)%4;
    }
}


int main(void)
{
    int x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,y1,y2,y3,y4,y5,y6,y7,y8,y9,y10,y11,y12;
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
        {
            cin>>a[i][j];
            b[i][j]=a[i][j];
        }
    int ans=100000;
    //printf("%d\n",iseligble());
    //memset(b,0,sizeof(b));
    for(x1=0;x1<4;x1++)
    for(x2=0;x2<4;x2++)
    for(x3=0;x3<4;x3++)
    for(x4=0;x4<4;x4++)
    for(x5=0;x5<4;x5++)
    for(x6=0;x6<4;x6++)
    for(x7=0;x7<4;x7++)
    for(x8=0;x8<4;x8++)
    for(x9=0;x9<4;x9++)

    {
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                a[i][j]=b[i][j];
        put(1,1,x1);
        put(1,2,x2);
        put(1,3,x3);
        put(2,1,x4);
        put(2,2,x5);
        put(2,3,x6);
        put(3,1,x7);
        put(3,2,x8);
        put(3,3,x9);
        if(iseligble())
        {
            //printf("yes!\n");
            //cout<<x1<<x2<<x3<<x4<<x5<<x6<<x7<<x8<<x9;
            if(x1+x2+x3+x4+x5+x6+x7+x8+x9<ans)
            {
                y1=x1;
                y2=x2;
                y3=x3;
                y4=x4;
                y5=x5;
                y6=x6;
                y7=x7;
                y8=x8;
                y9=x9;
                ans=x1+x2+x3+x4+x5+x6+x7+x8+x9;
            }
        }

    }
    //cout<<y1<<y2<<y3<<y4<<y5<<y6<<y7<<y8<<y9<<endl;

    if(y1!=0)
        for(int i=0;i<y1;i++)
        printf("1 ");
    if(y2!=0)
        for(int i=0;i<y2;i++)
        printf("2 ");
    if(y3!=0)
        for(int i=0;i<y3;i++)
        printf("3 ");
    if(y4!=0)
        for(int i=0;i<y4;i++)
        printf("4 ");
    if(y5!=0)
        for(int i=0;i<y5;i++)
        printf("5 ");
    if(y6!=0)
        for(int i=0;i<y6;i++)
        printf("6 ");
    if(y7!=0)
        for(int i=0;i<y7;i++)
        printf("7 ");
    if(y8!=0)
        for(int i=0;i<y8;i++)
        printf("8 ");
    if(y9!=0)
        for(int i=0;i<y9;i++)
        printf("9 ");


    return 0;
}
