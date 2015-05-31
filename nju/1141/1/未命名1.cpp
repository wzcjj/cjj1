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
    while(!a.empty())a.pop();
    int ans=0;
    while(1){
        char c;
        scanf("%c",&c);
        if(c=='('||c=='['||c=='{'){
            a.push(c);
        }
        else 
        if(c==')'||c==']'||c=='}'){
            if(a.empty()){
                printf("0\n");
                bool flag=false;
                while(c!='\n')if(scanf("%c",&c)==EOF){
                    flag=true;
                    break;
                }
                if(c!='\n')break;
                ans=0;
                continue;
            }
            char c2=a.top();
            if(c==')'&&c2=='('||c==']'&&c2=='['||c=='}'&&c2=='{'){
                ans++;
                a.pop();
            }
            else{
                printf("0\n");
                bool flag=false;
                while(c!='\n')if(scanf("%c",&c)==EOF){
                    flag=true;
                    break;
                }
                if(c!='\n')break;
                while(!a.empty())a.pop();
                ans=0;
                continue;
            }
        }
        else{
            if(a.empty())cout<<ans<<endl;
            else printf("0\n");
            while(!a.empty())a.pop();
            ans=0;
            if(c!='\n')break;
        }
    }
    return 0;
}
