#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> G[30];
string input1,input2;
void find_block(int id,int &block,int &height)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<G[i].size();j++)
            if(G[i][j]==id)
            {
                block=i;
                height=j;
                break;
             
            }

        
    }
}
void guiwei(int i,int id)//put the blocks in pile i above (id) to their original pos
{
    int now;
    while((now=G[i][G[i].size()-1])!=id)
    {
        G[now].push_back(now);
        G[i].pop_back();
    }
}

void move(int i,int j,int k)//move the blocks in pile i above j(including j) to block k
{
    int cnt=0;
    for(int ii=j;ii<G[i].size();ii++)
    {
         G[k].push_back(G[i][ii]);
         cnt++;
    }
    for(int ii=0;ii<cnt;ii++)
        G[i].pop_back();
}
void output_answer(void)
{
    for(int i=0;i<n;i++)
    {
         printf("%2d: ",i);
         for(auto it:G[i])
         {
            printf(" %d",it);   
         }
         printf("\n");
    }
}
int main(void)
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int a,b;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        G[i].clear();
        G[i].push_back(i);
    }
    while(cin>>input1)
    {
        if(input1=="quit")
        {
            output_answer();
            break;
        }
        cin>>a>>input2>>b;
        int a_block,a_height,b_block,b_height;
        find_block(a,a_block,a_height);
        find_block(b,b_block,b_height);
        if(a_block==b_block)
            continue;
        if(input1=="move")
        {
            if(input2=="onto")
            {
                guiwei(a_block,a);
                guiwei(b_block,b);
                G[a_block].pop_back();
                G[b_block].push_back(a);
            }
            else
            {
                guiwei(a_block,a);
                G[a_block].pop_back();
                G[b_block].push_back(a);
            }
        }
        else
        {
            if(input2=="onto")
            {
                guiwei(b_block,b);
                move(a_block,a_height,b_block);
            }
            else
            {
                move(a_block,a_height,b_block);
            }
        }
    }


    return 0;
}
