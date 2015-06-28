#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
bool l[20005],r[20005];
int main(){
    int i,j,m,n;
    string s;
    cin>>n;
    cin>>s;
    int ans=0;
    int t=0;
    for(i=0;i<s.size();i++){
        if(ans==0){
            t=s[i];
            ans++;
        }
        else{
            if(t==s[i])ans++;
            else ans--;
        }
    }
    cout<<ans<<endl;
    return 0;
} 
