#include<iostream>
#include<stdio.h>
using namespace std;
#define maxsize 100
typedef struct BTnode
{
    char data;
    struct BTnode *lchildren;
    struct BTnode *rchildren;
}BTnode;
typedef struct
{
    BTnode *root;
}BTree;
typedef struct 
{
    char data[maxsize];
    int length;
}sqlist;

typedef struct Lnode
{
    char data;
    struct Lnode *next;
}Lnode;
void Preorder(BTnode *p);
void Inorder(BTnode *p);
void Postorder(BTnode *p);
void Visit(BTnode *p);

int main()
{

}
void Preorder(BTnode *p)//先序遍历
{
    if(p!=NULL)
    {
        Visit(p);
        Preorder(p->lchildren);
        Preorder(p->rchildren);
    }
}
void Inorder(BTnode *p)//中序遍历
{
    if(p!=NULL)
    {
        Inorder(p->lchildren);
        Visit(p);
        Inorder(p->rchildren);
    }
}
void Postorder(BTnode *p)//后序遍历
{
    Postorder(p->lchildren);
    Postorder(p->rchildren);
    Visit(p);
}
void Visit(BTnode *p)
{
    cout<<p->data;
}