#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    string s;
    bool a[30];
    memset(a,false,sizeof(a));
    cin>>s;
    for(int i=0;i<s.size();i++)
    if(!a[s[i]-'a'])
    {
        cout<<s[i];
        a[s[i]-'a']=1;
    } 
    cout<<endl;
    system("pause");
    return 0;
}
