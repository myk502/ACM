/*
ID:myk5021
LANG:C++
TASK:beads
*/
int x,n,num,i,j,status[1100];
char temp1,temp2;
char s[1100],s1[400],s2[400];
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream.h>
#include<math.h>
using namespace std;
int findu(int x)
{
    for(i=0;i<n;i++)
        s[i]=s1[i];
    for(i=n;i<2*n;i++)
        s[i]=s1[i-n];
    for(i=2*n;i<3*n;i++)
        s[i]=s1[i-2*n];
    s[3*n]='\0';

    memset(status,0,sizeof(status));
    num=2;
    status[x]=1;
    x+=n;
    temp1=s[x];
    temp2=s[x+1];

    status[(x+1)%n]=1;
    for(i=x-1;i>=0;i--)
    {
        if(status[i%n]==1)
            break;
        //printf("i=%d and s[i]=%c\n",i,s[i]);
        if((s[i]=='w')||(s[i]==temp1))
            {
                status[i%n]=1;
                num++;


            }
        else
            break;
    }
    for(j=x+2;j<3*n;j++)
    {
        if(status[j%n]==1)
            break;
        if((s[j]=='w')||(s[j]==temp2))
        {
            status[j%n]=1;
            num++;

        }
        else
            break;
    }
    //printf("over");
    return(num);


}

int main(void)
{
    FILE *fin=fopen("beads.in","r");
    FILE *fout=fopen("beads.out","w");
    //FILE *fin=stdin;
    //FILE *fout=stdout;
    int tempn=0,myk,maxn=0;
    int temp3,temp4,temp5,temp6;
    fscanf(fin,"%d",&n);
    fscanf(fin,"%s",s1);
    strcpy(s2,s1);

    for(myk=0;myk<n;myk++)
    {
        if((s1[myk]=='w')&&(s1[(myk+1)%n]!='w'))
        {
            strcpy(s1,s2);
            s1[myk]='r';
            temp3=findu(myk);
            strcpy(s1,s2);
            s1[myk]='b';
            temp4=findu(myk);
            tempn=max(temp3,temp4);
        }
        if((s1[myk]=='w')&&(s1[(myk+1)%n]=='w'))
        {
            strcpy(s1,s2);
            s1[myk]='r';
            s1[(myk+1)%n]='r';
            temp3=findu(myk);
            strcpy(s1,s2);
            s1[myk]='b';
            s[(myk+1)%n]='b';
            temp4=findu(myk);
            strcpy(s1,s2);
            s1[myk]='r';
            s1[(myk+1)%n]='b';
            temp5=findu(myk);
            strcpy(s1,s2);
            s1[myk]='b';
            s1[(myk+1)%n]='r';
            temp6=findu(myk);
            tempn=max(temp3,temp4);
            tempn=max(tempn,temp5);
            tempn=max(tempn,temp6);
            //printf("#3=%d   #4=%d   #5=%d   #6=%d\n",temp3,temp4,temp5,temp6);
        }
        if((s1[myk]!='w')&&(s1[(myk+1)%n]=='w'))
        {
            strcpy(s1,s2);
            s1[(myk+1)%n]='r';
            temp3=findu(myk);
            strcpy(s1,s2);
            s1[(myk+1)%n]='b';
            temp4=findu(myk);
            tempn=max(temp3,temp4);
        }
         strcpy(s1,s2);

         if((s1[myk]!='w')&&(s1[(myk+1)%n]!='w'))
            tempn=findu(myk);
        maxn=(tempn>maxn)?tempn:maxn;
        //printf("Now myk=%d and tempn=%d\n",myk,tempn);

    }
    fprintf(fout,"%d\n",maxn);
    return 0;
}
