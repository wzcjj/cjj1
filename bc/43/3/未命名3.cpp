#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
vector<int> a[300005];
int fa[300005][20];
struct node{
    int l,r,lca;
}lca[1200005];
int de[300005];
void dfs(int x,int father,int deep){
    fa[x][0]=father;
    de[x]=deep;
    for(int i=0;fa[x][i]!=-1;i++)if(fa[fa[x][i]][i]!=0)fa[x][i+1]=fa[fa[x][i]][i];
    else fa[x][i+1]=-1;
    for(int i=0;i<a[x].size();i++)if(a[x][i]!=father){
    //cout<<father<<' '<<x<<' '<<a[x][i]<<fa[x][0]<<"-----------------"<<endl;
        dfs(a[x][i],x,deep+1);
    }
}
int lcaa(int x,int y){
    if(de[x]<de[y]){
        int t=de[y]-de[x];
        for(int i=0;t;i++){
            if(t&(1<<i)){
                y=fa[y][i];
                t-=(1<<i);
            }
        }
    }else
    if(de[x]>de[y]){
        int t=de[x]-de[y];
        for(int i=0;t;i++){
            if(t&(1<<i)){
                x=fa[x][i];
                t-=(1<<i);
            }
        }
    }
    //cout<<"----"<<x<<' '<<y<<endl;
    if(x==y)return x;
    int r=de[x]-1;
    int i;
    for(i=0;(1<<i)<=r;i++);
    for(i=i-1;i>=0;i--){
        if((1<<i)<=r&&fa[x][i]!=fa[y][i]){
            x=fa[x][i];
            y=fa[y][i];
            r-=(1<<i);
            //cout<<"-------"<<x<<' '<<y<<endl;
        }
    }
    return fa[x][0];
}
void build(int l,int r,int p){
    lca[p].l=l;
    lca[p].r=r;
    int mid=(l+r)>>1;
    if(l<r){
        build(l,mid,2*p);
        build(mid+1,r,2*p+1);
        lca[p].lca=lcaa(lca[2*p].lca,lca[2*p+1].lca);
    }
    else{
        lca[p].lca=l;
    }
}
int query(int l,int r,int p){
    if(l==lca[p].l&&r==lca[p].r)return lca[p].lca;
    int mid=(lca[p].l+lca[p].r)>>1;
    if(l>mid)return query(l,r,2*p+1);
    else if(r<=mid)return query(l,r,2*p);
    else return lcaa(query(l,mid,2*p),query(mid+1,r,2*p+1));
} 
int main(){
    int i,j,m,n;
    while(cin>>n){
        memset(fa,0,sizeof(fa));
        for(i=1;i<=n;i++)a[i].clear();
        for(i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        dfs(1,-1,1);
        build(1,n,1);
        //for(i=1;i<=3*n;i++)cout<<lca[i].l<<' '<<lca[i].r<<' '<<lca[i].lca<<' '<<i<<endl;
        //for(i=1;i<=n;i++)cout<<"--"<<de[i]<<endl;
        //cout<<lcaa(6,7)<<"--"<<endl;
        cin>>m;
        for(i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            int ans=query(x,y,1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
        
