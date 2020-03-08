#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>
#define Maxsize 50
#define N 6
using namespace std;
typedef struct Sqlist
{
    int data[Maxsize];
    int length;
}Sqlist;
typedef struct Char_Sqlist
{
    char data[Maxsize];
    int length;
}Char_Sqlist;
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

void reverse(Sqlist &A) //基础题3 顺序表中所有元素逆置
{
    int temp;
    for(int i=0;i<A.length/2;i++)
    {
        temp=A.data[i];
        A.data[i]=A.data[A.length-1-i];
        A.data[A.length-1-i]=temp;
    }
}

void delete_i_to_j(Sqlist &A,int i,int j) //基础题四 删除下表i_j的所有元素
{
    int temp=j-i+1;
    for(int n=i;n<(A.length-temp);n++)
    {
        A.data[n]=A.data[n+temp];
    }
    A.length-=temp;
}
void Change_position(Sqlist &A) //基础题5 将顺序表中所有小于表头元素的提前 大于的后置
{
    int i,j,temp;
    temp=A.data[i];
    i=0;j=A.length-1;
    while(i<j)
    {
        while(i<j&&A.data[j]>temp) --j;
        if(i<j)
        {
            A.data[i]=A.data[j];
            ++i;
        }
        while(i<j&&A.data[i]<temp) ++i;
        if(i<j)
        {
            A.data[j]=A.data[i];
            --j;
        } 
        A.data[i]=temp;
    }
}

void remove_repeat(Lnode *C) //基础题6 删除递增非减链表中值域重复的节点
{
    Lnode *s=C->next,*q;
    while (s->next!=NULL)
    {
        if(s->data==s->next->data)
        {
            q=s->next;
            s->next=q->next;
            free(q);
        }
        else s=s->next;
    }
}

void remove_minimum(Lnode *C) //基础题7 删除单链表L(带头结点)的最小值
{
    Lnode *pre=C,*p=pre->next,*min=p,*minpre=pre;
    while(p!=NULL)
    {
        if(p->data<min->data)
        {
            min=p;
            minpre=pre;
        }
        p=p->next;
    }
    minpre->next=min->next;
    free(min);
}

void reverse_List(Lnode *C) //基础题8 带头结点单链表的逆置，不能新生产节点
{
    Lnode *p=C->next,*q;
    C->next =NULL;
    while(p!=NULL)
    {
        q=p->next; //头插法
        p->next=C->next;
        C->next=p;
        p=q;
    }
}


void halved_List(Lnode *A,Lnode *&B) //基础题9 将带头结点的A单链表 分解成为偶数链表和 奇数链表
{
    Lnode *q,*p,*r;
    B=(Lnode *)malloc(sizeof(Lnode));
    B->next=NULL;
    r=B;
    p=A;
    while(p->next!=NULL)
    {
        if(p->next->data%2==0)
        {
            q=p->next;
            p->next=q->next;
            q->next=NULL;
            r->next=q;
            r=q;
        }
        else p=p->next;
    }    
}

void find_min(int A[],int &i) //思考题1 N个个位正整数 不用其余变量查找A[]中最小值
{
    i=A[0];
    while(i/10<=N-1)
    {
        if(i%10>A[i/10])
        {
            i=i-i%10;
            i=i+A[i/10];
        }
        i+=10;
    }
    i=i%10;
}

void reverse_print_List(Lnode *C) //思考题2 逆序打印单链表节点--- 递归实现
{
    if(C!=NULL)
    {
        reverse_print_List(C->next);
        cout<<C->data<<endl;
    }
}

void find_maximum(int A[],int n,int &max,int &min) //思考题3 不多于3n/2的平均次数，在n个整数顺序表A找最大最小值
{
    max=min=A[0];
    for(int i=1;i<=n;i++)
    {
        if(A[i]>max) max=A[i];
        else if(A[i]<min) min=A[i]; 
    }
}

int CompareA_B(Char_Sqlist &A,Char_Sqlist &B,int m,int n) //思考题4
{
    for(int i=0;(i<m&&i<n);i++)
    {

    }
}

int find_Node(Lnode *C,int k) // 综合应用题1 查找倒数第K个位置的结点  可以优化
{
    Lnode *s=C->next,*r=C->next;
    if(s==NULL) return 0;
    int length=1;
    for(int i=0;i<k-1;i++)
    {
        s=s->next;
        length +=1;
    }
    while(s->next!=NULL)
    {
        s=s->next;
        r=r->next;
        length +=1;
    }
    if(k>length) return 0;
    else
    {
        cout<<r->data<<endl;
        return 1;
    }
}

void reverse_Array(int A[],int head,int end) //翻转指定其实位置和终止位置(下标)的数组
{
    int temp;
    for(int i=head,j=end;i<j;i++,j--)
    {
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
    }
}

void Move_Array(int R[],int p,int n) //综合应用题2  数组R保存的序列 左移P个位置
{
    reverse_Array(R,0,p-1);
    reverse_Array(R,p,n-1);
    reverse_Array(R,0,n-1);
}
int find_main_elem(int A[],int n) //综合应用题3 找到数组A中的主元素
{
    int number=1,i,c;
    c=A[0];
    for(i=1;i<n;i++)
    {
        if(A[i]==c)
        {
            i++;
            number+=1;
        }
        else
        {
            if(number<=0)
            {
                c=A[i];
                number=1;
            }
            else
            {
                number-=1;
            }
        }
    }
    if(number>0)
    {
        for(int i=number=0;i<n;i++)
        {
            if(A[i]==c)
            {
                number +=1;
            }
        }
    }
    if(number>n/2)cout<<c<<endl;
    else cout<<-1<<endl;
    
}
int main()
{
    int max,min;
    int B[6];
    B[0]=1;
    B[1]=1;
    B[2]=1;
    B[3]=1;
    B[4]=5;
    B[5]=6;
    find_main_elem(B,6);
    // Move_Array(B,2,6);
    // for(int i=0;i<6;i++)
    // {
    //     cout<<B[i]<<endl;
    // }
    // find_maximum(B,6,max,min);
    // cout<<max<<min<<endl;
    // find_min(B,t);
    // cout<<t<<endl;
    // B.length=6;
    // reverse(B);
    // delete_i_to_j(B,2,3);
    // Change_position(B);
    // for(int i=0;i<B.length;i++){
    // cout<<B.data[i]<<endl;}
    // Lnode *L,*P;
    // createlistR(L,B,6);
    // find_Node(L,6);
    // halved_List(L,P);
    // remove_repeat(L);
    // remove_minimum(L);
    // while(L->next!=NULL)
    // {
    //     cout<<L->next->data<<endl;
    //     L=L->next;
    // }

    // cout<<"----------"<<endl;
    // while(P->next!=NULL)
    // {
    //     cout<<P->next->data<<endl;
    //     P=P->next;
    // }
}
