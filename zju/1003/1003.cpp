#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int i,j,m,n;
    int a,b,a1,b1;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if(a<b){int t=a;a=b;b=t;}
        a1=a;
        b1=b;
        for(i=100;i>=2;i--)
        {
            if(b1%i==0)b1=b1/i;
            else if(a1%i==0)a1=a1/i;
        }
        if(a1>1&&b1==1)cout<<b<<endl;
        else cout<<a<<endl;
    }
    return 0;
}
