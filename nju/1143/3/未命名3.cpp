#include<cstdio>
#include<queue>
using namespace std;
queue<int> a;
int b[1000][1000],time1,color[1000],d[1000],pi[1000],f[1000];
void bfs(int n,int s){
    int i,j;
    for(i=0;i<n;i++){
        color[i]=0;
        d[i]=9999;
        pi[i]=-1;
    }
    color[s]=1;
    d[s]=0;
    while(!a.empty())a.pop();
    a.push(s);
    while(!a.empty()){
        i=a.front();
        a.pop();
        for(j=0;j<n;j++)if(b[i][j]&&color[j]==0){
            color[j]=1;
            d[j]=d[i]+1;
            pi[j]=i;
            a.push(j);
        }
        color[i]=2;
    }
}
void dfs_visit(int n,int i){
    time1++;
    d[i]=time1;
    color[i]=1;
    for(int j=0;j<n;j++)if(b[i][j]&&color[j]==0){
        pi[j]=i;
        dfs_visit(n,j);
    }
    color[i]=2;
    time1++;
    f[i]=time1;
}
void dfs(int n){
    for(int i=0;i<n;i++){
        color[i]=0;
        pi[i]=-1;
    }
    time1=0;
    for(int i=0;i<n;i++)if(color[i]==0)dfs_visit(n,i);
}
int main(){
    int i,j,m,n;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&b[i][j]);
        bfs(n,m);
        for(i=0;i<n;i++)printf("%d %d %d\n",i,d[i],pi[i]);
        dfs(n);
        for(i=0;i<n;i++)printf("%d %d %d\n",i,d[i],f[i]);
    }
    return 0;
}
