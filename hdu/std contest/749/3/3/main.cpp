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
#define maxn 100005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int a[maxn];
priority_queue<int> q;
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,t;
    //cin>>N;
    while (scanf("%d%d%d",&n,&m,&t)!=EOF) {
        while(!q.empty())q.pop();
        for(i=1;i<=n;i++){
            int x,y;
            scanf("%d:%d",&x,&y);
            q.push(-(60*x+y));
        }
        for(i=1;i<m;i++){
            int x=q.top();
            q.pop();
            q.push(x-t);
        }
        int x=q.top();
        printf("%02d:%02d\n",-x/60,-x%60);
    }
    return 0;
}
