#include<bits/stdc++.h>
using namespace std;
stack<char> s;
stack<char> t;
vector<char> ANS;
int ss[30],n;
char input[100000+10];
void action1(void)//s to t
{
    char x=s.top();
    ss[x-'a']--;
//    if(s.empty())
//    printf("mark1\n");
    s.pop();
    t.push(x);
}
void action2(void)//t to u
{
    char x=t.top();
   // if(t.empty())
   //     printf("mark2\n");
    t.pop();
    ANS.push_back(x);
}
bool action2_ok(void)//if there is no character in s that is smaller than t.top()
{
    if(t.empty())
        return false;//if t is empty,we could just do action1
    char x=t.top();
    bool flag=true;
    for(int i=0;i<x-'a';i++)
    {
        if(ss[i]!=0)
            flag=false;
    }
    return flag;
}
int main(void)
{
    memset(ss,0,sizeof(ss));
    scanf("%s",input);
    n=strlen(input);
    for(int i=n-1;i>=0;i--)
        s.push(input[i]);
    for(int i=0;i<n;i++)
        ss[input[i]-'a']++;
    while(!s.empty()||!t.empty())
    {
        if(action2_ok())
            action2();
        else
            action1();
    }
    for(auto it:ANS)
       printf("%c",it);
    printf("\n"); 
    return 0;
}
