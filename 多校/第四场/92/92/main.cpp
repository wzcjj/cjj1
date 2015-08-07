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
#define MAX 1050
#define NIL
typedef long long LL;
typedef stack<int> SI;
typedef vector<int> VI;
typedef deque<int> DQI;
typedef priority_queue<int> PQI;
int n,m,maxc,len;
bool gra[MAX][MAX];
int vst[MAX][MAX];
int di[4][2] = {0,-1,-1,0,1,0,0,1};
struct P {
    int x,y;
    P(int a,int b) {x = a;y = b;}
};
void bfs() {
    memset(vst,-1,sizeof vst);
    queue<P> q;
    while(!q.empty()) q.pop();
    q.push(P(1,1));
    vst[1][1] = 1;
    while(!q.empty()) {
        P now = q.front();
        q.pop();
        int nx = now.x,ny = now.y;
        for(int i = 0;i < 4;i++) {
            int newx = nx + di[i][0];
            int newy = ny + di[i][1];
            if(newx > 0 && newx <= n && newy > 0 && newy <= m && vst[newx][newy] == -1) {
                vst[newx][newy] = 1;
                maxc = max(newx + newy ,maxc);
                if(!gra[newx][newy]) q.push(P(newx,newy));
            }
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    int t;cin >> t;
    while(t--){
        scanf("%d%d%*c",&n,&m);
        for(int i = 1;i <= n;i++) {
            char str[MAX];
            gets(str);
            //puts(str);
            for(int j = 0;j < m;j++) {
                if(str[j] == '0') gra[i][j+1] = false;
                else gra[i][j+1] = true;
            }
        }
        maxc = 0;
        if(!gra[1][1])
            bfs();
        else {
            maxc = 2;
            memset(vst,-1,sizeof vst);
            vst[1][1] = 1;
        }
        if(vst[n][m] == 1 && !gra[n][m]) {puts("0");continue;}
        //printf("%d\n",maxc);
        //for(int i = 1;i <= n;i++) {for(int j = 1;j <= m;j++) printf("%d ",vst[i][j]); printf("\n");}
        printf("1");
        for(int i = maxc;i < n + m;i++) {
            int f = 0;
            for(int j = max(1,i-m);j <= n && i-j > 0 && i-j <= m;j++) {
                int x = j;
                int y = i - j;
                //printf("%d\t%d\n",x,y);
                if(vst[x][y] != 1) continue;
                int newx,newy;
                if(y + 1 <= m) {
                    newx = x;newy = y + 1;
                    if(!gra[newx][newy]) {f = 1;vst[newx][newy] = 1;}
                    else {vst[newx][newy] = -2;}
                }
                if(x + 1 <= n) {
                    newx = x + 1;newy = y;
                    if(!gra[newx][newy]) {f = 1;vst[newx][newy] = 1;}
                    else {vst[newx][newy] = -2;}
                }
            }
            if(f) {
                printf("0");
            }
            else {
                for(int j = max(1,i-n);j <= n && i-j > 0 && i-j <= n;j++) {
                    int x = j;
                    int y = i - j;
                    int newx,newy;
                    if( y + 1 <= m) {
                        newx = x;newy = y + 1;
                        if(vst[newx][newy] == -2) vst[newx][newy] = 1;
                    }
                    if(x + 1 <= n) {
                        newx = x + 1;newy = y;
                        if(vst[newx][newy] == -2) vst[newx][newy] = 1;
                    }
                }
                printf("1");
            }
        }
        puts("");
    }
    return 0;
}