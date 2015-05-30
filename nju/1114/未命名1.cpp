#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a,b,c,d,i,j,m,n,ans;
    string s1,s2;
    cin>>a>>b>>s1>>c>>d>>s2;
    if(s1=="PM"&&a!=12)a+=12;
    if(s2=="PM"&&c!=12)c+=12;
    m=c-a;
    n=d-b;
    if(m<0||m==0&&n<0)m+=24;
    ans=m*60+n;
    cout<<ans<<endl;
    system("pause");
    return 0;
} 
