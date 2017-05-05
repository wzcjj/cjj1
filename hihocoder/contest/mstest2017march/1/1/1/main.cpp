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
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,p,q;
    //cin>>N;
    N=1;
    while (N--) {
        scanf("%d%d%d",&p,&q,&n);
        double x,y,ans=0,now;
        for(i=0;i<n;i++){
            if(p<(1<<i))break;
            x=p/(1<<i);
            x/=100;
            y=q;
            y/=100;
            now=1;
            while(x<1){
                ans+=now;
                now*=1-x;
                x+=y;
                //printf("%lf %lf %lf %lf\n",ans,now,x,y);
            }
            ans+=now;
        }
        for(;i<n;i++){
            x=0;
            y=q;
            y/=100;
            now=1;
            while(x<1){
                ans+=now;
                now*=1-x;
                x+=y;
            }
            ans+=now;
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
