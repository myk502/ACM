#include<bits/stdc++.h>
using namespace std;
int n,bg_x,bg_y,rg_x,rg_y,a[12][12];////to record the information of the whole picture
bool ans;//b represents whether there is a place;c represents whether it is safe
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
const int ddx[]={-2,-2,2,2,-1,1,-1,1};
const int ddy[]={-1,1,-1,1,-2,-2,2,2};
/*in 2-d array a,that is the explanation:
0:empty
1:black general
2:red general(G)
3:red chariot(R)
4:red horse(H)
5:red cannon(C)
*/
int center,up,down,leftt,rightt;
bool isinboard(int x,int y)
{
    if((x>=1)&&(x<=10)&&(y>=1)&&(y<=9))
        return true;
    else
        return false;
}
bool isinpalace(int x,int y)//whether the black general is in palace
{
    if((x>=1)&&(x<=3)&&(y>=4)&&(y<=6))
        return true;
    else
        return false;
}
void read(void)
{
    int xx,yy;
    string input;
    char temp;
    for(int i=0;i<n;i++)
    {
        cin>>input>>xx>>yy;
        temp=input[0];
        switch(temp)
        {
            case 'G':
            {
                a[xx][yy]=2;
                rg_x=xx;
                rg_y=yy;
                break;
            }
            case 'R':
            {
                a[xx][yy]=3;
                break;
            }
            case 'H':
            {
                a[xx][yy]=4;
                break;
            }
            case 'C':
            {
                a[xx][yy]=5;
                break;
            }
        }
    }
}
bool fly(int aa,int bb,int cc,int dd)
//whether a general at (a,b) could general fly another general at (c,d)
{
    if(bb!=dd)
        return false;
    bool flag=true;//suppose it could general fly
    for(int i=min(aa,cc)+1;i<max(aa,cc);i++)
        if(a[i][bb])
            flag=false;
    return flag;
}
bool isclear(int aa,int bb,int cc,int dd)
//The road in between(a,b) and (c,d)(except for these 2 points is clear)
//if they are not in a line return false
{
    if((aa!=cc)&&(bb!=dd))
        return false;
    if(aa==cc)
    {
        bool flag=true;
        for(int j=min(bb,dd)+1;j<max(bb,dd);j++)
            if(a[aa][j])
                flag=false;
        return flag;
    }
    if(bb==dd)
    {
        bool flag=true;
        for(int i=min(aa,cc)+1;i<max(aa,cc);i++)
            if(a[i][bb])
                flag=false;
        return flag;
    }
}
bool issafe(void)
{
    int xxx,yyy,xxxx,yyyy;
    for(int i=1;i<=10;i++)
        for(int j=1;j<=9;j++)
        {
            if((a[i][j]==2)&&fly(rg_x,rg_y,bg_x,bg_y))
                return false;
            if((a[i][j]==3)&&isclear(bg_x,bg_y,i,j))
                return false;
            if(a[i][j]==4)
            {
                for(int k=0;k<8;k++)
                {
                    xxx=i+ddx[k];
                    yyy=j+ddy[k];
                    if((xxx==bg_x)&&(yyy==bg_y))
                    {
                        xxxx=i+dx[k/2];
                        yyyy=j+dy[k/2];//the middle point
                        if(!a[xxxx][yyyy])//Actually we do not need to check whether the (xxxx,yyyy)is legal here
                            return false;
                    }
                }
            }
            if(a[i][j]==5)
            {
                if(i==bg_x)
                {
                    int cnt=0;
                    for(int jj=min(j,bg_y)+1;jj<max(j,bg_y);jj++)
                    {
                        if(a[i][jj])
                            cnt++;
                    }
                    if(cnt==1)
                        return false;
                }
                if(j==bg_y)
                {
                    int cnt=0;
                    for(int ii=min(i,bg_x)+1;ii<max(i,bg_x);ii++)
                        if(a[ii][j])
                            cnt++;
                    if(cnt==1)
                        return false;
                }
            }



        }
        return true;
}
void backup(int xx,int yy)
{
    center=a[xx][yy];
    up=a[xx-1][yy];
    down=a[xx+1][yy];
    leftt=a[xx][yy-1];
    rightt=a[xx][yy+1];
}
void recover(int xx,int yy)
{
    a[xx][yy]=center;
    a[xx-1][yy]=up;
    a[xx+1][yy]=down;
    a[xx][yy-1]=leftt;
    a[xx][yy+1]=rightt;
}
int main(void)
{
    int xx,yy;
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    while(cin>>n>>bg_x>>bg_y)
    {
        ans=true;//suppose checkmate will happen
        if(n+bg_x+bg_y==0)
            break;
        memset(a,0,sizeof(a));
        a[bg_x][bg_y]=1;
        //read in the other information
        read();
        //to check whether black general could generally fly in the next step
        if(fly(bg_x,bg_y,rg_x,rg_y))
            ans=false;
        else
        {
            xx=bg_x;
            yy=bg_y;//record the position of bg(now)
            backup(xx,yy);
            for(int k=0;k<4;k++)
            {
                recover(xx,yy);
                a[xx][yy]=0;
                bg_x=xx+dx[k];
                bg_y=yy+dy[k];
                if(!isinpalace(bg_x,bg_y))
                    continue;
                a[bg_x][bg_y]=1;

                if(issafe())
                {
                    //printf("Now the position is(%d,%d)\n",bg_x,bg_y);
                    //printf("a[1][4]=%d  a[1][5]=%d\n",a[1][4],a[1][5]);
                    ans=false;
                }
            }
        }
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}
