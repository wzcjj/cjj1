#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int dp[26];
int sum[26];
int main(){
    int i,j,m,n,N,k,l;
    cin>>N;
    int I=0;
    while(N--){
        I++;
        printf("Case #%d:\n",I);
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        string s;
        cin>>s;
        n=s.length();
        for(i=0;i<n;i++){
            int t=s[i]-'a';
            int now=20000000;
            for(j=0;j<26;j++)if(dp[j]<now)now=dp[j];
            dp[t]=now+1;
        }
        int ans=200000000;
        for(j=0;j<26;j++)if(dp[j]<ans)ans=dp[j];
        printf("%d ",ans+1);
        int all=0;
        for(i=ans;i<n;i++){
            all-=sum[s[i]-'a'];
            
        printf("%d\n"
    }
    return 0;
}    
        
            
