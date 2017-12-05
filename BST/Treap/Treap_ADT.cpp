#include<bits/stdc++.h>
using namespace std;
struct Treap_Node
{
    Treap_Node *lchild,*rchild,*parent;//left child,right child,parent
    int data,fix;
    Treap_Node(int x=0):data(x),lchild(NULL),rchild(NULL),parent(NULL)
    {
        fix=rand();
    }
};
void Treap_left_rotate(Treap_Node* a)
{
    if(a==NULL)//degeneracy
        return ;
    Treap_Node* b=a->rchild;//the new root
    if(a->parent!=NULL)//change the ancestor's lchild or rchild
    {
        if(a==a->parent->lchild)//if a is lchild of its parent
            a->parent->lchild=b;
        else
            a->parent->rchild=b;
    }
    b->parent=a->parent;//b will take the place of a so b->parent will point to a->parent
    a->parent=b;
    if(b->lchild)
        b->lchild->parent=a;
    a->rchild=b->lchild;
    b->lchild=a;
}
void Treap_right_rotate(Treap_Node* a)
{
    if(a==NULL)
        return ;
    Treap_Node* b=a->lchild;
    if(a->parent!=NULL)//change the ancestor's lchild or rchild
    {
        if(a==a->parent->lchild)
            a->parent->lchild=b;
        else
            a->parent->rchild=b;
    }
    b->parent=a->parent;
    a->parent=b;
    if(b->rchild)
        b->rchild->parent=a;
    a->lchild=b->rchild;
    b->rchild=a;
}

void Inorder_traverse(Treap_Node *p)
{
    if(p==NULL)
        return ;
    Inorder_traverse(p->lchild);
    printf("%d\n",p->data);
    Inorder_traverse(p->rchild);
}
Treap_Node* Treap_search(Treap_Node* p,int v)//if v exists,return its position;else return its parent(possible insertion position)
//if p is NULL then return NULL
{
    if(p==NULL)
        return NULL;
    while(p->data!=v)
    {
        if(v<=p->data)
        {
            if(p->lchild!=NULL)
                p=p->lchild;
            else
                break;//we will insert here
        }
        else
        {
            if(p->rchild!=NULL)
                p=p->rchild;
            else
                break;
        }
    }
    return p;//2 cases,we found p then does not satisfy the while conditon;or through the break
}
Treap_Node* Treap_insert(Treap_Node* p,int v)//with no duplicate
{
    p=Treap_search(p,v);
    if(p==NULL)
        return NULL;//to avoid v is root's value(root is also a node!)
    Treap_Node* ptr=NULL;//a pointer to the inserted node
    if(v==p->data)
        ptr=p;//already existed,no need for insertion
    else if(v<p->data)
    {
        p->lchild=new Treap_Node(v);
        p->lchild->parent=p;
        ptr=p->lchild;
    }
    else
    {
        p->rchild=new Treap_Node(v);
        p->rchild->parent=p;
        ptr=p->rchild;
    }
    while(ptr->parent&&(ptr->fix<ptr->parent->fix))//need rotating
    {
        if(ptr->parent->lchild==ptr)//ptr is lchild
            Treap_right_rotate(ptr->parent);
        else//ptr is rchild
            Treap_left_rotate(ptr->parent);

    }
    return ptr;
}

bool Treap_delete(Treap_Node* p,int v)//delete the Node with data v in subtree p
//return success or failure
{
    if(p==NULL)
        return false;
    p=Treap_search(p,v);
    if(p->data!=v)
        return false;//The Node v does not exist
    while(p->lchild&&p->rchild)//the special delete way of treap
    //see this page:http://www.docin.com/p-456402313.html?qq-pf-to=pcqq.c2c
    {
        if(p->lchild->fix<p->rchild->fix)
            Treap_right_rotate(p);
        else
            Treap_left_rotate(p);
    }
    if((p->lchild==NULL)&&(p->rchild==NULL))//no children
    {
        if(p->parent->lchild==p)//p is lchild of its parent
            p->parent->lchild=NULL;
        else
            p->parent->rchild=NULL;
        delete p;
    }
    else if(p->lchild!=NULL)//has lchild
    {
        p->data=p->lchild->data;
        delete(p->lchild);
        p->lchild=NULL;
    }
    else
    {
        p->data=p->rchild->data;
        delete(p->rchild);
        p->rchild=NULL;
    }

}
void Treap_destroy(Treap_Node* p)
{
    if(p->lchild)
        Treap_destroy(p->lchild);
    if(p->rchild)
        Treap_destroy(p->rchild);
    delete p;
}
int Treap_findmin(Treap_Node* p)//find the minimum value in subtree p
{
    while(p->lchild)
        p=p->lchild;
    return p->data;
}
int Treap_findmax(Treap_Node* p)//find the maximum value in subtree p
{
    while(p->rchild)
        p=p->rchild;
    return p->data;
}
int main(void)
{
    srand((unsigned)time(NULL));
    Treap_Node* _root=new Treap_Node(0);
    _root->fix=-1;
    for(int i=-5;i<10;i++)
        Treap_insert(_root,i);
    Treap_insert(_root,3);
    Treap_delete(_root,0);
    Inorder_traverse(_root);

    return 0;
}
