#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std; 
int calc(int x,int y){
    if(x<=y)return 1;
    else return 0;
}
int main(){
    string s,s1;
    int i,j,m,n;
    cin>>s;
    for(i=0;i<=s.length();i++){
        char c;
        for(c='a';c<='z';c++){
            s1=s.substr(0,i)+c+s.substr(i,s.length()-i);
            int z=0;
            for(j=0;j<=s1.length()/2;j++){
                if(s1[j]!=s1[s1.length()-j-1]){
                    z=1;
                    break;
                }
            }
            if(z==0){
                cout<<s1<<endl;
                return 0;
            }
        }
    }
    cout<<"NA"<<endl;
    return 0;
}
            
            
