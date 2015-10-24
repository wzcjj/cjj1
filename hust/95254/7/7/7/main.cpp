#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
#include <iomanip>
#include <map>
#include <cstring>

#define MAX 105
#define INF (1 << 20)
#define MOD
#define NIL -(1 << 30)
#define A first
#define B second
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef queue<int> QI;
typedef priority_queue<int> PQI;
int n,m,nows,h;
int s[(1<<15)+1][20];
bool inq[(1<<15)+1][20];
int gra[MAX][MAX];
struct H{
    int id,c,d;
}cc[20];
queue<pair<int,int> > q;
int main()
{
    //freopen("in.txt","r",stdin);
    int t;cin >> t;
    while(t--) {
        cin >> n >> m >> nows;
        for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) gra[i][j] = (i==j)?0:INF;
        for(int i = 1;i <= m;i++) {
            int x,y,z;scanf("%d%d%d",&x,&y,&z);
            gra[x][y] = gra[y][x] = min(z,gra[x][y]);
        }
        for(int t = 1;t <= n;t++) for(int i = 1;i <= n;i++) for(int j = i+1;j <= n;j++) gra[j][i] = gra[i][j] = min(gra[i][j],gra[i][t]+gra[t][j]);
        cin >> h;
        for(int i = 1;i <= h;i++) {
            scanf("%d%d%d",&cc[i].id,&cc[i].c,&cc[i].d);
        }
        for(int i = 0;i <= (1 << 15);i++) {
            for(int j = 0;j <= h;j++) {
                s[i][j] = NIL;
            }
        }
        s[0][1] = nows;
        while(!q.empty()) q.pop();
        memset(inq,false,sizeof inq);
        q.push(make_pair(0,1));
        inq[0][1] = true;
        while(!q.empty()) {
            int now = q.front().A;
            int id = q.front().B;
            q.pop();
            inq[now][id] = false;
            for(int i = 1;i <= h;i++) {
                if(now&(1<<(i-1))) continue;
                int nex = now|(1<<(i-1));
                int nexid = i;
                int neww = s[now][id] - gra[id][cc[nexid].id];
                if(neww < cc[nexid].d) continue;
                neww += cc[nexid].c - cc[nexid].d;
                if(s[nex][nexid] < neww) {
                    s[nex][nexid] = neww;
                    if(!inq[nex][nexid]) {
                        q.push(make_pair(nex,nexid));
                        inq[nex][nexid] = true;
                    }
                }
            }
        }
        int ans = NIL;
        for(int i = 1;i <= h;i++) {
            ans = max(ans,s[(1<<h)-1][i] - gra[cc[i].id][1]);
        }
        printf(ans >= 0 ? "YES\n" : "NO\n");
    }
    return 0;
}