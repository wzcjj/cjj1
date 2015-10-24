#define RETURN_TYPE int
class SegmentTree
{
public:
    struct node{
        int l, r;
        RETURN_TYPE nowadd, nowmodify, maxx, minn, sum;
    };
    
    void modify(int l,int r,RETURN_TYPE v,int p = 1){
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
    
    void add(int l,int r,RETURN_TYPE v,int p = 1){
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
    
    RETURN_TYPE querymax(int l,int r,int p = 1){
        down(p);
        if(l == tree[p].l && r == tree[p].r)return tree[p].maxx;
        int mid = (tree[p].l + tree[p].r) >> 1;
        if(r <= mid)return querymax(l, r, 2 * p);
        else if(l > mid)return querymax(l, r, 2 * p + 1);
        else return max(querymax(l, mid, 2 * p), querymax(mid + 1, r, 2 * p + 1));
    }
    
    RETURN_TYPE querymin(int l,int r,int p = 1){
        down(p);
        if(l == tree[p].l && r == tree[p].r)return tree[p].minn;
        int mid = (tree[p].l + tree[p].r) >> 1;
        if(r <= mid)return querymin(l, r, 2 * p);
        else if(l > mid)return querymin(l, r, 2 * p + 1);
        else return min(querymin(l, mid, 2 * p), querymin(mid + 1, r, 2 * p + 1));
    }
    
    RETURN_TYPE querysum(int l,int r,int p = 1){
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
            tree[p].maxx = tree[p].minn = tree[p].sum = a[l];
        }
        if(l < r){
            int mid = (l + r) >> 1;
            build(l, mid, 2 * p);
            build(mid + 1, r, 2 * p + 1);
            tree[p].maxx = max(tree[2 * p].maxx, tree[2 * p + 1].maxx);
            tree[p].minn = min(tree[2 * p].minn, tree[2 * p + 1].minn);
            tree[p].sum = tree[2 * p].sum + tree[2 * p + 1].sum;
        }
    }
private:
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
SegmentTree seg;