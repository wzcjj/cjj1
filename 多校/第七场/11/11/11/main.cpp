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
#define MAX 100050
#define NIL
#define MOD 1000000007
typedef long long LL;
typedef stack<int> SI;
typedef vector<int> VI;
typedef deque<int> DQI;
typedef priority_queue<int> PQI;
int n,cnte;
int head[MAX],fa[MAX];
LL ans,p[MAX];
bool flag[MAX],vst[MAX],isleaf[MAX];
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
    vst[x] = true;
    int cnt = 0;
    int cnt2 = 0;
    isleaf[x] = true;
    for(int i = head[x];i != -1;i = e[i].next) {
        int v = e[i].v;
        if(!vst[v]) {
            isleaf[x] = false;
            dfs(v,x);
            if(!isleaf[v]) cnt++;
            cnt2++;
        }
    }
    if(cnt > 2) ans = -1;
    if(cnt2 > 1) flag[x] = true;
}
LL work(int x) {
    LL ret = 1;
    if(isleaf[x]) return 1;
    int cntl = 0;
    bool ff = true;
    for(int i = head[x];i != -1;i = e[i].next) {
        int v = e[i].v;
        if(fa[v] == x) {
            if(isleaf[v]) {
                cntl++;
            }
            else {
                ff = false;
                ret *= work(v);
                ret %= MOD;
                ret += MOD;
                ret %= MOD;
            }
        }
    }
    ret *= p[cntl];
    ret %= MOD;
    ret += MOD;
    ret %= MOD;
    if(flag[x] && !ff) {
        ret *= 2;
        ret %= MOD;
        ret += MOD;
        ret %= MOD;
    }
    if((x == 1) || (x != 1 && !flag[fa[x]])) {
        ret *= 2;
        ret %= MOD;
        ret += MOD;
        ret %= MOD;
    }
    //printf("%d %I64d\n",x,ret);
    return ret;
}
int main()
{
    freopen("in2.txt","r",stdin);
    int t,cnt = 0;cin >> t;
    p[0] = 1;
    for(int i = 1;i < MAX;i++) {
        p[i] = p[i-1] * i;
        p[i] %= MOD;
        p[i] += MOD;
        p[i] %= MOD;
    }
    while(t--) {
        printf("Case #%d: ",++cnt);
        memset(head,-1,sizeof head);
        scanf("%d",&n);
        cnte = 0;
        for(int i = 1;i < n;i++) {
            int x,y;scanf("%d%d",&x,&y);
            addedge(x,y);addedge(y,x);
        }
        memset(vst,false,sizeof vst);
        memset(flag,false,sizeof flag);
        memset(isleaf,false,sizeof isleaf);
        ans = 0;
        dfs(1,-1);
        //for(int i = 1;i <= n;i++) printf("%d %d %d %d\n",isleaf[i],flag[i],fa[i],i);
        if(ans == -1) {
            puts("0");continue;
        }
        printf("%I64d\n",work(1));
    }
    return 0;
}