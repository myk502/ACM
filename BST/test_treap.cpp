#include<bits/stdc++.h>
using namespace std;

struct Treap_Node
{
	Treap_Node *lchild,*rchild;
	int val,fix;
};

void Treap_Left_Rotate(Treap_Node* &a)
{
	Treap_Node* b = a -> rchild;
	a ->rchild = b -> lchild;
	b -> lchid = a;
	a = b;
}

void Treap_Right_Rotate(Treap_Node* &a)
{
	Treap_Node* b = a -> lchild;
	a -> lchild = b -> rchild;
	b -> rchild = a;
	a = b;
}

Treap_Node* Treap_Find(Treap_Node* P,int val)
{
	if(!P)
		return NULL;
	if(P -> val == val)
		return P;
	if(val < P -> val)
		return Treap_Find(P -> lchild, val);
	else
		return Treap_Find(P -> rchild, val);
}

void Treap_Insert(Treap_Node* &P, int val)
{
	if(!P)//we have found the pos then build the node

int main(void)
{
	return 0;
}

