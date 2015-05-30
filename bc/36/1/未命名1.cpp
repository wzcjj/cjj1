#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main(){ 
    int i,j,m,n;
    string s;
    int le[5];
    while(cin>>s){
        int sum=0;
        if(s.size()%3==0){
            int z=1;
            for(i=1;i<s.size()/3;i++)if(s[i]!=s[i-1])z=0;
            for(i=s.size()/3+1;i<s.size()/3*2;i++)if(s[i]!=s[i-1])z=0;
            for(i=s.size()/3*2+1;i<s.size();i++)if(s[i]!=s[i-1])z=0;
            if(s[0]==s[s.size()/3])z=0;
            if(s[s.size()/3]==s[s.size()/3*2])z=0;
            if(s[s.size()/3*2]==s[0])z=0;
            if(z)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}
