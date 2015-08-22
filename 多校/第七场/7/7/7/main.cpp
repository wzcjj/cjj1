#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
#define MAX 200050
#define NIL -99999999
typedef long long LL;
typedef stack<int> SI;
typedef vector<int> VI;
typedef deque<int> DQI;
typedef priority_queue<int> PQI;
LL dp[MAX][2];
char str[MAX];
int num[MAX];
int main()
{
    //freopen("in.txt","r",stdin);
    int t,cnt = 0;scanf("%d",&t);
    while(t--) {
        printf("Case #%d: ",++cnt);
        scanf("%s",str);
        for(int i = 0;i < strlen(str);i++) scanf("%d",&num[i]);
        if(str[0] == '0') {
            dp[0][0] = 0;
            dp[0][1] = NIL;
        }
        else if(str[0] == '1') {
            dp[0][1] = num[0];
            dp[0][0] = NIL;
        }
        else {
            dp[0][1] = 1;
            dp[0][0] = 0;
        }
        //printf("%I64d %I64d\n",dp[0][0],dp[0][1]);
        for(int i = 1;i < strlen(str);i++) {
            if(str[i] == '0') {
                dp[i][0] = max(dp[i-1][0],dp[i-1][1]+num[i]);
                dp[i][1] = NIL;
            }
            else if (str[i] == '1') {
                dp[i][0] = NIL;
                dp[i][1] = max(dp[i-1][0]+num[i],dp[i-1][1]);
            }
            else {
                dp[i][0] = max(dp[i-1][0],dp[i-1][1]+num[i]);
                dp[i][1] = max(dp[i-1][0]+num[i],dp[i-1][1]);
            }
            //printf("%I64d %I64d\n",dp[i][0],dp[i][1]);
        }
        printf("%lld\n",max(dp[strlen(str)-1][0],dp[strlen(str)-1][1]));
    }
    return 0;
}