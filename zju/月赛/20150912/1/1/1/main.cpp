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
#define MAX 105
#define MOD 1000000007
#define NIL
typedef long long LL;
typedef stack<int> SI;
typedef vector<int> VI;
typedef deque<int> DQI;
typedef priority_queue<int> PQI;
char str[100005];
int op[MAX];
bool vst[MAX][MAX];
LL ans[MAX][MAX][2];
int num[MAX];
int top;
void deco(char str[]) {
    int tmp = strlen(str);
    int f = 0;
    top = 0;
    for(int i = 0;i < tmp;i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            if(!f) {num[top++] = 0;f = true;}
        }
        else if(str[i] >= 'a' && str[i] <= 'z') {
            if(!f) {num[top++] = 1;f = true;}
        }
        else if(str[i] == '*') {
            op[top] = 1;
            f = false;
        }
        else if(str[i] == '!') {
            op[top] = 2;
            f = false;
        }
        else if(str[i] == '^') {
            op[top] = 3;
            f = false;
        }
        else if(str[i] == '.') {
            op[top] = 4;
            f = false;
        }
    }
}
void work(int b,int e) {
    //printf("%d %d\n",b,e);
    if(vst[b][e]) return;
    vst[b][e] = vst[e][b] = true;
    if(b == e) {
        ans[b][b][num[b]] = 1;
        return;
    }
    LL ret[2];
    ret[0] = ret[1] = 0;
    for(int i = b+1;i <= e;i++) {
        work(b,i-1);
        work(i,e);
        if(op[i] == 1) {
            ret[0] += ans[b][i-1][0] * ans[i][e][0];
            ret[1] += ans[b][i-1][0] * ans[i][e][1] + ans[b][i-1][1] * ans[i][e][0];
        }
        else if(op[i] == 2) {
            ret[0] += ans[b][i-1][1] * ans[i][e][1];
            ret[1] += ans[b][i-1][0] * ans[i][e][1] + ans[b][i-1][1] * ans[i][e][0] + ans[b][i-1][0] * ans[i][e][0];
        }
        else if(op[i] == 3) {
            ret[1] += ans[b][i-1][1] * ans[i][e][1];
            ret[0] += 0;
        }
        else if(op[i] == 4) {
            ret[0] += ans[b][i-1][1] * ans[i][e][1];
            ret[1] += 0;
        }
        ret[0] %= MOD;
        ret[1] %= MOD;
    }
    //ret[0] = ((ret[0] % MOD) + MOD ) % MOD;
    //ret[1] = ((ret[1] % MOD) + MOD ) % MOD;
    ans[b][e][0] = ret[0];
    ans[b][e][1] = ret[1];
}
int main()
{
    freopen("in.txt","r",stdin);
    int t;
    cin >> t;
    while(t--) {
        scanf("%s",str);
        deco(str);
        memset(ans,0,sizeof ans);
        memset(vst,false,sizeof vst);
        //printf("qwe");
        work(0,top-1);
        printf("%lld\n",ans[0][top-1][0] + ans[0][top-1][1]);
        //for(int i = 0;i < top;i++) {for(int j = 0;j < top;j++) printf("%I64d,%I64d ",ans[i][j][0],ans[i][j][1]); printf("\n");}
        
    }
    return 0;
}