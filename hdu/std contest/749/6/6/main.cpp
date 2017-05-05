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

priority_queue<long long>p;
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    //cin>>N;
    while (scanf("%d",&n)!=EOF) {
        //scanf("%d",&n);
        while(!p.empty())p.pop();
        long long maxx=0;
        for(i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            p.push(-x);
            if(maxx<x)maxx=x;
        }
        long long ans=maxx+p.top();
        while(true){
            long long x=-p.top();
            if(x==1)break;
            p.pop();
            if(maxx-x>ans)break;
            if(maxx-x<ans)ans=maxx-x;
            if(x*x>maxx)maxx=x*x;
            p.push(-x*x);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
