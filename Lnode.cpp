#include<stdio.h>
#include<iostream>
using namespace std;
#define maxsize 100
typedef struct Lnode
{
    char data;
    struct Lnode *next;
}Lnode;

typedef struct 
{
    char data;
    int length;
}sqlist;


void Sort(int a[],int length)
{
    int head,rear,p;
    head=0,p=0;
    
}