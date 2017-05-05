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
class SegmentTree
{
public:
    struct node{
        int l, r;
        long long now, sum;
        bool flag;
        int s;
    };
    
    SegmentTree(int size){
        build(1, size);
    }
    
    SegmentTree(){
    }
    
    void sqrtt(int l,int r,int p = 1){
        down(p);
        if(l == tree[p].l && r == tree[p].r && tree[p].flag){
            
            down(p);
            return;
        }
    }
    
    void add(int l,int r,int v,int p = 1){
        down(p);
        if(l == tree[p].l && r == tree[p].r){
            tree[p].now += v;
            return;
        }
        int mid = (tree[p].l + tree[p].r) >> 1;
        if(r <= mid){
            add(l, r, v, 2 * p);
            down(2 * p + 1);
        }
        else if(l > mid){
            add(l, r, v, 2 * p + 1);
            down(2 * p);
        }
        else{
            add(l, mid, v, 2 * p);
            add(mid + 1, r, v, 2 * p + 1);
        }
        up(p);
    }
    
    long long query(int l,int r,int p = 1){
        down(p);
        if(l == tree[p].l && r == tree[p].r)return tree[p].sum;
        int mid = (tree[p].l + tree[p].r) >> 1;
        if(r <= mid)return query(l, r, 2 * p);
        else if(l > mid)return query(l, r, 2 * p + 1);
        else return query(l, mid, 2 * p) + query(mid + 1, r, 2 * p + 1);
    }
    
    void build(int l,int r,int p = 1){
        tree[p].l = l;
        tree[p].r = r;
        tree[p].now = 0;
        tree[p].flag = 0;
        tree[p].s = 0;
        if(l == r) {
            tree[p].sum = a[l];
            tree[p].flag = 1;
        }
        if(l < r){
            int mid = (l + r) >> 1;
            build(l, mid, 2 * p);
            build(mid + 1, r, 2 * p + 1);
            up(p);
        }
    }
private:
    node tree[4 * maxn];
    void downs(int p){
        if(tree[p].s){
            down(2 * p);
            down(2 * p + 1);
            tree[2 * p].s += tree[p].s;
            tree[2 * p + 1].s += tree[p].s;
            while(tree[p].s){
                tree[p].sum = sqrt(tree[p].sum / (tree[p].r - tree[p].l + 1)) * (tree[p].r - tree[p].l + 1);
                tree[p].s--;
            }
        }
    }
    void downadd(int p){
        if(tree[p].now == 0) return;
        down(2 * p);
        down(2 * p + 1);
        if(tree[p].l < tree[p].r){
            tree[2 * p].now += tree[p].now;
            tree[2 * p + 1].now += tree[p].now;
        }
        tree[p].sum += (tree[p].r - tree[p].l + 1) * tree[p].now;
        tree[p].now = 0;
    }
    void down(int p){
        if(tree[p].now == 0) return;
        if(tree[p].l < tree[p].r){
            tree[2 * p].now += tree[p].now;
            tree[2 * p + 1].now += tree[p].now;
        }
        tree[p].sum += (tree[p].r - tree[p].l + 1) * tree[p].now;
        tree[p].now = 0;
    }
    void up(int p){
        tree[p].sum = tree[2 * p].sum + tree[2 * p + 1].sum;
        tree[p].flag = tree[2 * p].flag && tree[2 * p + 1].flag && tree[2 * p].sum / (tree[2 * p].r - tree[2 * p].l + 1) == tree[2 * p + 1].sum / (tree[2 * p + 1].r - tree[2 * p + 1].l + 1);
    }
};
SegmentTree seg;
int main(int argc, const char * argv[]) {
    int i,j,m,n,N;
    cin>>N;
    while (N--) {
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
    }
    return 0;
}
