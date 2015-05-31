#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<stack>
using namespace std;
int a[1000005];
int main(){
    int i,j,m,n;
    string s;
    while(cin>>s){
        n=s.size();
        a[n]=0;
        long long ans=0;
        for(i=n-1;i>=0;i--)if(s[i]==')')a[i]=a[i+1]+1;
        else a[i]=a[i+1];
        for(i=0;i<n-1;i++)if(s[i]=='(')ans+=a[i+1];
        cout<<ans<<endl;
    }
    return 0;
}
