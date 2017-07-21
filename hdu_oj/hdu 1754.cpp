#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<climits>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=200000+10;
const int zuida=INT_MAX;
int ans,n,m,a[maxn],father[maxn];
struct Node
{
    int left;
    int right;
    int value;//the max value of students' grades
};
Node node[maxn*4];
void BuildTree(int i,int l,int r)
{
    node[i].left=l;
    node[i].right=r;
    if(l==r)
    {
        father[l]=i;
        node[i].value=a[l];
        return ;
    }
    BuildTree(i<<1,l,(l+r)/2);
    BuildTree((i<<1)+1,(l+r)/2+1,r);
    node[i].value=max(node[i<<1].value,node[(i<<1)+1].value);
}
void UpdateTree(int now)
{
    if(now==1)
        return ;
    int father=now/2;
    int a=node[father<<1].value;
    int b=node[(father<<1)+1].value;
    if(a<b)
        node[father].value=b;
    else
        node[father].value=a;
    UpdateTree(father);
}
void Query(int i,int l,int r)
{
    //printf("Now is scanning(%d,%d)\n",l,r);
    if((node[i].left==l)&&(node[i].right==r))
    {
        ans=max(ans,node[i].value);
        return ;
    }
    i=i<<1;//to get left child node
    if(l<=node[i].right)
    {
        if(r<=node[i].right)
        {
            Query(i,l,r);
        }
        else
        {
            Query(i,l,node[i].right);
        }
    }
    i++;
    if(r>=node[i].left)
    {
        if(l>=node[i].left)
        {
            Query(i,l,r);
        }
        else
        {
            Query(i,node[i].left,r);
        }
    }
}
int main(void)
{
    int aa,bb;
    char order,input[5];
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        BuildTree(1,1,n);
        //printf("m=%d\n",m);
        while(m--)
        {
            scanf("%s",input);
            order=input[0];
            scanf("%d%d",&aa,&bb);
            //printf("order=%c and aa=%d and bb=%d\n",order,aa,bb);
            if(order=='Q')
            {
                ans=INT_MIN;
                Query(1,aa,bb);
                printf("%d\n",ans);
            }
            else
            {
                int x=father[aa];
                node[x].value=bb;
                UpdateTree(x);
            }
        }
    }
    return 0;
}
