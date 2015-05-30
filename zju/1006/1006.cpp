#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
char calc(int t)
{
    if (t==0)return '_';
    else if(t==27)return '.';
    else return 'a'+t-1;
}
int main()
{
    int i,j,m,n;
    string s,t;
    cin>>n;
    while(n)
    {
        s="";
        cin>>s;
        m=s.length();
        t="";
        for(i=1;i<=m;i++)t+=" ";
        for(i=0;i<=m-1;i++)
        {
            int a;
            if(s[i]=='_')a=0;
            else if(s[i]=='.')a=27;
            else a=s[i]-'a'+1;
            t[n*i%m]=calc((a+i)%28);
        }
        cout<<t<<endl;
        cin>>n;
    }
    return 0;
}
        
