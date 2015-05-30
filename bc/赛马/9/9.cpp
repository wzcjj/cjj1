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
#define MAX 1050
#define NIL
typedef long long LL;
typedef stack<int> SI;
typedef vector<int> VI;
typedef deque<int> DQI;
typedef priority_queue<int> PQI;
VI v;
int gra[MAX][MAX],n,m1,m2,fa[MAX];
int getfa(int x) {return (fa[x]==x)?fa[x]:getfa(fa[x]);}
bool DFS(int x){
    v.push_back(x);
    for(int i = 1;i <= n;i++) {
        if(getfa(i)!=i)continue;
        if(x == i)continue;
        if(gra[x][i]) {
            for(int j = 0;j < v.size()-1;j++) if(v[j]==i) return true;
            gra[x][i]--;
            if(DFS(i)) return true;
            gra[x][i]++;
        }
    }
    return false;
}
int main()
{
    freopen("in.txt","r",stdin);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m1 >> m2;
        bool flag = false;
        memset(gra,0,sizeof gra);
        for(int i = 1;i <=n;i++) fa[i] = i;
        for(int i = 0;i < m1;i++) {
            int t1,t2;
            scanf("%d%d",&t1,&t2);
            if(t1 < t2) swap(t1,t2);
            if(getfa(t1) == getfa(t2)) flag = true;
            fa[t1] = getfa(t2);
        }
        for(int i = 0;i < m2;i++) {
            int t1,t2;
            scanf("%d%d",&t1,&t2);
            gra[getfa(t1)][getfa(t2)]++;
        }
        /*for(int i = 1;i <= n;i++) printf("%d ",fa[i]);
        puts("\n");
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++){
                printf("%d ",gra[i][j]);
            }
            printf("\n");
        }*/
        for(int i = 1;i <= n;i++) {
            if(getfa(i)!=i)continue;
            v.clear();
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
