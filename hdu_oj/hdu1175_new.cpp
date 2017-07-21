#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int x1,y1,x2,y2,m,n,a[1010][1010];
int panduan(int xx1,int yy1,int xx2,int yy2)// to judge whether the road between(x1,y1) and (x2,y2) does not exist 0 Attention: using this function must ensure that x1==x2 or y1==y2
{
    int temp=1;
    if(xx1==xx2)
    {
        int yymin=min(yy1,yy2);
        int yymax=max(yy1,yy2);
        for(int i=yymin;i<=yymax;i++)
        {
            if(a[xx1][i]!=0)
            {
                if((xx1==x1)&&(i==y1))
                    continue;
                if((xx1==x2)&&(i==y2))
                    continue;
                temp=0;
                break;
            }
        }
    }
    else
    {
        int xxmax=max(xx1,xx2);
        int xxmin=min(xx1,xx2);
        for(int i=xxmin;i<=xxmax;i++)
            if(a[i][yy1]!=0)
            {
                if((i==x1)&&(yy1==y1))
                    continue;
                if((i==x2)&&(yy1==y2))
                    continue;
                temp=0;
                break;
            }
    }
    //printf("From(%d,%d) to (%d,%d):%d\n",xx1,yy1,xx2,yy2,temp);
    return temp;
}
int main(void)
{
    freopen("E:\\in.txt","r",stdin);
	freopen("E:\\out2.txt","w",stdout);
    int q,status;//status stands for whether the two chosen chess can be offset
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n*m==0)
            break;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if((x1<1)||(x1>n)||(x2<1)||(x2>n)||(y1<1)||(y1>m)||(y2<1)||(y2>m))
            {
                printf("NO\n");
                continue;
            }
            if((x1==x2)&&(y1==y2))
            {
                printf("NO\n");
                continue;
            }
            if((a[x1][y1]==a[x2][y2])&&(a[x1][y1]!=0))//Attention! I don't consider the situation that the two input is the same point
            {
                status=0;
                if(x1==x2)//in the same row
                {
                    if(panduan(x1,y1,x2,y2)==1)
                        status=1;
                    if(status==0)//it needs three turnings
                    {
                        for(int x3=1;(x3<=n)&&(x3!=x1);x3++)
                        {
                            if((panduan(x1,y1,x3,y1))&&(panduan(x3,y1,x3,y2))&&(panduan(x3,y2,x2,y2)))
                            {
                                status=1;
                                break;
                            }
                        }
                    }
                }
                if(y1==y2)
                {
                    if(panduan(x1,y1,x2,y2)==1)
                        status=1;
                    if(status==0)
                    {
                        for(int y3=1;(y3<=m)&&(y3!=y1);y3++)
                        {
                            if(panduan(x1,y1,x1,y3)&&panduan(x1,y3,x2,y3)&&panduan(x2,y3,x2,y2))
                            {
                                status=1;
                                break;
                            }
                        }
                    }
                }
                if((x1!=x2)&&(y1!=y2))
                {
                    if(panduan(x1,y1,x1,y2)&&panduan(x1,y2,x2,y2))
                        status=1;
                    if(panduan(x1,y1,x2,y1)&&panduan(x2,y1,x2,y2))
                        status=1;// just 1 turnings
                    if(status==0)//need two turnings
                    {
                        int ymin=min(y1,y2),xmin=min(x1,x2),ymax=max(y1,y2),xmax=max(x1,x2);
                        for(int y3=ymin+1;y3<ymax;y3++)
                        {
                            if(panduan(x1,y1,x1,y3)&&panduan(x1,y3,x2,y3)&&panduan(x2,y3,x2,y2))
                            {
                                status=1;
                                break;
                            }
                        }
                        if(status==0)
                        {
                            for(int x3=xmin+1;x3<xmax;x3++)
                            {

                                if(panduan(x1,y1,x3,y1)&&panduan(x3,y1,x3,y2)&&panduan(x3,y2,x2,y2))
                                {
                                    status=1;
                                    break;
                                }
                            }
                        }
                    }

                }
                if(status==0)
                    printf("NO\n");
                else
                    printf("YES\n");

            }
            else
                printf("NO\n");
        }

    }
    return 0;
}
