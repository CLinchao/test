#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;
class Sample
{
private:
    int x,y;
    static int i;
public:
    Sample(int a=1,int b=1){
        x=a;y=b;
        disp();
    }
    Sample(Sample &s)
    {
        x=s.x;
        y=s.y;
        cout<<"calling copy construct"<<endl;
    }
    Sample& operator= (Sample &s)
    {
        x=s.x;
        y=s.y;
        cout<<"in operator="<<endl;
        return *this;
    }
    ~Sample(){
        if(x==y) cout<<"x==y"<<endl;
        else
        {
            cout<<"x!=y"<<endl;
        }
    }
    void disp()
    {
        cout<<"x="<<x<<",y="<<y<<endl;
    }
    friend void ms(Sample s);
};
class Sample2{
    int i;
    static int k;
    public:
    Sample2(){i=0;k++;}
    Sample2(int a){i=a;k+=a;}
    Sample2(Sample2 &a);
    void disp(){cout<<i<<','<<k<<endl;}
    //static void disp1(){cout<<k<<endl;}
};
Sample2::Sample2(Sample2 &a)
{
    i=a.i;
    k=a.k+++10;
}
int Sample2::k;
void ms(Sample s)
{
    s.x=s.y;
}
class one
{
    float x;
public:
    ~one(){}
    one(float a=0){x=a;}
    one operator++(){
        one t;
        x++;
        t=*this;
        return t;
    }
    void process(){show();}
    virtual void show(){cout<<"x="<<x<<"\t";}
};
class two:public one
{
    float y;
public:
    ~two(){}
    two(float a=0){y=a;}
    two operator++(){
        two t;
        ++y;
        t=*this;
        return t;
    }
    virtual void show(){cout<<"y="<<y<<"\t";}
};
class three:public two
{
   float z;
public:
    ~three(){cout<<"calling destrucotr"<<endl;}
    three(float a=0){z=a;}
    three operator++(){
        three t;
        ++z;
        t=*this;
        return t;
    }
    virtual void show(){cout<<"z="<<z<<endl;}
};

int main(){
    int a=1,b=4,c=5,x;
    one *p,a(2);
    two b(3);
    three c(4);
    short A=-32768;
    ++a;p=&a;p->show();
    ++b;p=&b;p->show();
    ++c;p=&c;p->show();
    c.process();
    cout<<setw(30)<<"c++ Programming Languague"<<endl;
    cout<<setw(6)<<"233"<<"\t"<<"233"<<endl;
    cout<<A<<endl;
    
    return 0;
}