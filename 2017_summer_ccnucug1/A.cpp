#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<string>
#include<set>
#include<sstream>
#include<queue>
#include<algorithm>
using namespace std;
int k,n,m,a[1010][1010];//a is the map,1 means could go
char character[1010][1010];
int row[1010][1010],col[1010][1010];//prefix sum
char input[1010];
typedef pair<char,int> instruction;
vector<instruction> b;//b is a vector of instructions
typedef pair<int,int> coordiante;
vector<coordiante> start_point;

bool iseligble(int x,int y)
{
    return( x>=1 && x<=n && y>=1 && y<=m);
}

coordiante get_next_pos(coordiante pre,instruction ins)
{
    int xx=pre.first,yy=pre.second,len=ins.second;
    char dir=ins.first;
    int x=xx,y=yy;
    if(dir=='N')
        x-=len;
    if(dir=='S')
        x+=len;
    if(dir=='W')
        y-=len;
    if(dir=='E')
        y+=len;
    return make_pair(x,y);
}
void readin(void)
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",input);
        for(int j=1;j<=m;j++)
        {
            character[i][j]=input[j-1];
            if(input[j-1]=='#')//This block is sea
                a[i][j]=0;
            else
            {
                a[i][j]=1;
                if(input[j-1]!='.')
                    start_point.push_back(make_pair(i,j) );
            }
        }
                    
    }
    cin>>k;
    scanf("\n");
    while(k--)
    {
        char dir;
        int len;
        string temp;
        getline(cin,temp);
        stringstream ss(temp);
        ss>>dir>>len;
        b.push_back(make_pair(dir,len) );
    }
}

void init(void)
{
    memset(row,0,sizeof(row));
    memset(col,0,sizeof(col));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            row[i][j]=row[i][j-1];
            if(a[i][j]==0)//This block is sea
                row[i][j]++;
        }
    }
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            col[i][j]=col[i-1][j];
            if(a[i][j]==0)
                col[i][j]++;
        }
    }
}

bool isok(coordiante start)
{
    bool flag=true;
    int xx=start.first,yy=start.second;
    int x=xx,y=yy;
    coordiante temp;
    for(auto it:b)
    {
        temp=get_next_pos(make_pair(x,y),it);
        xx=x;
        yy=y;
        x=temp.first;
        y=temp.second;
        if(!iseligble(x,y))
        {
            flag=false;
            break;
        }
        if(a[x][y]==0)
        {
            flag=false;
            break;
        }
        if(xx==x)//move on the same row
        {
            if(row[xx][yy]!=row[x][y])
            {
                flag=false;
                break;
            }
        }
        else
        {
            if(col[xx][yy]!=col[x][y])
            {
                flag=false;
                flag=false;
                break;
            }
        }
    }
    return flag;
}




int main(void)
{
    vector<char> ANS;
    readin();
    init();
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            printf("%d ",row[i][j]);
        printf("\n");
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            printf("%d ",col[i][j]);
        printf("\n");
    }
    */
    for(auto it:start_point)
    {
        if(isok(it))
            ANS.push_back(character[it.first][it.second]);
    }
    sort(ANS.begin(),ANS.end());
    if(ANS.empty())
    {
        printf("no solution\n");
        return 0;
    }
    for(auto it:ANS)
        cout<<it;
    cout<<endl;
    return 0;
}
