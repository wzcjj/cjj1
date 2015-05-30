#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int i,j,m,n;
        int w=0;
        int b=0;
    for(i=1;i<=8;i++){
        string s;
        cin>>s;
        for(j=0;j<8;j++){
            if(s[j]=='Q')w+=9;
            if(s[j]=='R')w+=5;
            if(s[j]=='B')w+=3;
            if(s[j]=='N')w+=3;
            if(s[j]=='P')w+=1;
            if(s[j]=='q')b+=9;
            if(s[j]=='r')b+=5;
            if(s[j]=='b')b+=3;
            if(s[j]=='n')b+=3;
            if(s[j]=='p')b+=1;
        }
    }
    if(b>w)cout<<"Black";
    if(b<w)cout<<"White";
    if(b==w)cout<<"Draw";
    return 0;
}
