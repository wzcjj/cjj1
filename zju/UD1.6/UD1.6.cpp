#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    int i,j,m,n;
    s="RDSXCVIWTDGNXHUJCLXAAATPGCBDGTPQDJIXIAPITG";
    n=s.length();
    for(i=1;i<=26;i++)
    {
        for(j=0;j<n;j++)s[j]=(s[j]-'A'+1)%26+'A';
        cout<<s<<endl;
    }
    system("pause");
    return 0;
}
