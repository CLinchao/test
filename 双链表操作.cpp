#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>
using namespace std;
#define N 4
#define Maxsize 100
typedef struct DLnode
{
    int data;
    struct DLnode *prior;
    struct DLnode *next;
}DLnode;

void CreateDlistR(DLnode *&L,int a[],int n)//尾插法创建双链表
{
    DLnode *p,*q;
    L=(DLnode *)malloc(sizeof(DLnode));
    L->next = NULL;
    L->prior= NULL;
    q=L;
    for(int i=0;i<n;i++)
    {
        p=(DLnode *)malloc(sizeof(DLnode));
        p->data=a[i];
        q->next =p;
        p->prior =q;
        q=q->next;
    }
    q->next= NULL;
}
void CreateDlistF(DLnode *&L,int a[],int n)//头插法建立双链表
{
    // int i=0;
    DLnode *p;
    L=(DLnode *)malloc(sizeof(DLnode));
    L->next=NULL;
    L->prior=NULL;
    for(int i=0;i<n;i++)
    {
        p=(DLnode *)malloc(sizeof(DLnode));
        p->data =a[i];
        p->next=L->next;
        p->prior=L;
        if(L->next!=NULL) 
        {
        L->next->prior=p;}
        L->next=p;
    }

}

DLnode* findNode(DLnode *L,int x)//查找节点
{
    DLnode *p=L->next;
    while(p!=NULL)
    {
        if(p->data==x){
            break;
        }
        p=p->next;
    }
    return p;

}
int main()
{

    int a[4]={1,2,3,4};
    DLnode *l;
    // CreateDlistR(l,a,4);
    CreateDlistF(l,a,4);
    // DLnode *p;
    // p=findNode(l,3);
    cout<<l->next->data<<endl;
}
