#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<stack>
using namespace std;
string s1,s2;
void dfs(int l1,int r1,int l2,int r2){
    if(l2>r2)return;
    printf("%c",s2[r2]);
    for(int i=l1;i<=r1;i++)if(s1[i]==s2[r2]){
        dfs(l1,i-1,l2,l2+i-l1-1);
        dfs(i+1,r1,l2+i-l1,r2-1);
        break;
    }
}
int main(){
    int i,j,m,n;
    while(cin>>s1>>s2){
        dfs(0,s1.size()-1,0,s1.size()-1);
    }
    return 0;
} 
