#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<string>
#include<math.h>
using namespace std;
char a[105][105];
char b[105];
int aa[100005];
int n,m;
int step=0;
int rr[200];
int main()
{


    cin>>n>>m;
    memset(rr,0,sizeof(rr));
    for (int i=1;i<=n;i++)
    {
        cin>>b;
        for (int j=0;j<m;j++)
        {
            a[i][j+1]=b[j];
        }
    }
    int N;
    cin>>N;
    for (int i=1;i<=N;i++)
    {
        cin>>aa[i];
    }
    int coutt=1;
    int cur=0;
    int statx,staty;
    statx=staty=1;
    char dir;
    dir='>';
    while (a[statx][staty]!='#')
    {
        if (staty<=0){cout<<"RUNTIME ERROR"<<endl;break;}
        if (staty>m){cout<<"RUNTIME ERROR"<<endl;break;}
        if (statx<=0){cout<<"RUNTIME ERROR"<<endl;break;}
        if (statx>n){cout<<"RUNTIME ERROR"<<endl;break;}
        if (a[statx][staty]=='?')
        {
            cur=aa[coutt];
            if (coutt!=N) coutt++;
        }
        if (a[statx][staty]=='!')
        {
            cout<<cur<<endl;
            cur=0;
        }
        if (a[statx][staty]=='+')
        {
            cur++;
            if (cur>100000) {cout<<"OVERFLOW ERROR"<<endl;break;}
        }
        if (a[statx][staty]=='-')
        {
            cur--;
            if (cur<-100000) {cout<<"OVERFLOW ERROR"<<endl;break;}
        }
        if (a[statx][staty]>='A'&&a[statx][staty]<='Z')
        {
            int t;
            t=rr[a[statx][staty]-64];
            rr[a[statx][staty]-64]=cur;
            cur=t;
        }
        if (a[statx][staty]=='^')
        {
            dir='^';
        }
        if (a[statx][staty]=='v')
        {
            dir='v';
        }
        if (a[statx][staty]=='>')
        {
            dir='>';
        }
        if (a[statx][staty]=='<')
        {
            dir='<';
        }
        if (a[statx][staty]=='@')
        {
            int flag=1;
            if (cur==0)
            {
                if (dir=='^'&&flag) {dir='<';flag=0;}
                if (dir=='<'&&flag) {dir='v';flag=0;}
                if (dir=='v'&&flag) {dir='>';flag=0;}
                if (dir=='>'&&flag) {dir='^';flag=0;}
            }
            if (cur!=0)
            {
                if (dir=='^'&&flag) {dir='>';flag=0;}
                if (dir=='>'&&flag) {dir='v';flag=0;}
                if (dir=='v'&&flag) {dir='<';flag=0;}
                if (dir=='<'&&flag) {dir='^';flag=0;}
            }
        }
         if (dir=='<') { staty=staty-1;}
         if (dir=='>') { staty=staty+1;}
         if (dir=='^') { statx=statx-1;}
         if (dir=='v') {statx=statx+1;}
         step=step+1;
         if (step>1000000) {cout<<"TIME LIMIT EXCEEDED"<<endl;break;}
    }
}
