#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#define P 998244353
using namespace std;
string s[20005];
bool b[10][20];
int main(){
    int i,j,m,n,I,N,c,l,r;
    cin>>N;
    for(I=1;I<=N;I++){
        cin>>n>>c>>l>>r;
        r-=c;
        l-=c;
        ans=0;
        if(r==n)ans--;
        
