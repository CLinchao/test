#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct Lnode
{
    int data;
    struct Lnode *next;
}Lnode;

void createlistR(Lnode *&C,int a[],int n) //尾插法建立单链表 a[]顺序进入单链表
{
    Lnode *s,*r;
    C=(Lnode*)malloc (sizeof(Lnode));
    C->next=NULL;
    r=C;
    for(int i=0;i<n;i++)
    {
        s=(Lnode *)malloc(sizeof(Lnode));
        s->data=a[i];
        r->next=s;
        r=r->next;
    }
    r->next=NULL;
}
void createlistF(Lnode *&C,int a[],int n)//头插法建立单链表 会使a[]变成逆序
{
    Lnode *s;
    C=(Lnode *)malloc(sizeof(Lnode));
    C->next=NULL;
    for(int i=0;i<n;i++)
    {
        s=(Lnode *)malloc(sizeof(Lnode));
        s->data=a[i];
        s->next=C->next;
        C->next=s;
    }
}
void merge(Lnode *A,Lnode *B,Lnode *&C)
{
    Lnode *p,*q,*s;
    p=A->next;
    q=B->next;
    C=(Lnode *)malloc(sizeof(Lnode));
    s=C;
    C->next=NULL;
    while(p->next!=NULL and q->next !=NULL)
    {
        if(p->data<q->data)
        {
            s->next=p;
            s=s->next;
            p=p->next;
        }
        else
        {
            s->next=q;
            s=s->next;
            q=q->next;
        }   
    }
    if(p->next !=NULL) s->next=p;
    if(q->next !=NULL) s->next=q;   
}
int main()
{
    Lnode *C,*B,*A;
    int a[5],b[5];
    a[0]=0,a[1]=2,a[2]=4,a[3]=6,a[4]=8;
    b[0]=1,b[1]=3,b[2]=5,b[3]=7,b[4]=9;
    createlistR(C,a,5);
    createlistR(B,b,5);
    merge(C,B,A);
    for(int i=0;i<10;i++)
    {
        A=A->next;
        cout<<A->data<<endl;
    }
}
