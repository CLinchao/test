#include<stdio.h>
#include<iostream>
using namespace std;
#define maxsize 100
typedef struct LNode //链表节点定义
{
    int data;
    struct LNode *next;
}LNode;
typedef struct TNode //树节点定义
{
    char data;
    struct TNode *lchildren;
    struct TNode *rchildren;
}TNode;
typedef struct
{
    int data[maxsize];
    int length;
}Sqlist;
int findElem(Sqlist A,int p,int e);

void merge(LNode *A,LNode *B,LNode *C);

void Preorder(TNode *p);

void Visit(TNode *p)
{
    cout<<p->data;
}

int main()
{
    int a;
    printf("asdasd");
    cin>>a;
}
int findElem(Sqlist A,int p)
{
    for(int i=0;i<A.length;i++)
    {
        if(A.data[i]==p) return i;
        else return -1;
    }
}
void merge(LNode *A,LNode *B,LNode *&C)//归并不减链表A,B
{
    LNode *p = A->next;
    LNode *q = B->next;
    LNode *r;
    C=A;
    C->next=NULL;
    free(B);
    r=C;
    while(p->next!=NULL&&q->next!=NULL)
    {
        if(p->data<=q->data)
        {
            r->next=p;
            p=p->next;
            r=r->next;
        }
        else
        {
            r->next=q;
            q=q->next;
            r=r->next;
        }
    }
    if(p->next!=NULL) r->next=p;
    if(q->next!=NULL) r->next=q;
}
void CreatelistR(LNode *&C,int a[],int n)//尾插法建立链表
{
    LNode *s,*r;
    int i;
    C=(LNode*)malloc(sizeof(LNode));
    C->next=NULL;
    r=C;
    for(i=0;i<n;i++)
    {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=a[i];
        r->next=s;
        r=r->next;
    }
    r->next=NULL;
}
void CreatelistF(LNode *&C,int a[],int n)
{
    LNode *s;
    
}
void Preorder(TNode *p)//先序遍历
{
    if(p!=NULL)
    {
        Visit(p);
        Preorder(p->lchildren);
        Preorder(p->rchildren);
    }
}
void inorder(TNode *p)
{
    
}