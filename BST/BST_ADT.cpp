#include<bits/stdc++.h>
using namespace std;
//The declaration of BinNode
struct  BinNode
{
    BinNode *lchild,*rchild;
    int data;
    //BinNode *parent;we do not need a parent in treap
    BinNode(int x=0):data(x){}
};
//Inorder traverse the subtree of P
void Inorder_traverse(BinNode* P)
{
    if(P)
    {
        In_traverse(P->lchild);
        printf("%d\n",P->data);
        In_traverse(P->rchild);
    }
}
//search v in the subtree of P and return the pointer to it
//return NULL if found failed
BinNode* BST_search(BinNode *P,int v)
{
    if(!P)
        return NULL;//search failed
    if(P->data==v)
        return P;
    else if(v<P->data)
        return BST_search(P->lchild,v);
    else
        return BST_search(P->rchild,v);
}
//insert v to the subtree of P and return the pointer to it
BinNode* BST_insert(BinNode* &P,int v)//reference to a pointer
{
    if(!P)//create a new BinNode here and report insert success
    {
        P=new BinNode(v);
        return P;
    }
    else
    {
        if(v<=P->data)
            return BST_insert(P->lchild,v);
        else
            return BST_insert(P->rchild,v);
    }
}
//delete the minimal node in subtree P and return the value
int BST_deletemin(BinNode* &P)
{
    if(P->lchild==NULL)//if there is no more lchild
    //then P is the minimal node and we delete it
    {
        BinNode* temp=P;//for backup
        int value=P->data;
        P=P->rchild;//important! P is a reference to its parents' 'lchild' instance
        //varible,so we are now changint P's parent's lchild
        delete temp;
        return value;
    }
    else
        return BST_deletemin(P->lchild);

}
int BST_deletemax(BinNode* &P)//the same as above
{
    if(P->rchild==NULL)
    {
        BinNode* temp=P;
        int value=P->data;
        P=P->lchild;
        delete temp;
        return value;
    }
    else
        return BST_deletemin(P->rchild);
}
bool BST_delete(BinNode* &P,int v)//delete v in subtree P,return whether we delete it
{
    if(P==NULL)
        return false;
    if(P->data==v)//search success and we shall delete it
    {
        if(P->lchild&&P->rchild)//have both childs
        {
            int ca=rand()%2;
            if(ca)
                P->data=BST_deletemin(P->rchild);
            else
                P->data=BST_deletemax(P->lchild);
        }
        else//have only one child
        {
            BinNode* temp=P;
            if(P->lchild!=NULL)
                P=P->lchild;
            else
                P=P->rchild;
            delete temp;
        }
        return true;
    }
    else if(v<=P->data)
        return BST_delete(P->lchild,v);
    else
        return BST_delete(P->rchild,v);
}
int main(void)
{
    BinNode *root=new BinNode;
    for(int i=0;i<100;i++)
        BST_insert(root,i);
    printf("%p\n",BST_search(root,43));
    BST_delete(root,43);
    printf("%p\n",BST_search(root,43));
    delete root;
    return 0;
}
