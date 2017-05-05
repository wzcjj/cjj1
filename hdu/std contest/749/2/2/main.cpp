
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
#define maxn 20005
#define P 1000000007
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int a[maxn];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,x,y;
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d%d",&x,&y);
            a[x]=y;
        }
        double ans=a[1];
        int sum=a[1];
        for(i=2;i<=n;i++){
            ans+=a[i];
            ans+=1.0*sum/(i-1);
            sum+=a[i];
        }
        printf("%.2lf\n",ans-1000);
    }
    return 0;
}
