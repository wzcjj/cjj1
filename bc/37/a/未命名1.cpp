#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
string s;
int z;
bool ishuiwen(string s1){
    for(int i=0;i<s1.size();i++)if(s1[i]!=s1[s1.size()-i-1])return false;
    return true;
}
void dfs(int x){
    int i=x;
    while(i<s.size()&&s[i]!='?')i++;
    if(i==s.size()){
        if(ishuiwen(s))return;
        else{
            z=1;
            cout<<s<<endl;
            return;
        }
    }
    else{
        for(char j='a';j<='z';j++){
            s[i]=j;
            dfs(i);
            if(z==1)return;
        }
        s[i]='?';
    }
}
int main(){
    int i,j,m,n;
    int N;
    while(cin>>n){
        cin>>s;
        z=0;
        dfs(0);
        if(z==0)cout<<"QwQ"<<endl;
    }
    return 0;
}
