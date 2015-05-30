#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int i;
    float a=0,b=0,n;
    for(i=1;i<=10;i++)
    {
        cin>>n;
        if(n>0)a+=n;
        else b+=n;
    }
    printf("%.2f,%.2f,%.2f\n",a,b,a+b);
    scanf("%f",&n);
    return 0;
} 
    
