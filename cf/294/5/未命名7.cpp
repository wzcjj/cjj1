#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> a[100005];
int sum[100005],de[100005];
int fa[100005][20];
void dfs(int x,int f,int d){
    sum[x]=1;
    fa[x][0]=f;
    de[x]=d;
    for(int i=0;i<a[x].size();i++)if(a[x][i]!=f){
        dfs(a[x][i],x,d+1);
        sum[x]+=sum[a[x][i]];
    }
}
int father(int x,int many){
    int t=x;
    int j=0;
    for(int i=1;i<=many;i*=2){
        if(i&many)t=fa[t][j];
        j++;
    }
    return t;
}
int theirfather(int x,int y){
    if(de[x]>de[y])x=father(x,de[x]-de[y]);
    else y=father(y,de[y]-de[x]);
    int l=0,r=100005;
    while(r>l+1){
        int mid=(l+r)/2;
        if(father(x,mid)==father(y,mid))r=mid;
        else l=mid;
    }
    return father(x,r);
}
int main(){
    int i,j,m,n,x,y,t;
    cin>>n;
    for(i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(i=0;i<=19;i++)fa[0][i]=0;
    dfs(1,0,1);
    for(i=1;i<=19;i++)for(j=1;j<=n;j++)fa[j][i]=fa[fa[j][i-1]][i-1];
    cin>>m;
    for(i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        if(x==y)cout<<n<<endl;
        else if(de[x]==de[y])cout<<sum[1]-sum[father(x,de[x]-de[theirfather(x,y)]-1)]-sum[father(y,de[x]-de[theirfather(x,y)]-1)]<<endl;
        else if((de[x]+de[y])%2==1)cout<<0<<endl;
        else if(de[x]>de[y]){
            if(father(x,de[x]-de[y])==y)cout<<sum[father(x,(de[x]-de[y])/2)]-sum[father(x,(de[x]-de[y])/2-1)]<<endl;
            else{
                t=(de[x]+de[y]-de[theirfather(x,y)]*2)/2;
                cout<<sum[father(x,t)]-sum[father(x,t-1)]<<endl;
            }
        }
        else if(father(y,de[y]-de[x])==x)cout<<sum[father(y,(de[y]-de[x])/2)]-sum[father(y,(de[y]-de[x])/2-1)]<<endl;
        else{
            t=(de[x]+de[y]-de[theirfather(x,y)]*2)/2;
            cout<<sum[father(y,t)]-sum[father(y,t-1)]<<endl;
        }
    }
    return 0;
}
        
