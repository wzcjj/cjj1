
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define MAX 1050
#define NIL
typedef long long LL;
typedef stack<int> SI;
typedef vector<int> VI;
typedef deque<int> DQI;
typedef priority_queue<int> PQI;
int n,m,gra[MAX][MAX],pre[MAX];
int dfn[MAX],low[MAX],dfc;
bool vst[MAX],flag[MAX];
VI v;
void DFS(int x) {
    vst[x] = true;
    dfn[x] = low[x] = ++dfc;
    //printf("pDFS%d,DFN%d,LOW%d\n",x,dfn[x],low[x]);
    for(int i = 1;i <= n;i++) {
        if(gra[x][i] != -1) {
            if(!vst[i]) {
                pre[i] = x;
                DFS(i);
                //printf("iDFS%d,DFN%d,LOW%d\n",i,dfn[i],low[i]);
                low[x] = min(low[x],low[i]);
            }
            else if(i != pre[x])
                low[x] = min(low[x],dfn[i]);
        }
    }
    if(low[x] == dfn[x]) flag[x] = true;
    //printf("DFS%d,DFN%d,LOW%d\n",x,dfn[x],low[x]);
}
int tarjan() {
    memset(vst,false,sizeof vst);
    memset(flag,false,sizeof flag);
    for(int i = 1;i <= n;i++) pre[i] = -1;
    dfc = 0;
    for(int i = 1;i <= n;i++) {
        if(!vst[i]) DFS(i);
    }
    int ans = 9999999;
    for(int i = 1;i <= n;i++) {
        if(flag[i] && pre[i] != -1) {
            //printf("%d ",i);
            ans = min(ans,gra[i][pre[i]]);
        }
    }
    return ans;
}
int main()
{
    //freopen("in.txt","r",stdin);
    while(cin >> n >> m && (n || m)) {
        memset(gra,-1,sizeof gra);
        for(int i = 0;i < m;i++) {
            int x,y,w;
            cin >> x >> y >> w;
            gra[x][y] = w;
            gra[y][x] = w;
        }
        int ans = tarjan();
        if(ans == 9999999) ans = -1;
        printf("%d\n",ans);
    }
    return 0;
}
