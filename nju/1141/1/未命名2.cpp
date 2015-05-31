#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<stack>
using namespace std;
stack<char>a;
int main(){
    int i,j,m,n;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    string s;
    while(cin>>s){
        while(!a.empty())a.pop();
        int ans=0;
        for(i=0;i<s.size();i++){
            char c=s[i];
            if(c=='('||c=='['||c=='{'){
                a.push(c);
            }
            else 
            if(c==')'||c==']'||c=='}'){
                if(a.empty()){
                    printf("0\n");
                    break;
                }
                char c2=a.top();
                if(c==')'&&c2=='('||c==']'&&c2=='['||c=='}'&&c2=='{'){
                    ans++;
                    a.pop();
                }
            }
        }
        if(i==s.size()){
            if(a.empty())cout<<ans<<endl;
            else printf("0\n");
        }
    }
    return 0;
}
