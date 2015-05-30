#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[30];
struct node{
    long long sum;
    int i;
}b[100005];
int main(){
    int i,j,m,n;
    string s;
    for(i=1;i<=26;i++)cin>>a[i];
    cin>>s;
    b[0].sum=0;
    b[0].i=0;
    for(i=0;i<s.length();i++){
        b[i+1].i=i+1;
        b[i+1].sum=b[i].sum+a[s[i]-'a'+1];
    }
    
