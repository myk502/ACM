#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
bool flag=true;
char input[300];
vector<int> ANS;
struct Node
{
	bool has_value=false;
	int value;
	Node *lchild,*rchild;
};
Node *root=NULL;
queue<Node*> q;
void destroy_tree(Node* root)
{
	if(root==NULL)
		return;
	destroy_tree(root->lchild);
	destroy_tree(root->rchild);
	delete(root);
}
bool add_node(int v,char* path)
{
	//printf("v=%d ,path=%s\n",v,path);
	//printf("We are adding Node whose value is %d\n",v);
	if(root==NULL)
		root=new Node();
	Node* now=root;
	int n=strlen(path);
	for(int i=0;i<n;i++)
	{
		if(path[i]=='L')//to left
		{
			if(now->lchild==NULL)
				now->lchild=new Node();
			now=now->lchild;
		}
		else if(path[i]=='R')
		{
			if(now->rchild==NULL)
				now->rchild=new Node();
			now=now->rchild;
		}
	}
	if(now->has_value)
		flag=false;
	now->has_value=true;
	now->value=v;
	return flag;
}
bool read_data(void)
{
	int v;
	if(scanf("%s",input)==EOF)
		return false;//end of file now
	while(1)
	{
		if(!strcmp(input,"()"))
			break;//The end of this tree
		sscanf(input+1,"%d",&v);
		char* path=strchr(input,',');
		add_node(v,path+1);
		scanf("%s",input);
	}
	return true;//successfully read a tree
}
/*
void inorder_traverse(Node* root)
{
	if(root==NULL)
		return ;
	inorder_traverse(root->lchild);
	cout<<root->value<<" ";
	inorder_traverse(root->rchild);
}
*/
bool bfs(void)
{
	if(root==NULL)
	{
		while(1)
		{

		}
	}
	q.push(root);
	while(!q.empty())
	{
		Node* now=q.front();
		q.pop();
		if(!now->has_value)
			flag=false;
		ANS.push_back(now->value);
		if(now->lchild)
			q.push(now->lchild);
		if(now->rchild)
			q.push(now->rchild);
	}
	return flag;
	
}
int main(void)
{
	while(1)
	{
		ANS.clear();
		while(!q.empty())
			q.pop();
		flag=true;
		destroy_tree(root);
		root=NULL;
		if(!read_data())
			break;
		bfs();
		if(flag)
		{
			int len=ANS.size();
			if(len>0)
				printf("%d",ANS[0]);
			for(int i=1;i<len;i++)
				printf(" %d",ANS[i]);
			cout<<endl;
		}
		else
			printf("not complete\n");
	}
	return 0;
}
