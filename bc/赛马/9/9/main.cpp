#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
#define MAX 1000050
#define NIL
typedef long long LL;
typedef stack<int> SI;
typedef vector<int> VI;
typedef deque<int> DQI;
typedef priority_queue<int> PQI;
VI v[MAX];
int n,m1,m2,fa[MAX];
bool vst[MAX];
bool visi[MAX];
int ru[MAX];
int getfa(int x) {return (fa[x]==x)?fa[x]:fa[x]=getfa(fa[x]);}
bool DFS(int x){
    vst[x] = true;
    visi[x] = true;
    for(int i = 0;i < v[x].size();i++) {
        if(vst[v[x][i]]){
            vst[x]=false;
            return true;
        }
        if(getfa(v[x][i])!=v[x][i] || visi[v[x][i]]) continue;
        if(DFS(v[x][i])){
            vst[x]=false;
            return true;
        }
    }
    vst[x] = false;
    return false;
}
int main()
{
    freopen("in.txt","r",stdin);
            memset(vst,false,sizeof vst);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m1 >> m2;
        memset(ru,0,sizeof ru);
        bool flag = false;
        for(int i = 1;i <=n;i++) {fa[i] = i;v[i].clear();}
        for(int i = 0;i < m1;i++) {
            int t1,t2;
            scanf("%d%d",&t1,&t2);
            if(t1 < t2) swap(t1,t2);
            if(getfa(t1) == getfa(t2)) flag = true;
            fa[getfa(t1)] = getfa(t2);
        }
        for(int i = 0;i < m2;i++) {
            int t1,t2;
            scanf("%d%d",&t1,&t2);
            v[getfa(t1)].push_back(getfa(t2));
        }
        for(int i=1;i<=n;i++)if(getfa(i)==i){
            for(int j=0;j<v[i].size();j++)ru[v[i][j]]++;
        }
            memset(visi,false,sizeof visi);
        for(int i = 1;i <= n;i++) {
            if(getfa(i)!=i || visi[i] || ru[i]==0)continue;
            if(DFS(i)) {
                flag = true;
                break;
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
