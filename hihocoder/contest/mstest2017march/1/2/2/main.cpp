#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <bitset>
#include <functional>
#include <algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 105
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

vector<int> a[maxn];
int b[maxn];
int c[maxn];
int d[maxn][maxn];
int e[maxn];
int f[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,k,l;
    //cin>>N;
    N=1;
    while (N--) {
        scanf("%d%d%d",&n,&m,&k);
        for(i=1;i<=m;i++){
            scanf("%d",&b[i]);
        }
        for(i=1;i<=m;i++)a[i].clear();
        memset(e,0,sizeof(e));
        f[1]=0;
        for(i=1;i<=m;i++){
            for(j=1;j<=b[i];j++){
                int x;
                scanf("%d",&x);
                a[i].push_back(x);
            }
        }
        for(i=1;i<=k;i++){
            scanf("%d",&c[i]);
            e[c[i]]=i;
        }
        for(i=1;i<=k;i++){
            for(j=1;j<=k;j++){
                scanf("%d",&d[c[i]][c[j]]);
            }
        }
        for(i=m;i>1;i--){
            int now=0;
            while(e[a[i-1][now]])now++;
            f[a[i][0]]=a[i-1][now];
            for(l=1;l<=n;l++)d[a[i-1][now]][l]=d[l][a[i-1][now]]=d[a[i][0]][l]-1;
            for(j=1;j<a[i].size();j++){
                if(d[a[i][j-1]][a[i][j]]==2){
                    f[a[i][j]]=a[i-1][now];
                }
                else {
                    now++;
                    while(e[a[i-1][now]])now++;
                    f[a[i][j]]=a[i-1][now];
                    for(l=1;l<=n;l++)d[a[i-1][now]][l]=d[l][a[i-1][now]]=d[a[i][j]][l]-1;
                }
            }
        }
        for(i=1;i<n;i++)printf("%d ",f[i]);
        printf("%d\n",f[n]);
    }
    return 0;
}
