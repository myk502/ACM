#include<stdio.h>
#include<ctype.h>
#include<string.h>
char a[10][10];
int cnt=0;
bool panduan(int i,int j)
{
    if((i>=0)&&(i<5)&&(j>=0)&&(j<5))
        return true;
    else return false;
}
void shuchu(void)
{
    int k,m;
    printf("\n");
    for(k=0;k<5;k++)
    {
        for(m=0;m<5;m++)
        {
            printf("%c",a[k][m]);
        }
        printf("\n");
    }
    printf("\n");
}
int main(void)
{
    char temp,temp1,temp2;
    int i,j,status,temp_x,temp_y,num=1;
    while((temp=getchar())&&(temp!='Z'))
    {
        if(temp=='\n')
            continue;

        a[0][0]=temp;
        if(temp==' ')
            temp_x=temp_y=0;

        for(i=0;i<5;i++)
            for(j=0;j<=5;j++)
            {

                if((i==0)&&(j==0))
                    continue;
                temp2=getchar();
                if(temp2=='\n')
                    continue;
                a[i][j]=temp2;

                if(temp2==' ')
                {

                    temp_x=i;
                    temp_y=j;
                }


            }
        status=1;


        //printf("\nNow temp_x=%d and temp_y=%d\n",temp_x,temp_y);
        while((temp1=getchar()) &&(temp1!='0'))
        {

            switch(temp1)
            {
                case 'A':

                             if(temp_x<=0)
                                status=0;
                             else
                             {
                                 a[temp_x][temp_y]=a[temp_x-1][temp_y];
                                 a[--temp_x][temp_y]=' ';
                             }
                             //shuchu();
                             break;

                case 'B':

                             if(temp_x>=4)
                                status=0;
                             else
                             {
                                 a[temp_x][temp_y]=a[temp_x+1][temp_y];
                                 a[++temp_x][temp_y]=' ';
                             }
                             //shuchu();
                             break;

                case 'L':

                             if(temp_y<=0)
                                status=0;
                             else
                             {
                                 a[temp_x][temp_y]=a[temp_x][temp_y-1];
                                 a[temp_x][--temp_y]=' ';
                             }
                             //shuchu();
                             break;

                case 'R':

                             if(temp_y>=4)
                                status=0;
                             else
                             {
                                  a[temp_x][temp_y]=a[temp_x][temp_y+1];
                                  a[temp_x][++temp_y]=' ';
                             }
                             //shuchu();
                             break;
                case '\n':
                             break;

                default:status=0;
                        break;

            }
            //printf("Now the step is %c and status=%d\n",temp1,status);


        }
        if(cnt++)
            printf("\n");
        printf("Puzzle #%d:\n",num++);
        if(status==0)
            printf("This puzzle has no final configuration.\n");
        else
        {
            for(i=0;i<5;i++)
            {
                for(j=0;j<4;j++)
                {
                    printf("%c ",a[i][j]);
                }
                printf("%c",a[i][4]);
                printf("\n");
            }

        }

    }
    return 0;

}
