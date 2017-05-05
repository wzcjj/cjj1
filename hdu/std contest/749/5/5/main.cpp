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

int gcd(int a,int b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
}
int exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    int r=exgcd(b,a%b,x,y);
    int t=x;x=y;y=t-a/b*y;
    return r;
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,a,b,c;
    cin>>N;
    while (N--) {
        scanf("%d%d%d%d",&a,&b,&c,&n);
        if(n%c==0){
            printf("Yes\n");
            continue;
        }
        bool flag=0;
        int t=gcd(a,b);
        while(n>0){
            int x,y;
            if(n%t==0){
                exgcd(a,b,x,y);
                long long x1=(long long)n*x/t,y1=(long long)n*y/t;
                if(y1<0){
                    swap(a,b);
                    swap(x1,y1);
                }
                long long t1=(-x1-1)/(b/t)+1;
                x1+=t1*(b/t);
                y1-=t1*(a/t);
                if(y1>=0){
                    flag=1;
                    break;
                }
            }
            n-=c;
        }
        if(flag)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
