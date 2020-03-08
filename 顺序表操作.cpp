#include<stdio.h>
#include<iostream>
#define maxsize 50
using namespace std;


typedef struct
{
    int data[maxsize];
    int length;
}sqlist; //顺序表类型的定义

typedef struct Lnode
{
    int data;
    struct Lnode *next;
}Lnode; //单链表节点类型的定义

int find_elem(sqlist a,int x) //找到第一个比x大的元素的位置
{
    int i;
    for(i=0;i<a.length;++i)
    {
        if (x<a.data[i]) return i;
    }
    return i;
}
void insert_elem(sqlist &a,int x)//插入一个元素
{
    int i;
    for(i=a.length;i>find_elem(a,x);--i)
    {
        a.data[i]=a.data[i-1];
    }
    a.data[i]=x;
    a.length+=1;
}
void delete_elem(sqlist &a,int p,int &x)//删除下表为p的元素
{
    int i;
    x=a.data[p];
    for(i=p;i<a.length;++i)
    {
        a.data[i]=a.data[i+1];
    }
    a.length-=1;
}
void sqlist_init(sqlist &a)//初始化顺序表
{
    a.length=0;
}
//构造一个Lnode型的节点，定义A指针指向这个节点
//  Lnode *A = (Lnode*)malloc(sizeof(Lnode));

int main()
{
    sqlist A;
    int x;
    A.data[0]=0;
    A.data[1]=1;
    A.data[2]=2;
    A.data[3]=3;
    A.data[4]=5;
    A.length=5;
    // insert_elem(A,3);
    delete_elem(A,2,x);
    for(int i=0;i<4;i++)
    {
    cout<<A.data[i]<<endl;
    }
    cout <<x;
    // cout<<A.length;
}
