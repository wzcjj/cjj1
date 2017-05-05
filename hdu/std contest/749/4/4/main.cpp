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
char s[20],s1[20];
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    //cin>>N;
    while (scanf("%d%d",&n,&m)!=EOF) {
        int ans=0,sum=0,flag=0;
        for(i=1;i<=n;i++){
            scanf("%s%s",s1,s);
            if(s1[0]=='i'){
                if(strcmp(s,"wnm")==0)flag=1;
                sum+=strlen(s);
                if(flag&&sum%m==0&&!ans)ans=i;
            }
            else {
                sum-=strlen(s);
                if(flag&&sum%m==0&&!ans)ans=i;
            }
        }
        if(ans)printf("^_^ %d\n",ans);
        else printf("T_T\n");
    }
    return 0;
}
