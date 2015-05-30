#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
#define MAX 25
int n,a[MAX],b[MAX];
int DP[MAX][MAX][MAX][MAX][2];
int dfs(int ba,int ea,int bb,int eb,int first) {
     int dp = 0;
     if(ba > ea && bb > eb) return 0;
     if(DP[ba][ea][bb][eb][first] != -1) return DP[ba][ea][bb][eb][first];
     if(first) {
        if(ba <= ea) dp = max(dp,a[ba]+dfs(ba+1,ea,bb,eb,0));
        if(ba <= ea) dp = max(dp,a[ea]+dfs(ba,ea-1,bb,eb,0));
        if(bb <= eb) dp = max(dp,b[bb]+dfs(ba,ea,bb+1,eb,0));
        if(bb <= eb) dp = max(dp,b[eb]+dfs(ba,ea,bb,eb-1,0));
     }
     else {
        int dp1=100000000,dp2=100000000;
        if(ba <= ea) dp1 = min(dfs(ba,ea-1,bb,eb,1),dfs(ba+1,ea,bb,eb,1));
        if(bb <= eb) dp2 = min(dfs(ba,ea,bb,eb-1,1),dfs(ba,ea,bb+1,eb,1));
        dp = min(dp1,dp2);
     }

     return DP[ba][ea][bb][eb][first] = dp;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int t;cin >> t;
    while(t--) {
        cin >> n;
        memset(DP,-1,sizeof DP);
        for(int i = 1;i <= n;i++) cin >> a[i];
        for(int i = 1;i <= n;i++) cin >> b[i];
        cout << dfs(1,n,1,n,1) << endl;
    }
    return 0;
}
