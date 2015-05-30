#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int color[105];
bool edge[105][105];
bool cango[105][105];
int main(){
    int i,j,m,n,N,x,y;
    cin>>N;
    for(int I=1;I<=N;I++){
        cin>>n>>m;
        memset(color,0,sizoef(color));
        memset(edge,false,sizeof(edge));
        memset(cango,false,sizeof(cango));
        for(i=1;i<=m;i++){
            cin>>x>>y;
            edge[x][y]=edge[y][x]=true;
        }
        int colors=0;
        for(i=1;i<=n;i++)if(color[i]==0)dfs(i,++colors);
        
