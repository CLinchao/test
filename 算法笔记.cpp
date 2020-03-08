#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
#define N 100
void PAT_1001()
{
    int n,step=0;
    scanf("%d",&n);
    while(n!=1)
    {
        if(n%2==0)
        {
            n/=2;
            step+=1;
        }
        else if(n%2==1)
        {
            n=3*n+1;
            n/=2;
            step+=1;
        }
    }
    printf("%d",step);
}

void PAT_1002()
{
    int i,j,len,sum,n;
    sum=0,j=0;
    int num[N];
    int a[500];
    char A[500];
    string s;
    cin>>s;
    len=s.length();
    for(i=0;i<len;i++)
    {
        num[i]=s[i]-'0';
        sum += num[i];
    }

    while(sum!=0)
    {
        n=sum%10;
        a[j++]=n;
        sum/=10;
    }
}


int main()
{

}