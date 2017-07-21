#include<stdio.h>
#include<string.h>
int r,c;
char a[12][12];
char temp_input[13];
int b[12][12];//to record the number of each white grid(0 when black)
int iseligible(int x,int y)
{
    if(a[x][y]=='*')
        return 0;
    if((x==1)||(y==1))
        return 1;
    if((a[x][y-1]=='*')||(a[x-1][y]=='*'))
        return 1;
    else
        return 0;
}
void fuzhi(void)
{
    int temp=0;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
    {
        if(iseligible(i,j))
        {
            temp++;
            b[i][j]=temp;
        }
    }
}
void row(void)
{
    int start_position,end_position;
    printf("Across\n");
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
    {
        start_position=j;
        if(!iseligible(i,j))
            continue;
        if((j!=1)&&(a[i][j-1]!='*'))
            continue;
        for(end_position=start_position;end_position<=c;end_position++)
        {
            if(a[i][end_position]=='*')
            {
                end_position--;
                break;
            }
        }
        if(end_position>c)
            end_position=c;
        printf("%3d.",b[i][start_position]);
        for(int k=start_position;k<=end_position;k++)
            printf("%c",a[i][k]);
        printf("\n");

    }
}
void column(void)
{
    int start_position,end_position;
    printf("Down\n");
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
    {
        start_position=i;
        if(!iseligible(i,j))
            continue;
        if((i!=1)&&(a[i-1][j]!='*'))
            continue;
        for(end_position=start_position;end_position<=r;end_position++)
        {
            if(a[end_position][j]=='*')
            {
                end_position--;
                break;
            }
        }
        if(end_position>r)
            end_position=r;
        printf("%3d.",b[start_position][j]);
        for(int k=start_position;k<=end_position;k++)
            printf("%c",a[k][j]);
        printf("\n");

    }
}
int main(void)
{
    //freopen("in.txt","r",stdin);
    //freopen("outwrong.txt","w",stdout);
    int num_puzzle=0;
    while(scanf("%d",&r)&&(r!=0))
    {
        if(num_puzzle)
            printf("\n");
        memset(b,0,sizeof(0));
        scanf("%d",&c);
        num_puzzle++;
        for(int i=1;i<=r;i++)
        {
            scanf("%s",temp_input);
            for(int j=1;j<=c;j++)
                a[i][j]=temp_input[j-1];
        }
        fuzhi();//to allowcate different numbers of each eligible white grid
        printf("puzzle #%d:\n",num_puzzle);
        row();//to print the across words
        column();

    }
    return 0;
}
