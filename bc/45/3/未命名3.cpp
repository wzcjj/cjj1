#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> a[100005];
int de[100005],f[100005],v[100005];
void dfs(int x,int fa,int deep){
    f[x]=fa;
    de[x]=deep;
    for(int i=0;i<a[x].size();i++)if(a[x][i]!=fa){
        dfs(a[x][i],x,deep+1);
    }
}
int query(int x,int y){
    int ans=0;
    bool zero=false;
    while(de[x]>de[y]){
        if(v[x]==0)zero=!zero;
        ans=ans^v[x];
        x=f[x];
    }
    while(de[x]<de[y]){
        if(v[y]==0)zero=!zero;
        ans=ans^v[y];
        y=f[y];
    }
    while(x!=y){
        if(v[x]==0)zero=!zero;
        ans=ans^v[x];
        x=f[x];
        if(v[y]==0)zero=!zero;
        ans=ans^v[y];
        y=f[y];
    }
    if(v[x]==0)zero=!zero;
    ans=ans^v[x];
    if(ans==0&&(zero==false))return -1;
    else return ans;
}
int main(){
    int i,j,m,n,N;
    cin>>N;
    while(N--){
        cin>>n>>m;
        for(i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        dfs(1,-1,1);
        for(i=1;i<=n;i++)scanf("%d",&v[i]);
        for(i=1;i<=m;i++){
            int z,x,y;
            scanf("%d%d%d",&z,&x,&y);
            if(z==0){
                v[x]=y;
            }else{
                int ans=query(x,y);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
