#define LCA
class Gragh{
    struct edge {
        int y, v, flag;//是否为割边
    };
    vector<edge> a[maxn];
    bool visit[maxn],flag[maxn];//是否被访问过、是否为割点
    int dfn[maxn],low[maxn];//tarjan
    int root;

#ifdef LCA
    int fa[maxn][20];
    int de[maxn];
#endif
    
    void init(int n,int root = 1){//初始化，传入点数
        memset(fa, 0, sizeof(fa));
        for(int i=1;i<=n;i++){
            a[i].clear();
            visit[i] = dfn[i] = low[i] = flag[i] = de[i] = 0;
        }
        this->root = root;
        if(a[root].size() > 1)flag[root] = 1;
    }
    
    void addedge(int x,int y,int v = 1){//加有向边
        edge t;
        t.v = v;
        t.y = y;
        t.flag = false;
        a[x].push_back(t);
    }
    
    void addedge_u(int x,int y,int v = 1){//加无向边
        addedge(x, y, v);
        addedge(y, x, v);
    }
    
    void tarjan(int x,int father,int time = 1,int deep = 1){
        visit[x] = 1;
        dfn[x] = time;
        low[x] = time;
#ifdef LCA
        de[x] = deep;
        fa[x][0] = father;
        for(int i = 0; fa[x][i]; i ++){
            fa[x][i + 1] = fa[fa[x][i]][i];
        }
#endif
        for(int i = 0; i < a[x].size(); i ++)if(a[x][i].y != father){
            int y = a[x][i].y;
            if(visit[y]){
                low[x] = min(low[x], dfn[y]);
            }
            else {
                tarjan(y, x, time + 1, deep + 1);
                if(low[x] < low[y]){
                    a[x][i].flag = 1;
                    if(x != root)flag[x] = 1;
                }
                else low[x] = low[y];
            }
        }
    }
    
#ifdef LCA
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
#endif
};