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
#define maxn 15
#define P 1000000007
#define INF 10000000000000LL
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int a[maxn],b[maxn],n,m;
long long ans,sum,cnt;
bool flag[maxn];
void dfs(int x){
    if(x>n){
        if(sum<ans)ans=sum;
        /*int cnt=0,sum=0;
        for(int i=1;i<=n;i++){
            cnt+=(a[d[i]]-1)/m+1;
            sum+=(cnt-1)*b[d[i]];
        }
        if(sum<ans)ans=sum;*/
        return;
    }
    for(int i=1;i<=n;i++){
        if(!flag[i]){
            flag[i]=true;
            cnt+=(a[i]-1)/m+1;
            sum+=(cnt-1)*b[i];
            //c[x]=i;
            //d[i]=x;
            if(sum<ans)dfs(x+1);
            sum-=(cnt-1)*b[i];
            cnt-=(a[i]-1)/m+1;
            flag[i]=false;
        }
    }
}
int main(int argc, const char * argv[]) {
    int i;
    //cin>>N;
    memset(flag,0,sizeof(flag));
    while (scanf("%d%d",&n,&m)!=EOF) {
        //scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d%d",&a[i],&b[i]);
        }
        ans=INF;
        cnt=sum=0;
        dfs(1);
        printf("%lld\n",ans);
    }
    return 0;
}
