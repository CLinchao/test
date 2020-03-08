#include<iostream>
#include<stdio.h>
using namespace std;
enum color_set1{red,black,yellow,blue}; //枚举定义
//enum color_set2{black,red,blue,red};
void Example_of_enum() //枚举相关操作
{
    enum color_set1 color1;//枚举变量声明
    color1 = red; //整数值不能直接赋值给枚举变量
    int i=color1;
    cout<<color1<<"\t"<<i<<endl;
}

int main()
{
    Example_of_enum();
} 