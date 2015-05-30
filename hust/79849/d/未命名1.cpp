#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define MAX 100050 
struct EDGE {
    int u,v;
}e[MAX]; 
int ans[MAX],fa[MAX];
int getfa(int x){
    return (fa[x] == x) ? fa[x] : fa[x] = getfa(fa[x]);
}
int main(){
    int m,n;
    while(cin >> n >> m) {
        for(int i = 1;i <= m;i++) {
            int x,y;scanf("%d%d",&x,&y);
            e[i].u = x;e[i].v = y;
        }
        for(int i = 0;i < n;i++) fa[i] = i;
        memset(ans,0,sizeof ans);
        ans[m] = n;
        for(int i = m;i > 0;i--) {
            int fu = getfa(e[i].u);
            int fv = getfa(e[i].v);
            if(fu == fv) {
                ans[i-1] = ans[i];
            }
            else {
                fa[fu] = fv;
                ans[i-1] = ans[i]-1;
            }
        }
        for(int i = 1;i <= m;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
