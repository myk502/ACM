#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<climits>
#include<string>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int n,m;
char input[600000+10];
char beifen;
char toxiao(char x)
{
    if(x=='a')
        return 'b';
    if(x=='b')
        return 'a';
    if(x=='c')
        return 'a';
}
char toda(char x)
{
    if(x=='c')
        return 'b';
    else
        return 'c';
}
typedef struct Trie_Node
{
    int exist;
    struct Trie_Node* next[3];
}TrieNode,*Node;
Node Create_Node(void)
{
    Node p=(Node)malloc(sizeof(Trie_Node));
    p->exist=0;
    p->next[0]=p->next[1]=p->next[2]=NULL;
    return p;
}
void Insert_Node(Node root,char *s)
{
    Node p=root;
    int idx,i=0;
    while(s[i]!='\0')
    {
        idx=s[i]-'a';
        if(p->next[idx]==NULL)
        {
            Node pp=Create_Node();
            p->next[idx]=pp;
        }
        p=p->next[idx];
        if(input[i+1]=='\0')
        {
            p->exist=1;
        }
        i++;
    }
}
bool dfs(Node p,int i,int flag)//i means the index of the char,flag==0 means no mistake has been made
{
    int idx=input[i]-'a';
    if(input[i]=='\0')
    {
        if((p->exist==1)&&(flag==1))
            return true;
        else
            return false;
    }
    if(p->next[idx]!=NULL)
    {
        if(dfs(p->next[idx],i+1,flag))
            return true;
    }
    if(flag==0)
    {
        for(int j=0;j<3;j++)
        {
            if((j!=idx)&&(p->next[j]!=NULL))
                if(dfs(p->next[j],i+1,1))
                    return true;
        }
    }

    return false;
}
int main(void)
{
    cin>>n>>m;
    bool ans;
    Node root=Create_Node();
    for(int i=0;i<n;i++)
    {
        scanf("%s",input);
        Insert_Node(root,input);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%s",input);
        ans=dfs(root,0,0);
        //ans=iseligble(root,input);
        if(ans)
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }

    return 0;
}
