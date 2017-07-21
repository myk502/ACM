#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
const int max1=100;//what the hell?
const double EPS=1e-5;
char sid[maxn][max1],name[maxn][max1];
int cid[maxn],score[maxn][5],n=0,total[maxn];//n represents the number of students
bool removed[maxn];//to determine whether this student has been removed
const char *subject[4]={"Chinese","Mathematics","English","Programming"};
int rnk(int x)//looking for the rank of the i-th student
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if((!removed[i])&&(total[i]>total[x]))//important! not removed!
            cnt++;
    }
    return cnt+1;
}
int valid(int u)
{
    for(int i=0;i<u;i++)
        if(!strcmp(sid[i],sid[u]) && !removed[i])
            return 0;
    return 1;
}
void ADD(void)
{
    while(true)
    {
        printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
        scanf("%s",sid[n]);
        if(!strcmp(sid[n],"0"))
            break;//if the input suggests the end
        scanf("%d%s%d%d%d%d",&cid[n],name[n],&score[n][0],&score[n][1],&score[n][2],&score[n][3]);//scanf the information of a new student
        if(valid(n))
        {
            total[n]=score[n][0]+score[n][1]+score[n][2]+score[n][3];
            removed[n]=false;
            n++;
        }
        else
            printf("Duplicated SID.\n");
    }
}
void DQ(int isq)//isq means is a query
{
    char input[max1];
    int cnt=0;

    while(true)
    {
        printf("Please enter SID or name. Enter 0 to finish.\n");
        scanf("%s",input);
        cnt=0;
        if(strcmp(input,"0")==0)
            break;
        for(int i=0;i<n;i++)
        {
            if(!removed[i]&&(   strcmp(sid[i],input)==0||strcmp(name[i],input)==0))
            {
                if(!isq)//not a query, is a remove
                {
                    removed[i]=true;
                    cnt++;
                }
                else
                {
                    printf("%d %s %d %s %d %d %d %d %d %.2f\n",rnk(i),sid[i],cid[i],name[i],score[i][0],score[i][1],score[i][2],score[i][3],total[i],total[i]/(4.0+EPS));
                }
            }
        }
        if(!isq)
            printf("%d student(s) removed.\n",cnt);
    }
}
void RANK(void)
{
    printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
}
void stat(void)
{
    printf("Please enter class ID, 0 for the whole statistics.\n");
    int a,cnt=0,pass[5][2];
    double ave[4];
    scanf("%d",&a);
    memset(ave,0,sizeof(ave));
    memset(pass,0,sizeof(pass));
    for(int i=0;i<n;i++)
        if(((cid[i]==a)||(a==0))&&(!removed[i]))
        {
            int c=0;
            cnt++;
            for(int j=0;j<4;j++)
            {
                ave[j]+=score[i][j];
                if(score[i][j]>=60)
                {
                    pass[j][0]++;//this represents how many students have passed subject j
                    c++;
                }
            }//c finally represents how many subjects a student have passed
            pass[c][1]++;
        }
        if(cnt)
            for(int i=0;i<4;i++)
                ave[i]=ave[i]/(double)cnt+EPS;
        for(int i=0;i<4;i++)
            printf("%s\nAverage Score: %.2f\nNumber of passed students: %d\nNumber of failed students: %d\n\n",subject[i],ave[i],pass[i][0],cnt-pass[i][0]);
        printf("Overall:\n");
        printf("Number of students who passed all subjects: %d\n",pass[4][1]);
        printf("Number of students who passed 3 or more subjects: %d\n",pass[3][1]+pass[4][1]);
        printf("Number of students who passed 2 or more subjects: %d\n",pass[3][1]+pass[4][1]+pass[2][1]);
        printf("Number of students who passed 1 or more subjects: %d\n",cnt-pass[0][1]);
        printf("Number of students who failed all subjects: %d\n\n",pass[0][1]);


}
int main(void)
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int choice;
    while(true)
    {
        printf("Welcome to Student Performance Management System (SPMS).\n\n");
        printf("1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n");
        printf("5 - Show Statistics\n0 - Exit\n\n");
        cin>>choice;
        if(choice==0)
            break;
        switch(choice)
        {
            case 1:ADD();break;
            case 2:DQ(0);break;//remove a student
            case 3:DQ(1);break;//query a student
            case 4:RANK();break;
            case 5:stat();break;
        }
    }
    return 0;
}
