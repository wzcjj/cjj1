class SegmentTree
{
public:
    struct node{
        int l, r;
        int nowadd, nowmodify, maxx, minn, sum;
    };
    
    void modify(int l,int r,int v,int p = 1){
        downadd(p);
        if(l == tree[p].l && r == tree[p].r){
            tree[p].nowmodify = v;
            downmodify(p);
            return;
        }
        downmodify(p);
        int mid = (tree[p].l + tree[p].r) >> 1;
        if(r <= mid){
            modify(l, r, v, 2 * p);
            downmodify(2 * p + 1);
        }
        else if(l > mid){
            modify(l, r, v, 2 * p + 1);
            downmodify(2 * p);
        }
        else{
            modify(l, mid, v, 2 * p);
            modify(mid + 1, r, v, 2 * p + 1);
        }
        up(p);
    }
    
    void add(int l,int r,int v,int p = 1){
        downmodify(p);
        if(l == tree[p].l && r == tree[p].r){
            tree[p].nowadd += v;
            downadd(p);
            return;
        }
        downadd(p);
        int mid = (tree[p].l + tree[p].r) >> 1;
        if(r <= mid){
            add(l, r, v, 2 * p);
            downadd(2 * p + 1);
        }
        else if(l > mid){
            add(l, r, v, 2 * p + 1);
            downadd(2 * p);
        }
        else{
            add(l, mid, v, 2 * p);
            add(mid + 1, r, v, 2 * p + 1);
        }
        up(p);
    }
    
    int querymax(int l,int r,int p = 1){
        down(p);
        if(l == tree[p].l && r == tree[p].r)return tree[p].maxx;
        int mid = (tree[p].l + tree[p].r) >> 1;
        if(r <= mid)return querymax(l, r, 2 * p);
        else if(l > mid)return querymax(l, r, 2 * p + 1);
        else return max(querymax(l, mid, 2 * p), querymax(mid + 1, r, 2 * p + 1));
    }
    
    int querymin(int l,int r,int p = 1){
        down(p);
        if(l == tree[p].l && r == tree[p].r)return tree[p].minn;
        int mid = (tree[p].l + tree[p].r) >> 1;
        if(r <= mid)return querymin(l, r, 2 * p);
        else if(l > mid)return querymin(l, r, 2 * p + 1);
        else return min(querymin(l, mid, 2 * p), querymin(mid + 1, r, 2 * p + 1));
    }
    
    int querysum(int l,int r,int p = 1){
        down(p);
        if(l == tree[p].l && r == tree[p].r)return tree[p].sum;
        int mid = (tree[p].l + tree[p].r) >> 1;
        if(r <= mid)return querysum(l, r, 2 * p);
        else if(l > mid)return querysum(l, r, 2 * p + 1);
        else return (querysum(l, mid, 2 * p) + querysum(mid + 1, r, 2 * p + 1));
    }
    
    void build(int l,int r,int p = 1){
        tree[p].l = l;
        tree[p].r = r;
        tree[p].nowadd = 0;
        tree[p].nowmodify = -INF;
        if(l == r) {
            tree[p].maxx = tree[p].minn = tree[p].sum = 0;
        }
        if(l < r){
            int mid = (l + r) >> 1;
            build(l, mid, 2 * p);
            build(mid + 1, r, 2 * p + 1);
            up(p);
        }
    }
    node tree[4 * maxn];
    void downadd(int p){
        if(tree[p].nowadd == 0)return;
        if(tree[p].l < tree[p].r){
            downmodify(2 * p + 1);
            downmodify(2 * p);
            tree[2 * p].nowadd += tree[p].nowadd;
            tree[2 * p + 1].nowadd += tree[p].nowadd;
        }
        tree[p].sum += (tree[p].r - tree[p].l + 1) * tree[p].nowadd;
        tree[p].maxx += tree[p].nowadd;
        tree[p].minn += tree[p].nowadd;
        tree[p].nowadd = 0;
    }
    
    void downmodify(int p){
        if(tree[p].nowmodify == -INF)return;
        if(tree[p].l < tree[p].r){
            tree[2 * p].nowadd = 0;
            tree[2 * p + 1].nowadd = 0;
            tree[2 * p].nowmodify = tree[p].nowmodify;
            tree[2 * p + 1].nowmodify = tree[p].nowmodify;
        }
        tree[p].maxx = tree[p].nowmodify;
        tree[p].minn = tree[p].nowmodify;
        tree[p].sum = (tree[p].r - tree[p].l + 1) * tree[p].nowmodify;
        tree[p].nowmodify = -INF;
    }
    
    void down(int p){
        downadd(p);
        downmodify(p);
    }
    
    void up(int p){
        tree[p].maxx = max(tree[2 * p].maxx, tree[2 * p + 1].maxx);
        tree[p].minn = min(tree[2 * p].minn, tree[2 * p + 1].minn);
        tree[p].sum = tree[2 * p].sum + tree[2 * p + 1].sum;
    }
};
class SegmentTree2{
public:
    struct node {
        int l,r;
        SegmentTree seg;
    };
    
    void build(int l, int r, int n, int p = 1){
        tree[p].l = l;
        tree[p].r = r;
        tree[p].seg.build(1, n);
        if(l < r){
            int mid = (l + r) >> 1;
            build(l, mid, n, 2 * p);
            build(mid + 1, r, n, 2 * p + 1);
        }
    }
    
    void modify(int xl,int xr,int yl,int yr,int v,int p = 1){
        if(xl == tree[p].l && xr == tree[p].r){
            tree[p].seg.modify(yl, yr, v);
            if(xl < xr)downall(yl, yr, p);
            return;
        }
        downall(yl, yr, p);
        int mid = (tree[p].l + tree[p].r) >> 1;
        if(xr <= mid){
            modify(xl, xr, yl, yr, v, 2 * p);
            downall(yl, yr, 2 * p + 1);
        }
        else if(xl > mid){
            modify(xl, xr, yl, yr, v, 2 * p + 1);
            downall(yl, yr, 2 * p);
        }
        else{
            modify(xl, mid, yl, yr, v, 2 * p);
            modify(mid + 1, xr, yl, yr, v, 2 * p + 1);
        }
        upall(yl, yr, p);
        downall(yl, yr, p);
    }
    
    void add(int xl,int xr,int yl,int yr,int v,int p = 1){
        if(xl == tree[p].l && xr == tree[p].r){
            tree[p].seg.add(yl, yr, v);
            if(xl < xr)downall(yl, yr, p);
            return;
        }
        downall(yl, yr, p);
        int mid = (tree[p].l + tree[p].r) >> 1;
        if(xr <= mid){
            add(xl, xr, yl, yr, v, 2 * p);
            downall(yl, yr, 2 * p + 1);
        }
        else if(xl > mid){
            add(xl, xr, yl, yr, v, 2 * p + 1);
            downall(yl, yr, 2 * p);
        }
        else{
            add(xl, mid, yl, yr, v, 2 * p);
            add(mid + 1, xr, yl, yr, v, 2 * p + 1);
        }
        upall(yl, yr, p);
        downall(yl, yr, p);
    }
    
    int querymax(int xl,int xr,int yl,int yr,int p = 1){
        downall(yl, yr, p);
        if(xl == tree[p].l && xr == tree[p].r)return tree[p].seg.querymax(yl, yr);
        int mid = (tree[p].l + tree[p].r) >> 1;
        if(xr <= mid)return querymax(xl, xr, yl, yr, 2 * p);
        else if(xl > mid)return querymax(xl, xr, yl, yr, 2 * p + 1);
        else return max(querymax(xl, mid, yl, yr, 2 * p), querymax(mid + 1, xr, yl, yr, 2 * p + 1));
    }
    
    int querymin(int xl,int xr,int yl,int yr,int p = 1){
        downall(yl, yr, p);
        if(xl == tree[p].l && xr == tree[p].r)return tree[p].seg.querymin(yl, yr);
        int mid = (tree[p].l + tree[p].r) >> 1;
        if(xr <= mid)return querymin(xl, xr, yl, yr, 2 * p);
        else if(xl > mid)return querymin(xl, xr, yl, yr, 2 * p + 1);
        else return min(querymin(xl, mid, yl, yr, 2 * p), querymin(mid + 1, xr, yl, yr, 2 * p + 1));
    }
    
    int querysum(int xl,int xr,int yl,int yr,int p = 1){
        downall(yl, yr, p);
        if(xl == tree[p].l && xr == tree[p].r)return tree[p].seg.querysum(yl, yr);
        int mid = (tree[p].l + tree[p].r) >> 1;
        if(xr <= mid)return querysum(xl, xr, yl, yr, 2 * p);
        else if(xl > mid)return querysum(xl, xr, yl, yr, 2 * p + 1);
        else return (querysum(xl, mid, yl, yr, 2 * p) + querysum(mid + 1, xr, yl, yr, 2 * p + 1));
    }
private:
    node tree[4 * maxn];
    
    void downx(int p,int yp){
        tree[p].seg.down(yp);
    }
    
    void upy(int p,int yp){
        tree[p].seg.tree[yp].sum = tree[2 * p].seg.tree[yp].sum + tree[2 * p + 1].seg.tree[yp].sum;
        tree[p].seg.tree[yp].maxx = max(tree[2 * p].seg.tree[yp].maxx, tree[2 * p + 1].seg.tree[yp].maxx);
        tree[p].seg.tree[yp].minn = min(tree[2 * p].seg.tree[yp].minn, tree[2 * p + 1].seg.tree[yp].minn);
    }
    
    void upx(int p,int yp){
        tree[p].seg.up(yp);
    }
    
    void downall(int yl,int yr,int p){
        tree[p].seg.add(yl, yr, 0);
    }
    
    void upall(int yl,int yr,int p,int yp = 1){
        if(yl < yr)downx(p, yp);
        if(yl == tree[p].seg.tree[yp].l && yr == tree[p].seg.tree[yp].r){
            upy(p, yp);
            return;
        }
        int mid = (tree[p].seg.tree[yp].l + tree[p].seg.tree[yp].r) >> 1;
        if(mid < yl){
            upall(yl, yr, p, 2 * yp + 1);
            downx(p, 2 * yp);
        }
        else if(mid >= yr){
            upall(yl, yr, p, 2 * yp);
            downx(p, 2 * yp + 1);
        }
        else {
            upall(yl, mid, p, 2 * yp);
            upall(mid + 1, yr, p, 2 * yp + 1);
        }
        upx(p, yp);
    }
};
SegmentTree2 seg;