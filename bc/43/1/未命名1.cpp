#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int main(){
    int i,j,m,n,I=0,N;
    cin>>N;
    while(N--){
        string s;
        cin>>s;
        for(i=0;i<s.size()/2;i++)cout<<s[2*i];
        cout<<endl;
        for(i=0;i<s.size()/2;i++)cout<<s[s.size()-2*i-1];
        cout<<endl;
    }
    system("pause");
    return 0;
}
