#include<cstdio>
#include<iostream>
#include<stdlib.h>

#define Maxsize 100
using namespace std;
enum color_set {red,blue,yellow,black};
typedef struct 
{
    char str[Maxsize+1];
    int length;
}Str_static;

typedef struct
{
    char *ch;
    int length;
}Str_dynamic;


int Str_assign(Str_dynamic &str,char *ch)
{
    if(str.ch) free(str.ch);
    int len=0;
    char *c=ch;
    while (c!=NULL)
    {
        len+=1;
        ++c;
    }
    if(len==0)
    {
        str.ch=NULL;
        str.length=0;
        return 1;
    }
    else
    {
        str.ch=(char *)malloc(sizeof(char)*(len+1));
        if(str.ch==NULL) return 0;
        else
        {
            c=ch;
            for(int i=0;i<=len;++i,++c)
            {
                str.ch[i]=*c;
            }
            str.length=len;
            return 1;
        }
    }    
}

int Str_length(Str_dynamic s) //串长
{
    return s.length;
}

int Str_Compare(Str_dynamic s1,Str_dynamic s2)
{
    for(int i=0;i<s1.length&&i<s2.length;i++)
    {
        if(s1.ch[i]!=s2.ch[i]) return s1.ch[i]-s1.ch[i];
    }
    return s1.length-s2.length;
}

int Str_concat(Str_dynamic &s,Str_dynamic s1,Str_dynamic s2) //连接串s1 和s2
{
    if(s.ch!=NULL) free(s.ch);
    char *p;
    s.ch=(char *)malloc(sizeof(char)*(s1.length+s2.length+1));
    if(s.ch!=NULL)
    {
        p=s1.ch;
        for(int i=0;i<s1.length;++i)
        {
            s.ch[i]=*p;
            ++p;
        }
        p=s2.ch;
        for(int i=s1.length;i<=s1.length+s2.length;i++)
        {
            s.ch[i]=*p;
            ++p;
        }
        s.length=s1.length+s2.length;
        return 1;
    }
    else return 0;
}

int Str_Substr(Str_dynamic &Sub,Str_dynamic S,int n,int len) //从n 取len长度的字串
{
    if(len<0||len>S.length||n<0||n+len>S.length) return 0;
    if(Sub.ch) free(Sub.ch);
    Sub.ch=NULL;
    if(len==0)
    {
        Sub.ch=NULL;
        Sub.length=0;
        return 1;
    }
    else
    {
        Sub.ch=(char *)malloc(sizeof(char)*(len+1));
        for(int i=0;i<len;i++)
        {
            Sub.ch[i]=S.ch[i+n];
        }
        Sub.ch[len]='\0';
        Sub.length=len;
        return 1;
    }
}
int Str_clearn(Str_dynamic &S) //1表示清楚成功
{
    if(S.ch)
    {
        free(S.ch);
        S.ch=NULL;
    }
    S.length=0;
    return 1;
}
int Str_Index(Str_dynamic s,Str_dynamic sub) //简单模式匹配算法
{
    int i=0,j=0,k=i;
    while(i<s.length&&j<sub.length)
    {
        if(s.ch[i]==sub.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            j=0;
            i=++k;
        }
    }
    if(j>=sub.length) return k;
    else return 0;
}
int main()
{
    color_set color1;
    color1=red;
    cout<<color1<<endl;
    
    // Str_dynamic S,s1,s2;
    // S.ch="abc";
    // S.length=3;
    // s1.ch="bc";
    // s1.length=2;
    // cout<<Str_Index(S,s1)<<endl;
    // Str_Substr(s1,S,0,3);
    // cout<<s1.length<<endl;
    // cout<<Str_Substr(s1,S,0,4)<<endl;
    // for(int i=0;i<s1.length;i++)
    // {
    //     cout<<s1.ch[i]<<endl;
    // }
    // S.length=3;
    // s1.ch="def";
    // s1.length=3;
    // s2.ch="rt";
    // s2.length=2;
    // Str_concat(S,s1,s2);
    // for(int i=0;i<S.length;i++)
    // {
    //     cout<<S.ch[i]<<endl;
    // }

}