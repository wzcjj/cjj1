#include <iostream>
#include <cstdio>
#include <cstring>
#include<string>
#include <cmath>
using namespace std;
int main(){
    int i,j,m,n,I=0; 
    while(cin>>n){
        I++;
        int ans=0;
        for(i=1;i<=n;i++){
            int t=0;
            string s;
            cin>>s;
            for(j=0;j<s.size();j++)t+=s[j];
            if(t>ans)ans=t;
        }
        printf("Case %d: %d\n",I,ans);
    }
    return 0;
}
