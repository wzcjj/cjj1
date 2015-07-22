#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<queue>
using namespace std;
struct node{
    int y,c;
};
int b[2005][2005],n;
int c[2005];
bool flag[2005];
vector<int>a[2005],e[2005];
vector<bool>d[2005];
queue<int>q;
int dfs(int x,int now){
    int ans=0;
    if(x==n)return now;
    flag[x]=true;
    for(int i=0;i<a[x].size();i++)if(d[x][i]&&!flag[a[x][i]]&&b[x][a[x][i]]){
        int t=dfs(a[x][i],min(now,b[x][a[x][i]]));
        b[a[x][i]][x]+=t;
        b[x][a[x][i]]-=t;
        now-=t;
        ans+=t;
        if(t==0)b[x][a[x][i]]=0;
        if(now==0)break;
    }
    flag[x]=false;
    return ans;
}
int main(){
    int i,j,m;
    while(cin>>n>>m){
        for(i=1;i<=n;i++)a[i].clear();
        for(i=1;i<=n;i++)d[i].clear();
        for(i=1;i<=n;i++)e[i].clear();
        memset(flag,false,sizeof(flag));
        memset(b,0,sizeof(0));
        for(i=1;i<=m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[x].push_back(y);
            a[y].push_back(x);
            d[x].push_back(false);
            d[y].push_back(false);
            e[x].push_back(z);
            e[y].push_back(z);
            b[x][y]+=1;
            b[y][x]+=1;
        }
        if(n==1){
            cout<<"0 "<<m<<endl;
            continue;
        }
        
        memset(flag,false,sizeof(flag));
        memset(c,0,sizeof(c));
        while(!q.empty())q.pop();
        q.push(1);
        flag[1]=true;
        while(!q.empty()){
            int x=q.front();
            for(j=0;j<a[x].size();j++)if(c[a[x][j]]==0||c[x]+e[x][j]<c[a[x][j]]){
                c[a[x][j]]=c[x]+e[x][j];
                d[x][j]=true;
                if(!flag[a[x][j]]){
                    q.push(a[x][j]);
                    flag[a[x][j]]=true;
                }
            }
            q.pop();
            flag[x]=false;
        }
        int ans=dfs(1,1000000);
        cout<<ans<<' ';
        memset(flag,false,sizeof(flag));
        memset(c,0,sizeof(c));
        while(!q.empty())q.pop();
        q.push(1);
        flag[1]=true;
        while(!q.empty()){
            int x=q.front();
            for(j=0;j<a[x].size();j++)if(c[a[x][j]]==0||c[x]+1<c[a[x][j]]){
                c[a[x][j]]=c[x]+1;
                if(!flag[a[x][j]]){
                    q.push(a[x][j]);
                    flag[a[x][j]]=true;
                }
            }
            q.pop();
            flag[x]=false;
        }
        cout<<m-c[n]<<endl;
    }
    return 0;
}
