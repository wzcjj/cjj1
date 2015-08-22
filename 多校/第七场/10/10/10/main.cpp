#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
#define MAX 1050
#define NIL
#define MOD 1000000007
typedef long long LL;
typedef stack<int> SI;
typedef vector<int> VI;
typedef deque<int> DQI;
typedef priority_queue<int> PQI;
int n,k,cnte,head[MAX];
int siz[MAX];
LL dp[MAX][MAX],p[MAX];
LL c[MAX][MAX];
int fa[MAX];
bool vst[MAX],isleaf[MAX];
struct T {
    int u,v,next;
}e[MAX << 1];
void addedge(int u,int v) {
    e[cnte].u = u;
    e[cnte].v = v;
    e[cnte].next = head[u];
    head[u] = cnte++;
}
void dfs(int x,int f) {
    fa[x] = f;
    siz[x] = 1;
    vst[x] = true;
    isleaf[x] = true;
    for(int i = head[x];i != -1;i = e[i].next) {
        int v = e[i].v;
        if(!vst[v]) {
            isleaf[x] = false;
            dfs(v,x);
            siz[x] += siz[v];
        }
    }
}
void work(int x) {
    if(isleaf[x]) {
        dp[x][1] = 1;
        return;
    }
    LL tmp[MAX];
    int cntl = 0;
    bool ff = true;
    int now = siz[x]-1;
    LL mu = 1;
    for(int i = head[x];i != -1;i = e[i].next) {
        int v = e[i].v;
        if(fa[v] == x) {
            work(v);
            cntl++;
            if(ff) {
                for(int i = 1;i <= siz[v];i++) dp[x][i] = dp[v][i];
                ff = false;
            }
            else {
                memset(tmp,0,sizeof tmp);
                for(int j = siz[x];j >= 1;j--) {
                    for(int k = min(j,siz[v]);k >= 1;k--) {
                        tmp[j] += dp[x][j-k] * dp[v][k];
                        //printf("%d %d %I64d\n",j,k,tmp[j]);
                    }
                }
                for(int j = siz[x];j >= 1;j--) {dp[x][j] = tmp[j];}//printf("%I64d ",dp[x][j]);}puts("");
            }
            mu *= c[now][siz[v]];
            now -= siz[v];
        }
    }
    for(int i = 1;i <= siz[x];i++) {
        dp[x][i] *= mu;
        dp[x][i] %= MOD;
        dp[x][i] += MOD;
        dp[x][i] %= MOD;
    }
    for(int i = siz[x];i >= 1;i--) {
        dp[x][i] = dp[x][i] * (siz[x] - 1);
        dp[x][i] += dp[x][i-1];
        dp[x][i] %= MOD;
        dp[x][i] += MOD;
        dp[x][i] %= MOD;
    }
    /*printf("%d\n",x);
     for(int i = 1;i <= siz[x];i++) {
     printf("%I64d ",dp[x][i]);
     }puts("");*/
}
int main()
{
    //freopen("in.txt","r",stdin);
    memset(p,0,sizeof p);
    p[0] = 1;
    for(int i = 1;i <= 1000;i++) {
        p[i] = p[i-1] * i;
        p[i] %= MOD;
        p[i] += MOD;
        p[i] %= MOD;
    }
    for(int i = 1;i <= 1000;i++) {
        c[i][0] = 1;
        c[i][1] = i;
    }
    for(int i = 1;i <= 1000;i++) {
        for(int j = 2;j <= i;j++) {
            c[i][j] = c[i][j-1] * (i-j+1) / j;
            c[i][j] %= MOD;
            c[i][j] += MOD;
            c[i][j] %= MOD;
        }
    }
    int t,cnt = 0;scanf("%d",&t);
    while(t--) {
        printf("Case #%d: ",++cnt);
        scanf("%d%d",&n,&k);
        memset(head,-1,sizeof head);
        cnte = 0;
        for(int i = 1;i < n;i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            addedge(x,y);
            addedge(y,x);
        }
        memset(dp,0,sizeof dp);
        memset(siz,0,sizeof siz);
        memset(vst,false,sizeof vst);
        memset(isleaf,false,sizeof isleaf);
        dfs(1,-1);
        work(1);
        printf("%I64d\n",dp[1][k]);
    }
    return 0;
}