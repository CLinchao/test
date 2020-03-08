#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<math.h>
#define Maxsize 100
using namespace std;
typedef struct Lnode
{
    int data;
    Lnode *next;
}Lnode;

typedef struct 
{
    int data[Maxsize];
    int front,rear;
}cycqueue;

typedef struct 
{
    int elem[Maxsize];
    int top[2]; //top[0]--top of stack1  top[1]--top of stack2
}Sqstack;

typedef struct 
{
    int data[Maxsize];
    int front,rear;
    int tag;
}Queue;

int Push(Sqstack &S,int N,int x) // N为插入栈名 x为数据 1表示入栈成功 -1表示入栈失败 0表示栈满
{
    if(S.top[0]+1<S.top[1])
    {
        if(N==1)
        {
            S.elem[++S.top[0]]=x;
            return 1;
        }
        else if (N==2)
        {
            S.elem[--S.top[1]]=x;
            return 1;
        }
        else return -1;
    }
    else return 0;
}

int Pop(Sqstack &S,int N,int &x) //N为栈名字 x为数据 -1表示输入栈有误 1表示出栈成功 0表示栈空
{
    if(N==1)
    {
        if(S.top[0]!=-1)
        {
            x=S.elem[S.top[0]--];
            return 1;
        }
        else return 0;
    }
    else if(N==2)
    {
        if(S.top[1]!=Maxsize)
        {
            x=S.elem[S.top[1]++];
            return 1;
        }
        else return 0;
    }
    else return -1;
}

void enQueue(Lnode *&rear,int x) // 基础题6 带头结点的循环链表表示队列 rear指向队尾节点
{
    Lnode *s =(Lnode *)malloc(sizeof(Lnode));
    s->data=x;
    s->next=rear->next;
    rear->next=s;
    rear=s;
}

int deQueue(Lnode *&rear,int &x) //0表示队空 1表示出队成功
{
    Lnode *s;
    if(rear->next==rear) return 0;
    else
    {
        s=rear->next->next;
        rear->next->next=s->next;
        x=s->data;
        if(s==rear) rear=rear->next;
        free(s);
        return 1;
    }
    
}

int decycqueue(cycqueue &S,int &x)//基础题7 0表示插入失败 1表示插入成功
{
    if(S.front==S.rear) return 0;
    else
    {
        x=S.data[S.rear];
        S.rear=(S.rear-1+Maxsize)%Maxsize;
        return 1;
    }
}

int encycqueue(cycqueue &S,int x) //基础题7 0表示队满 插入失败 1表示插入成功
{
    if(S.rear==(S.front-1+Maxsize)%Maxsize) return 0;
    else
    {
        S.data[S.front]=x;
        S.front=(S.front-1+Maxsize)%Maxsize;
        return 1;
    }
    
}

void initQueue(Queue &Q) //基础题8 初始化队列
{
    Q.front=Q.rear=0;
    Q.tag=0;
}
int is_Empty_Queue(Queue &Q) //队空 1 队非空 0
{
    if(Q.front==Q.rear&&Q.tag==0) return 1;
    else return 0;
}

int is_Full_Queue(Queue &Q) //队满 1 队非满 0
{
    if(Q.front==Q.rear&&Q.tag==1) return 1;
    else return 0;
}

int enQueue(Queue &Q,int x)// -1 队满 无法入队 1入队成功
{
    if(is_Full_Queue(Q)) return -1;
    else
    {
        Q.rear=(Q.rear+1+Maxsize)%Maxsize;
        Q.data[Q.rear]=x;
        Q.tag=1; 
        return 1;
    }
}

int deQueue(Queue &Q,int &x) //基础题8 -1 队空 无法出队 1表示出队成功
{
    if(is_Empty_Queue(Q)) return -1;
    else
    {
        Q.front=(Q.front+1+Maxsize)%Maxsize;
        x=Q.data[Q.front];
        Q.tag=0;
        return 1;
    }
}

void ten_TO_two(Sqstack &S,int N) //基础题9 十进制转 2进制
{
    int Stack[Maxsize];
    int top=-1;
    int i,result=0;
    while (N!=0)
    {
        i=N%2;
        N/=2;
        Stack[++top]=i;
    }
    while (top!=-1)
    {
        i=Stack[top--];
        result=result*10+i;
    }
    cout<<result<<endl;
}

float recursion_of_sqrt(float A,float p,float e) //思考题1 递归法求解二次方根
{
    if(fabs(p*p-e)<e) return p;
    else
    {
        recursion_of_sqrt(A,(p+A/p)/2,e);
    }
}
float No_recurion_of_sqrt(float A,float p,float e) //思考题1 非递归法求解二次方根
{
    while(fabs(p*p-e)>=e)
    {
        p=(p+A/p)/2;
    }
    return p;
}

void Print_ALL_sort(char s[],int k,int n) //思考题2 递归算法 求你个不同字符的所有全排列
{
    int i,j;
    char temp;
    if(k==0)
    {
        for(i=0;i<=n-1;++i)
        {
            cout<<s[i];
        }
        cout<<endl;
    }
    else
    {
        for(j=0;j<=k;++j)
        {
            temp=s[k];
            s[k]=s[j];
            s[j]=temp;
            Print_ALL_sort(s,k-1,n);
            temp=s[j];
            s[j]=s[k];
            s[k]=temp;
        }
    }
}


int main()
{


    char s[]="abc";
    Print_ALL_sort(s,2,3);
    // Sqstack S;
    // ten_TO_two(S,12);

    // int x,y;
    // Queue Q;
    // initQueue(Q);
    // enQueue(Q,1);
    // enQueue(Q,2);
    // enQueue(Q,3);
    // cout<<Q.data[Q.rear]<<endl;
    // deQueue(Q,x);
    // deQueue(Q,y);
    // cout<<x<< y<<endl;
    // int x;
    // Sqstack L;
    // L.elem[0]=0;
    // L.elem[1]=1;
    // L.elem[Maxsize-1]=1;
    // L.top[0]=1;
    // L.top[1]=Maxsize-1;
    // Pop(L,1,x);
    // Push(L,2,3);
    // Pop(L,2,x);
    // cout<<x<<endl;
}