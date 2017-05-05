#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

#define is(X) cout << #X << " = " << X << endl

using namespace std;

struct T{
    int l,r,v;
}node[100005 << 2];
inline int fa(int x) {return x >> 1;}
inline int ln(int x) {return x << 1;}
inline int rn(int x) {return 1+(x << 1);}
void init(int x,int l,int r) {
    node[x].l = l;node[x].r = r;node[x].v = 0;
    if(l == r) return;
    int m = (l+r) >> 1;
    init(ln(x),l,m);
    init(rn(x),m+1,r);
    return;
}
void ins(int x,int l,int r,int v) {
    //ais(l);is(r);
    node[x].v++;
    if(l == r && r == v) {
        return;
    }
    int m = (l+r) >> 1;
    if(m < v) ins(rn(x),m+1,r,v);
    else ins(ln(x),l,m,v);
    return;
}
int query(int x,int l,int r,int ll,int rr) {
    if(rr < ll) return 0;
    //is(l);is(r);is(ll);is(rr);
    if(l == ll && r == rr) return node[x].v;
    else {
        int m = (l+r)>>1;
        if(m >= rr) return query(ln(x),l,m,ll,rr);
        else if(m < ll) return query(rn(x),m+1,r,ll,rr);
        else return query(ln(x),l,m,ll,m)+query(rn(x),m+1,r,m+1,rr);
    }
}
struct K{
    int id,v;
    friend bool operator <(K k1,K k2) {return k1.v < k2.v;}
}num[100005];
int ans[100005];
int main()
{
    int t;cin >> t;
    int cc = 1;
    while(t--) {
        int n;cin >> n;
        memset(node,0,sizeof node);
        init(1,1,n);
        for(int i = 1;i <= n;i++) {
            int v;scanf("%d",&v);
            int id = i;
            ins(1,1,n,v);
            int cnt = v - query(1,1,n,1,v-1);
            ans[v] = id + cnt - 1 - min(v,id);
        }
        //stable_sort(num+1,num+n+1);
        printf("Case #%d:",cc++);
        //for(int i = 1;i <= n;i++) {
        //is(num[i].v);is(num[i].id);
        //    ans[num[i].v] = abs(num[i].id-i);
        //}
        for(int i = 1;i <= n;i++) {
            printf(" %d",ans[i]);
        }puts("");
    }
    return 0;
}