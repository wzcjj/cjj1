class Gragh{
public:
    vector<int> a[maxn];
    bool visit[maxn];
    int color[maxn];
    int flag[maxn];
    int fa[maxn];
    int father[maxn];
    
    int getfa(int x){
        if(fa[x] != x)fa[x] = getfa(fa[x]);
        return fa[x];
    }
    
    void init(int n){//初始化，传入点数
        for(int i=1;i<=n;i++){
            a[i].clear();
            visit[i] = color[i] = flag[i] = 0;
            fa[i] = i;
        }
    }
    
    void addedge(int x,int y){//加有向边
        a[x].push_back(y);
    }
    
    void tarjan(int x,int fat){     //强连通分量
        if(visit[x])return;
        visit[x] = flag[x] = true;
        father[x] = fat;
        for(int i = 0; i < a[x].size(); i ++){
            int y = a[x][i];
            if(visit[y]){
                if(flag[y]){
                    int j = x;
                    while(j != getfa(y)){
                        fa[getfa(j)] = getfa(y);
                        j = getfa(father[j]);
                    }
                }
            }
            else {
                tarjan(y, x);
            }
        }
        flag[x] = false;
    }
    
    int num(int n){      //强连通分量数
        int ans = 0;
        for(int i = 1; i <= n; i ++){
            flag[i] = 0;
        }
        for(int i = 1; i <= n; i ++){
            if(!flag[getfa(i)]){
                ans ++;
                flag[getfa(i)] = 1;
            }
        }
        return ans;
    }
};
Gragh G;