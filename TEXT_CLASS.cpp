#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

class example
{
	int a,b,c;
public:
	static int sum;
	example(int x,int y,int z){a=x;b=y;c=z;sum+=a+b+c;}
	friend void PrintSum(example t);
};
class Tree
{
private:
	int h;
public:
	Tree(int);
	Tree(Tree &t){h=t.h;cout<<"copy construct h="<<h<<endl;}
	void Disp(){cout<<"The height is"<<h<<endl;}
	~Tree();
};

Tree::Tree(int height=0)
{
	h=height;
	cout<<"Construct h="<<h<<endl;
}
Tree::~Tree()
{

}


void PrintSum(example t){cout<<t.sum<<endl;}
int example::sum=0;
void exa(char *p,int *q,int t1,int t2)
{
	int i;
	cout<<p<<endl;
	for(i=0;i<t2;i++)
	{
		cout<<char(*(p+t1+i));
		*q=p[i]-'a';
		q++;
	}
	cout<<endl;
	q=q-t2;i=0;
	while(i<t2)
	{
		cout<<char(*p+t1+i);
		p[i]=char('A'+q[i]);
		i++;
	}
	cout<<endl;
}
class CShape{
	public:
	void Display(){
		cout<<"CShape"<<endl;
	}
};
class DShape:public CShape{
	public:
	void Display(){
		cout<<"DShape"<<endl;
	}
};
class EShape:public CShape{
	public:
	void Display(){
		cout<<"EShape"<<endl;
	}
};
class STRING
{
private:
	char *str;
	int length;
public:
	STRING(char *s);
	STRING(STRING &ss);
	~STRING();
	char& operator()(int pos);
	void s_printf(){cout<<str<<endl;}
};
STRING::STRING(STRING &ss){
	length=ss.length;
	str=new char[ss.length+1];
	strcpy(str,ss.str);
}
char& STRING::operator()(int pos){
	return str[pos];
}
STRING::STRING(char *s)
{
	length=strlen(s);
	str=new char[length+1];
	strcpy(str,s);
}

STRING::~STRING()
{
	delete []str;
}
vector<int> text;
vector<int> ia(10);//
const int size=7
int main()
{	//vector STL 方式
	int ia[size]={1,2,3,4,5,6,7};
	int b[size]={1,1,1,1,1,1,1}
	for(int i=0;i<size;++i)
	{
		ia.push_back()
	}
	int a[5]={1,2,3,4,5};
	for(int i=0;i<5;i++)
	{
		text.push_back(a[i]);
	}
	for(vector<int>::iterator it=text.begin();it!=text.end();++it){//vector iterator
		cout<<*it<<",";
	}
	cout<<endl;
	for(int i=0;i<text.size();i++)
	{
		cout<<text[i]<<',';
	}
	cout<<endl;
}
