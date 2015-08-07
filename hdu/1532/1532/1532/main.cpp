#include<cstdio>        //EK()算法。时间复杂度（VE^2）
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 205;
const int INF = (1<<30)-1;
int g[maxn][maxn];
int flow[maxn],pre[maxn];
bool vis[maxn];
int n,m;
int bfs(){
    memset(pre,-1,sizeof(pre));
    memset(vis,false,sizeof(vis));
    queue<int > q;
    vis[1] = true;
    for(int i=1;i<=n;i++)   flow[i]=INF;
    q.push(1);
    while(!q.empty()){
        int now = q.front();  q.pop();
        if(now==n)  break;
        for(int i=1;i<=n;i++){                //寻找增广路最小流量
            if(!vis[i]&&g[now][i]>0){
                vis[i] = true;
                flow[i] = min(flow[now],g[now][i]);
                pre[i] = now;
                q.push(i);
            }
        }
    }
    if(!vis[n]|| n==1)                         //找不到完整的增广路or源点汇点重合
        return -1;
    else
        return flow[n];
}
int EK(){
    int temp,d,res,maxflow;
    maxflow = 0;
    while((d=bfs())!=-1){
        maxflow += d;
        temp=n;
        while(temp!=1){
            res = pre[temp];
            g[res][temp]-=d;               //正向边
            g[temp][res]+=d;               //反向边
            temp = res;
        }
    }
    return maxflow;
}
int main(){
    int T,ca=1,m;
    int start,end,capacity;
    while(scanf("%d%d",&m,&n)!=EOF){
        memset(g,0,sizeof(g));
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&start,&end,&capacity);
            g[start][end]+=capacity;
        }
        printf("%d\n",EK());
    }
    return 0;
}
