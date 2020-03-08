#include<iostream>
#include<string.h>
using namespace std;
int fun(int a[],int n){
    int low=0,high=n-1,mid=(low+high)/2;
    while(low<high){
        if(a[mid]>a[0]){
            low = mid + 1;
        }
        else if(a[mid]<a[0]){
            high = mid - 1;
        }
        mid+=a[mid]>a[0]?1:0;
        mid =(low+high)/2;
    }
    mid +=a[mid]>a[0]?1:0;
    return a[mid];
}
int fun1(int a[],int n){
    int low=0,high=n-1,mid=(low+high)/2;
    while(low<high){
        if(a[mid]<a[mid-1]&&a[mid]<a[mid+1])
            return a[mid];
        else if(a[mid]>a[low]&&a[mid]>a[high])
        {
            mid=low;
        }
        else if (a[mid]<a[low]&&a[mid]<a[high])
        {
            mid=high;
        } 
    }
}
class STRING
{
    public:
    int *p;
    char *str;
    int length;
    //public:
    STRING(char *s,int *p);
    STRING(STRING &STR);
    ~STRING(){cout<<"destruction"<<endl;delete []str;}
    char operator()(int pos);
    void ss(){cout<<str<<endl;}
};
STRING::STRING(char *s,int *q){
    if(s){
        str = new char(strlen(s)+1);
        strcpy(str,s);
    }
    cout<<"construction"<<endl;
    *p=*q;
}
STRING::STRING(STRING &s)
{
    if(s.str){
        str = new char(strlen(s.str)+1);
        strcpy(str,s.str);
    }
    cout<<"copy construction"<<endl;
}
char STRING::operator()(int pos){
    return str[pos];
}


int main()
{
    char a[]="dsdsd";
    int *r= new int(2);
    STRING A(a,r);
    cout<<A.*p<<A.str<<endl;
    //STRING B(A);
    //cout<<B(2)<<endl;
    //cout<<B.str<<endl;
}