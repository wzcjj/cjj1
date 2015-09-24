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
#define INF 2100000000
using namespace std;

vector<int> a[maxn];
int top;
int fst[maxn];
int de[maxn],su[maxn];
int fa[maxn][20];
struct D{
    int dee,id;
    void operator = (D d1) {
        this->id = d1.id;
        this->dee = d1.id;
        return;
    }
}dp[maxn][20],dft[maxn << 2];
void st(int n) {
    for(int i = 1;i <= n;i++) {
        dp[i][0] = dft[i];
    }
    for(int j = 1;(1<<j) <= n;j++) {
        for(int i = 1;i + (1 << j) - 1 <= n;i++) {
            D a = dp[i][j-1],b = dp[i+(1<<(j-1))][j-1];
            dp[i][j] = a.dee < b.dee ? a : b;
        }
    }
}
int rmq(int l,int r) {
    int k = 0;
    while((1 << (k+1)) <= r-l+1) k++;
    D a = dp[l][k],b = dp[r-(1<<k)+1][k];
    return a.dee < b.dee ? a.id : b.id;
}
void dfs(int x,int dee,int fat){
    fst[x] = top;
    dft[top].dee = dee;
    dft[top++].id = x;
    de[x]=dee;
    fa[x][0]=fat;
    for(int i=1;(1<<i)<=dee;i++)fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int i=0;i<a[x].size();i++)if(a[x][i]!=fat){
        dfs(a[x][i],dee+1,x);
        dft[top].dee = dee;
        dft[top++].id = x;
    }
}
int lca(int x,int y){
    if(de[x]<de[y]){
        int t=de[y]-de[x];
        int i=0;
        while(t){
            if(t&(1<<i)){
                y=fa[y][i];
                t-=(1<<i);
            }
            i++;
        }
    }
    else if(de[x]>de[y]){
        int t=de[x]-de[y];
        int i=0;
        while(t){
            if(t&(1<<i)){
                x=fa[x][i];
                t-=(1<<i);
            }
            i++;
        }
    }
    if(x==y)return x;
    int i=0;
    while((1<<i)<de[x])i++;
    for(;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];
}
void dfs2(int x,int fat){
    for(int i=0;i<a[x].size();i++)if(a[x][i]!=fat){
        dfs2(a[x][i],x);
        su[x]+=su[a[x][i]];
    }
}
int main(int argc, const char * argv[]) {
    int i,j,m,n,N,I=0;
    cin>>N;
    while (N--) {
        memset(fst,0,sizeof fst);
        memset(dft,0,sizeof fst);
        top = 1;
        I++;
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)a[i].clear();
        memset(de,0,sizeof(de));
        memset(fa,0,sizeof(fa));
        memset(su,0,sizeof(su));
        for(i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        dfs(1,1,0);
        st(n);
        for(i=n;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            su[x]++;
            su[y]++;
            su[rmq(x,y)]-=2;
        }
        dfs2(1,0);
        int ans=INF;
        for(i=2;i<=n;i++)if(ans>su[i]+1)ans=su[i]+1;
        printf("Case #%d: %d\n",I,ans);
    }
    return 0;
}