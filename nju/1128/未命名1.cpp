#include<cstdio>
#include<iostream> 
#include<cstring>
#include<string>
#include<map>
using namespace std;
map<char,int> a[10000];
string s;
void swap(int i,int j){
    char t=s[i];
    s[i]=s[j];
    s[j]=t;
}
void dfs(int x){
    if(x==s.length()-1){
        cout<<s<<endl;
        return;
    }
    for(int i=x;i<s.length();i++)if(a[x][s[i]]!=1){
        a[x][s[i]]=1;
        string s1=s;
        swap(x,i);
        dfs(x+1);
        s=s1;
    }
    a[x].clear();
}
int main(){
    int i,j,m,n;
    while (cin>>s)dfs(0);
    system("pause");
    return 0;
}
